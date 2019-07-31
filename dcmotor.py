import RPi.GPIO as gpio
from time import sleep

in1 = 2
in2 = 3
en = 18
temp1 = 1

gpio.setmode(gpio.BCM)
gpio.setup(in1, gpio.OUT)
gpio.setup(in2, gpio.OUT)
gpio.setup(en, gpio.OUT)
gpio.output(in1, gpio.LOW)
gpio.output(in2, gpio.LOW)
gpio.output(en, gpio.HIGH)
print("\n")
print("The default speed & direction of motor is LOW & Forward.....")
print("r-run s-stop f-forward b-backward e-exit")
print("\n")

while 1:

    x = input()

    if x == "r":
        print("run")
        if temp1 == 1:
            gpio.output(in1, gpio.HIGH)
            gpio.output(in2, gpio.LOW)
            print("forward")
            x = "z"
        else:
            gpio.output(in1, gpio.LOW)
            gpio.output(in2, gpio.HIGH)
            print("backward")
            x = "z"

    elif x == "s":
        print("stop")
        gpio.output(in1, gpio.LOW)
        gpio.output(in2, gpio.LOW)
        x = "z"

    elif x == "f":
        print("forward")
        gpio.output(in1, gpio.HIGH)
        gpio.output(in2, gpio.LOW)
        temp1 = 1
        x = "z"

    elif x == "b":
        print("backward")
        gpio.output(in1, gpio.LOW)
        gpio.output(in2, gpio.HIGH)
        temp1 = 0
        x = "z"

    elif x == "e":
        gpio.cleanup()
        break

    else:
        print("<<<  wrong data  >>>")
        print("please enter the defined data to continue.....")
