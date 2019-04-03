#!/usr/bin/python3
from random import uniform
import json
import time
import paho.mqtt.publish as publish


temp = 25
max_temp = 60
wind = 80
max_wind = 160
pressure = 1013
min_pressure = 900
max_pressure = 1040
wind2speed = 0.5
wind2power = 1.2


def gen_temp():
    global temp
    temp = temp + uniform(-1, 1)
    if temp < 0:
        temp = 0
    elif temp > max_temp:
        temp = max_temp
    return temp 


def gen_speed():
    speed = int(wind * wind2speed)
    return speed


def gen_power():
    power = int(wind * wind2power)
    return power


def gen_wind():
    global wind
    wind = wind + uniform(-1, 1)
    if wind < 0:
        wind = 0
    elif wind > max_wind:
        wind = max_wind
    return wind


def gen_pressure():
    global pressure
    pressure = pressure + uniform(-1, 1)
    if pressure < min_pressure:
        pressure = min_presure
    elif pressure > max_pressure:
        pressure = max_presure
    return pressure


def gen_alarm():
    return "CRIT-AL22"


def gen_msg(type):
    msg = {} 

    # Data
    if type == 1:
        msg['temp'] = gen_temp()
    elif type == 2:
        msg['speed'] = gen_speed()
    elif type == 3:
        msg['power'] = gen_power()
    elif type == 4:
        msg['wind'] = gen_wind()
    elif type == 5:
        msg['pressure'] = gen_pressure()
    elif type == 255:
        msg['alarm'] = gen_alarm()
    else:
        print("Error: Not supported")
        return msg 

    # Timestamp
    msg['timestamp'] = int(time.time())

    print("JSON: ", json.dumps(msg))
    return json.dumps(msg)


def mqtt_send(data):
    try:
        # TODO: Set topic name and auth
        publish.single("NombreEquipo", data, hostname="127.0.0.1", auth={'username': 'ik', 'password': 'ik'})
    except Exception as e:
        print("ERROR: MQTT publish error: ", e)


def gen_data():
    for i in range(1, 6):
        mqtt_send(gen_msg(i))
    # Only generate alarms 1%
    if uniform(0, 1) < 0.01:
        mqtt_send(gen_msg(255))


if __name__ == "__main__":
    while True:
        gen_data()
        time.sleep(1)
