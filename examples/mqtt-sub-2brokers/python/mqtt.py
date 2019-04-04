import paho.mqtt.client as mqtt
import time


def on_connect(mqttc, obj, flags, rc):
    print("rc: " + str(rc))


def on_message(mqttc, obj, msg):
    print(msg.topic + " " + str(msg.qos) + " " + str(msg.payload))
    print("Publish into NombreEquipo/pub")
    mqttc.publish("NombreEquipo/pub", "Message received");


def on_publish(mqttc, obj, mid):
    print("mid: " + str(mid))


def on_subscribe(mqttc, obj, mid, granted_qos):
    print("Subscribed: " + str(mid) + " " + str(granted_qos))


def on_log(mqttc, obj, level, string):
    print(string)


mqttc = mqtt.Client()
mqttc2 = mqtt.Client()
if __name__ == "__main__":
    mqttc.on_message = on_message
    mqttc.on_connect = on_connect
    mqttc.on_publish = on_publish
    mqttc.on_subscribe = on_subscribe
    # Uncomment to enable debug messages
    # mqttc.on_log = on_log
    mqttc.connect("127.0.0.1", 1883, 60)
    mqttc.subscribe("NombreEquipo1/sub", 0)

    mqttc2.on_message = on_message
    mqttc2.on_connect = on_connect
    mqttc2.on_publish = on_publish
    mqttc2.on_subscribe = on_subscribe
    # Uncomment to enable debug messages
    # mqttc2.on_log = on_log
    mqttc2.connect("127.0.0.1", 1884, 60)
    mqttc2.subscribe("NombreEquipo2/sub", 0)

    mqttc.loop_start()
    mqttc2.loop_start()

    while True:
        print("Loop...")
        time.sleep(5)
