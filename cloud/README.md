# Cloud related tasks

Ir order to access to your server instance, a private key will be provided.

You can convert it to ```putty``` format following this [guide](https://www2.linuxacademy.com/howtoguides/17385-use-putty-to-access-ec2-linux-instances-via-ssh-from-windows/).

The overview of the "final" architecture can be seen next: 
<p align="center">
  <img width="650" height="351" src="https://github.com/ikerlan2015/hackathon/blob/master/cloud/cloud-arch.png">
</p>

Python or Java knowledge is required to fulfill the following tasks (it´s your decision!).

## Instructions to connect to the Cloud via SSH
* Convert the key certificate included in your USBs to a valid format for Putty (convert from .pem to .ppk). Follow [these instructions](https://www2.linuxacademy.com/howtoguides/17385-use-putty-to-access-ec2-linux-instances-via-ssh-from-windows/).
* Use Putty to connect via SSH to the master node:
    * Hostname (IP): ```ec2-18-203-246-88.eu-west-1.compute.amazonaws.com```
    * Upload the generated private key (.ppk). In the left panel, go to SHH -> Auth -> Browse
    * Finally, push Open button
* Introduce the username within the prompted window (username = ec2-user)
* Connect via SSH to your personal machine:
    * `ssh -i konnekt.pem ec2-user@<private-ip>`
 
## MQTT Data Generator

A python3 script is provided in this folder as a random data generator to provide the basic data to test the system.

You need to install the paho-mqtt dependency (python3 -m pip install paho-mqtt) and modify the code to configure the MQTT authentication and topic.

## MQTT Broker

The broker is accessible at: ```ec2-63-35-224-92.eu-west-1.compute.amazonaws.com```
 
## Store sensor data in a Time Series Database 

 * Install a time series database such as [InfluxDB](https://portal.influxdata.com/downloads/)
 * Develop a program that 1) reads from MQTT broker the data coming from the edge node and 2) stores it into the Time Series database:
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
 * Then develop a small program that registers into the database an alarm every time a sensor data is above a given threshold. 
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


## Instrucciones para conectarse al Cloud via SSH
* Convertir el certificado incluido en vuestros USBs a un formato válido para Putty (convertir de .pem a .ppk). Seguid [estas instrucciones](https://www2.linuxacademy.com/howtoguides/17385-use-putty-to-access-ec2-linux-instances-via-ssh-from-windows/).
* Usar Putty para conectaros via SSH al nodo maestro:
    * Hostname (IP): ```ec2-18-203-246-88.eu-west-1.compute.amazonaws.com```
    * Añadir la clave privada generada anteriormente (.ppk). En el panel izquierdo, id a SHH -> Auth -> Browse.
    * Finalmente, pulsar el botón Open.
* Introducid el nombre de usuario en la ventaña emergente (username = ec2-user)
* Conectaos vía SSH a vustra máquina personal:
    * `ssh -i konnekt.pem ec2-user@<ip-privada>`


## MQTT Data Generator

Se provee de un script de python3 script que permite generar datos aleatorios para poder probar el sistema.

Las dependencias necesarias son (python3 -m pip install paho-mqtt), modifica el código para configurar la conexión a MQTT, el topic y la autenticación.

## MQTT Broker

El broker MQTT esta disponible en: ```ec2-63-35-224-92.eu-west-1.compute.amazonaws.com```


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




