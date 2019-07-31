from gpiozero import Buzzer, LED, TrafficLights
from time import sleep

buzzer = Buzzer(15)
lights = TrafficLights(25, 8, 21)
red, yellow, green = lights.red, lights.yellow, lights.green
left = LED(13)
right = LED(14)


def toggle(components, time):
    for component in components:
        on(component)
    sleep(time)
    for component in components:
        off(component)


def on(component):
    component.on()


def off(component):
    component.off()


def blink(led: LED):
    for _ in range(5):
        toggle((led, buzzer), 1)
        sleep(1)


def loop():
    while True:
        print("Green on for 5 seconds")
        toggle([green], 5)
        print("Blinking yellow with buzzer 5 times in 10 seconds")
        blink(yellow)
        print("Red on for 5 seconds")
        blink(red, 4)
        print("Buzzer on for 1 second")
        toggle([red, buzzer], 1)
        sleep(1)


try:
    print("Starting loop")
    loop()
except KeyboardInterrupt:
    print("KeyboardInterrupt - exiting")
    lights.close()
    buzzer.close()
