import RPi.GPIO as gpio
from time import sleep

gpio.setmode(gpio.BOARD)
control_pins = (7, 11, 13, 15)

halfstep_seq = [
    [1, 0, 0, 0],
    [1, 1, 0, 0],
    [0, 1, 0, 0],
    [0, 1, 1, 0],
    [0, 0, 1, 0],
    [0, 0, 1, 1],
    [0, 0, 0, 1],
    [1, 0, 0, 1],
]


def reset_pin(pin):
    gpio.setup(pin, gpio.OUT)
    gpio.output(pin, 0)


def reset():
    for pin in control_pins:
        reset_pin(pin)


def run():
    for _ in range(512):
        for halfstep in range(8):
            for pin in range(4):
                gpio.output(control_pins[pin], halfstep_seq[halfstep][pin])
            sleep(0.002)


def move_motor():
    reset()
    run()


try:
    # Clockwise direction
    move_motor()

    # Reverse for anticlockwise
    halfstep_seq.reverse()
    move_motor()

finally:
    gpio.cleanup()
