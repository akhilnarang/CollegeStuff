#!/usr/bin/env python3
import time
import paho.mqtt.client as paho
import Adafruit_DHT as dht 

#broker="broker.hivemq.com"
broker="127.0.0.1"
#broker="iot.eclipse.org"


def on_connect(client2, userdata, flags, rc):
    print("Publisher Connected with result code "+str(rc))
    time.sleep(2)

#define DHT11 reading
def DHT11_data():
	# Sensor data of temperature and humidity
	humi, temp = dht.read_retry(11,4) 
	return humi, temp

client2= paho.Client("client-002")
print("Connecting to broker... ",broker)
client2.connect(broker)
client2.on_connect = on_connect

client2.loop_start()
try:
    while True:
	humi,temp = DHT11_data()
	print('Temperature={0:0.1f}*C  Humidity={1:0.1f}%'.format(temp, humi))
  	print("publishing... ")
	client2.publish("mit/temperature",str(temp)) 
       	time.sleep(10)
except KeyboardInterrupt:
    client2.loop_stop()
    client2.disconnect()  
		            

