#!/usr/bin/env python3

student_data = {}

for i in range(10):
    print(f'Please enter details for student {i+1}')
    student_data[input('Enter name: ')] = float(input('Enter marks: '))

print('Top 5 students: ')
print('Name\tMarks')
student_sorted_data = sorted(student_data.items(), key=lambda item: item[1])
student_sorted_data.reverse()

for i in range(5):
    print(student_sorted_data[i][0] + '\t' + str(student_sorted_data[i][1]))
