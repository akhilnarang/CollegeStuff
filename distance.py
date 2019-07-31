import RPi.GPIO as gpio
from time import time, sleep

# GPIO Mode (BOARD / BCM)
gpio.setmode(gpio.BOARD)
# Set GPIO Pins
GPIO_TRIGGER = 7
GPIO_ECHO = 11

# Set GPIO direction (IN / OUT)
gpio.setup(GPIO_TRIGGER, gpio.OUT)
gpio.setup(GPIO_ECHO, gpio.IN)


def distance():
    # Set trigger to HIGH
    gpio.output(GPIO_TRIGGER, True)

    # Set trigger after 0.01ms to LOW
    sleep(0.00001)
    gpio.output(GPIO_TRIGGER, False)

    start_time = time()
    stop_time = time()

    # Get the start time
    while gpio.input(GPIO_ECHO) == 0:
        start_time = time()
    print("Start time: %.4f seconds" % start_time)
    # Get the stop time
    while gpio.input(GPIO_ECHO) == 1:
        stop_time = time()
    print("Stop time: %.4f seconds" % stop_time)
    # Time difference between start and arrival
    time_elapsed = stop_time - start_time
    if time_elapsed < 0:
        print("Negative time elapsed, something is wrong!")
        return 0
    print("Time elapsed: %.4f seconds" % time_elapsed)
    # Multiply with the sonic speed (34300 cm/s) and divide by 2, because it travels and comes back
    distance = (time_elapsed * 34300) / 2
    return distance


try:
    while True:
        dist = distance()
        if dist != 0:
            print("Measured Distance = %.1f cm" % dist)
        sleep(1)

except KeyboardInterrupt:
    print("Measurement stopped by User")
    gpio.cleanup()
