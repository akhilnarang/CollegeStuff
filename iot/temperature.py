from time import sleep

import Adafruit_DHT as dht


def read_data():
    return dht.read_retry(dht.DHT22, 23)


while True:
    try:
        print("Checking temperature")
        temperature = read_data()[1]
        print("%.2f" % temperature)
        sleep(2)
    except KeyboardInterrupt:
        break
