# Cloud related tasks

Ir order to access to your server instance a private key will provided.
<p align="center">
  <img width="600" height="351" src="https://github.com/ikerlan2015/hackathon/blob/master/cloud/cloud-arch.png">
</p>

## Configure an MQTT Broker 

The first task involves installing anc configuring an MQTT Broker such as [Mosquitto](https://mosquitto.org/). 

 * Download and configure mosquitto with at least **password** authentication. 
 * Test that your Edge node connects and that it´s able to send/receive messages. 
 
## Store sensor data in a Time Series Database 

 * Install a time series database such as [InfluxDB](https://portal.influxdata.com/downloads/)
 * Develop a program that stores data received on the broker on the Time Series database:
    * You can use whatever you want (python script / Java program, etc) to develop a small program.
    * Another option is to use [Telegraf](https://www.influxdata.com/time-series-platform/telegraf/) with its MQTT consumer [plugin](https://github.com/influxdata/telegraf/tree/master/plugins/inputs/mqtt_consumer)

## Develop a REST API capable of getting data stored on the Time Series Database

 * Develop a small REST API that is able to extract data from the Time Series Database, two options:
   * [Springboot](https://spring.io/projects/spring-boot)
   * [Flask](https://flask-restful.readthedocs.io/en/latest/)

## Develop a Dashboard in order to be able to see incoming data

Install an configure [Grafana](https://grafana.com/) in order to make an easy visualization of the incoming data.

## Real Time processing of incoming data

First install and configure a relational database such as MySql or Posgres.
Then develop a small program that makes stores and alarm on the relational database when a sensor data is above a given threshold. 

## Make a small machine learning model using the historical data stored in the time series Database



## Use Docker and docker-compose to Dockerize your solution 

Install docker and make scripts for all the developed components. 




