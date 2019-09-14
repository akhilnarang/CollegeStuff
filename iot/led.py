import RPi.GPIO as gpio
from time import sleep

gpio.setmode(gpio.BCM)
gpio.setwarnings(False)

pin = 14

gpio.setup(pin, gpio.OUT)


def loop():
    while True:
        print("LED on")
        gpio.output(pin, gpio.HIGH)
        sleep(1)
        print("LED off")
        gpio.output(pin, gpio.LOW)
        sleep(1)


try:
    loop()
except KeyboardInterrupt:
    gpio.output(pin, gpio.LOW)
    gpio.cleanup()
