#!/usr/bin/env python3

import requests
from time import sleep
import Adafruit_DHT as dht
import random

url = "https://api.thingspeak.com/update.json"
api_key = "PGDU2UY4RHZ06G3D"


def get_data():
    return dht.read_retry(dht.DHT11, 23)
    # return random.randrange(20, 30), random.randrange(20, 30)


def send_data(url, data):
    return requests.post(url, data)


if __name__ == "__main__":
    while True:
        try:
            humidity, temperature = get_data()
            print(f"Humidity: {humidity}\nTemperature: {temperature}")
            data = {"api_key": api_key, "field1": humidity, "field2": temperature}
            response = send_data(url, data)
            print(response)
            print(response.text)
            sleep(15)
        except KeyboardInterrupt:
            print("OK, exiting!")
            break
