from influxdb import InfluxDBClient
import paho.mqtt.client as mqtt
import json

db_host = 'localhost'
db_port = 8086
db_user = 'root'
db_password = 'root'
db_name = 'example'


def on_connect(client, userdata, flags, rc):
    if rc == 0:
        client.connected_flag = True  # set flag
        print("connected OK Returned code =", rc)
        # client.subscribe(topic)
    else:
        print("Bad connection Returned code =", rc)


def on_message(client, userdata, msg):
    print(type(msg.payload))
    point_list = []
    # parse from bytes to string
    try:
        json_str = json.loads(msg.payload.decode("utf-8"))
        # we are only saving pressure into the database
        # customize your dictionary as required
        if 'pressure' in list(json_str.keys()):
            point = {}
            point['measurement'] = 'test'
            tags = {"host": "server01", "region": "us-west"}
            point['tags'] = tags
            point['time'] = '2019-11-10T23:00:00Z'
            point['fields'] = {'value': json_str['pressure']}
            point_list.append(point)

        save_data_into_influx(point_list)
    except Exception as e:
        print(e)


def save_data_into_influx(point_list: list):
    influx_client = InfluxDBClient(db_host, db_port, db_user, db_password, db_name)

    print('saving data')
    try:
        influx_client.write_points(point_list)
    except Exception as e:
        print(e)

    influx_client.close()


def main():
    client = mqtt.Client('python1')  # create new instance
    client.username_pw_set(username="mqtt-user", password="ikerlankonnect")
    client.on_connect = on_connect  # bind call back function
    client.on_message = on_message
    client.connect('ec2-63-35-224-92.eu-west-1.compute.amazonaws.com')  # connect to broker
    client.loop_forever()  # Start loop
    client.subscribe('mcanizo', 0)


if __name__ == '__main__':
    main()
