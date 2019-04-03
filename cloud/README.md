# Cloud related tasks

Ir order to access to your server instance, a private key will be provided.
The overview of the "final" architecture can be seen next: 
<p align="center">
  <img width="650" height="351" src="https://github.com/ikerlan2015/hackathon/blob/master/cloud/cloud-arch.png">
</p>

Python or Java knowledge is required to fulfill the following tasks (it´s your decision!).

## Configure an MQTT Broker 

The first task involves installing and configuring an MQTT Broker such as [Mosquitto](https://mosquitto.org/). 

 * Download and configure mosquitto with at least **password** authentication. 
 * Test that your Edge node connects and that it´s able to send/receive messages. 
 
## MQTT Data Generator

A python3 script is provided in this folder as a random data generator to provide the basic data to test the system.

You need to install the paho-mqtt dependency (python3 -m pip install paho-mqtt) and modify the code to configure the MQTT authentication and topic.
 
## Store sensor data in a Time Series Database 

 * Install a time series database such as [InfluxDB](https://portal.influxdata.com/downloads/)
 * Develop a program that stores data received on the broker on the Time Series database:
    * You can use whatever you want (python script / Java program, etc) to develop a small program.
    * Another option is to use [Telegraf](https://www.influxdata.com/time-series-platform/telegraf/) with its MQTT consumer [plugin](https://github.com/influxdata/telegraf/tree/master/plugins/inputs/mqtt_consumer)

## Develop a REST API capable of getting data stored on the Time Series Database

 * Develop a small REST API that is able to extract data from the Time Series Database, two options:
   * [Springboot](https://spring.io/projects/spring-boot)
   * [Flask](https://flask-restful.readthedocs.io/en/latest/)
 * Use a tool like [Postman](https://www.getpostman.com/downloads/) to test the API. 

## Develop a Dashboard in order to be able to see incoming data

 * Install and configure [Grafana](https://grafana.com/) in order to develop on top of it an easy visualization of the incoming data (develop a Grafana ```dashboard```). 

## Real Time processing of incoming data

 * First install and configure a relational database such as [MySql](https://www.mysql.com/) or [PostgreSQL](https://www.postgresql.org/).
 * Then develop a small program that makes stores and fire an alarm on the relational database when a sensor data is above a given threshold. 
 * Use a program that connects to the database (e.g. [DBVeaber](https://dbeaver.io/)) for showing that your program works.

## Make machine learning model using the historical data stored in the time series database

 * See ```ml``` folder for further instructions.

## Use Docker and docker-compose to Dockerize your solution 

 * See ```docker``` folder for further instructions.


# Tareas relacionadas con el cloud

Para poder acceder a tu servidor se os proveerá de una clave privada.
Un diagrama de la arquitectura "final" puede verse en el siguiente diagrama:
<p align="center">
  <img width="650" height="351" src="https://github.com/ikerlan2015/hackathon/blob/master/cloud/cloud-arch.png">
</p>

Las tareas se pueden resolver con conocimiento de Python o Java. (es vuestra decisión!). 

## Configurar un Broker MQTT

La primera tarea es instalar y configurar un Broker MQTT como [Mosquitto](https://mosquitto.org/). 

 * Descargar y configurar el Broker con autenticación por **password** como mínimo. 
 * Testear que vuestros nodos se conectan al Broker y son capaces de enviar y recibir mensajes. 
 
## Guardar datos de sensores en una base de datos de Time Series

 * Instalar una base de datos de Time Series como puede ser [InfluxDB](https://portal.influxdata.com/downloads/)
 * Desarrollar un programa que almacene los datos recibidos en el Broker en la base de datos:
    * Bien desarrollando un pequeño programa (python script / Java program, etc).
    * Bien usando [Telegraf](https://www.influxdata.com/time-series-platform/telegraf/) con el plugin de MQTT [plugin](https://github.com/influxdata/telegraf/tree/master/plugins/inputs/mqtt_consumer)

## Desarrollar una API REST que sea capaz de extraer datos de la base de datos

 * Desarrollar una pequeña API REST que sea capaz de extraer datos de la base de datos, dos opciones:
   * [Springboot](https://spring.io/projects/spring-boot)
   * [Flask](https://flask-restful.readthedocs.io/en/latest/)
 * Puedes usar una herramienta como [Postman](https://www.getpostman.com/downloads/) para testear la API. 

## Desarrollar un Dashboard para visualizar en tiempo real los datos entrantes

 * Instalar y configurar [Grafana](https://grafana.com/) para poder desarrollar un ```dashboard``` de Grafana manera sencilla de tal forma que se puedan ver los datos de entrada.

## Procesamiento en tiempo real de los datos

 * Primero instalar y configurar una base de datos relacional como [MySql](https://www.mysql.com/) ó [PostgreSQL](https://www.postgresql.org/).
 * Desarrollar un pequeño programa que guarde una alarma en esa BD cuando cierto sensor pase de cierto valor.
 * Usar un programa como (e.g. [DBVeaber](https://dbeaver.io/)) para demostrar que vuestro programa funciona.

## Realizar un modelo de machine learning en base a datos historicos almacenados en la base de datos de time series

 * Mirar el directorio ```ml``` para más instrucciones.

## Usar Docker y docker-compose para "dockerizar" vuestra solución 

 * Mirar el directorio ```docker``` para más instrucciones.




