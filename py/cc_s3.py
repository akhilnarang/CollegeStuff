#!/usr/bin/env python3

from boto3.session import Session
from decouple import config
from tabulate import tabulate

import os
import sys


def get_client():
    """
    Method to return a boto3 Session Client object for S3 service
    """
    return Session().client(
        's3',
        aws_access_key_id=config('S3_ACCESS_KEY'),
        aws_secret_access_key=config('S3_SECRET_ACCESS_KEY'),
    )


def list_buckets():
    """
    Method to print a list of S3 buckets we have access to
    """
    response = get_client().list_buckets()
    if buckets := response.get('Buckets'):
        print(f'Found {len(buckets)} buckets!')
        data = []
        for bucket in buckets:
            data.append(bucket.values())
        print(tabulate(data, headers=bucket.keys()))


def create_bucket():
    """
    Method to create an S3 bucket
    """
    bucket_name = input('Enter the desired name for your S3 bucket: ')
    try:
        get_client().create_bucket(Bucket=bucket_name)
        print(f'{bucket_name} has been succesfully created!')
    except Exception as e:
        print(e)
        sys.exit(1)


def delete_bucket():
    """
    Method to delete an S3 bucket
    """
    bucket_name = input('Enter the name of the S3 bucket you wish to delete: ')
    try:
        get_client().delete_bucket(
            Bucket=bucket_name,
        )
        print(f'{bucket_name} has been deleted!')
    except Exception as e:
        print(e)
        sys.exit(1)


def list_files(bucket_name: str = None):
    """
    Method to list the files in an S3 bucket
    """
    if bucket_name is None:
        bucket_name = input('Enter the name of the S3 bucket you want a listing for: ')
    try:
        response = get_client().list_objects_v2(Bucket=bucket_name)
        if files := response.get('Contents'):
            data = []
            for file in files:
                data.append(file.values())
            print(tabulate(data, headers=file.keys()))
    except Exception as e:
        print(e)
        sys.exit(1)


def upload_file():
    """
    Method to upload a file to an S3 bucket
    """
    bucket_name = input('Enter the name of the S3 bucket you to upload a file to: ')
    file_path = input(
        f'Enter the path to the file you wish to upload to {bucket_name}: '
    )
    if not os.path.isfile(file_path):
        print(f'{file_path} does not exist!')
        sys.exit(1)
    file_name = os.path.basename(file_path)
    try:
        get_client().upload_file(
            Bucket=bucket_name,
            Filename=file_path,
            Key=file_name,
            ExtraArgs={'ACL': 'public-read'},
        )
        print(
            f'{file_name} can be downloaded from https://{bucket_name}.s3.amazonaws.com/{file_name}'
        )
    except Exception as e:
        print(e)
        sys.exit(1)


def delete_file():
    """
    Method to delete a file from an S3 bucket
    """
    bucket_name = input(
        'Enter the name of the S3 bucket you wish to delete a file from: '
    )
    list_files(bucket_name)
    key = input(f'Enter the key (filename) you wish to delete from {bucket_name}: ')
    try:
        get_client().delete_object(
            Bucket=bucket_name,
            Key=key,
        )
        print(f'{key} has been deleted from {bucket_name}')
    except Exception as e:
        print(e)
        sys.exit(1)


def download_file():
    """
    Method to download a file from an S3 bucket
    """
    bucket_name = input(
        'Enter the name of the S3 bucket you wish to download a file from: '
    )
    list_files(bucket_name)
    key = input(f'Enter the key (filename) you wish to download from {bucket_name}: ')
    file_path = (
        input(f'Enter the path you wish to download {key} to (default {key}): ') or key
    )
    try:
        get_client().download_file(Bucket=bucket_name, Key=key, Filename=file_path)
        print(f'Downloaded {key} from {bucket_name} to {file_path}')
    except Exception as e:
        print(e)
        sys.exit(1)


if __name__ == '__main__':

    # Prompt the user for an input
    prompt = """1 to list buckets
2 to create a new bucket
3 to delete an existing bucket
4 to list files in a bucket
5 to upload a file to a bucket
6 to delete a file from a bucket
7 to download a file from a bucket
Anything else to exit
choice: """

    try:
        choice = int(input(prompt))
        if choice == 1:
            list_buckets()
        elif choice == 2:
            create_bucket()
        elif choice == 3:
            delete_bucket()
        elif choice == 4:
            list_files()
        elif choice == 5:
            upload_file()
        elif choice == 6:
            delete_file()
        elif choice == 7:
            download_file()
    except ValueError:
        pass  # Don't do anything for invalid inputs so we can simply exit
