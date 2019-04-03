# Reto: Internet of Things

El reto Internet of Things del hackathon se enfoca en la implementación de un esquema de monitorización y control remoto utilizando un esquema de Sensor<->Edge<->Cloud.

## Nodo sensor
El nodo sensor está implementado en una de las Raspberry Pi del reto. 

### Lectura datos linea serie
El nodo debe leer de la linea serie (/dev/ttyS0) datos que llegan de forma aleatoria desde la turbina eólica. Para ello el programa debe estar leyendo de forma continua la linea serie y cada vez que llegue un mensaje, parsearlo, formatearlo y enviarlo al nodo edge.

### Parseo datos industriales
Este nodo debe ser capaz de parsear los mensajes recibidos a través de línea serie y transformarlos a un formato estándar basado en JSON.
El formato de los mensajes es el siguiente:
- 1er Byte: tipo de mensaje:
  - 0x01: Temperatura
  - 0x02: Velocidad aspas
  - 0x03: Energía producida (kWh)
  - 0x04: Velocidad viento
  - 0x05: Presión turbina
  - 0xFF: Alarma
- 2-9do Byte: Dato UInt64 (BigEndian) (unidad 0.01), por ejemplo, 2452 sería 24,52. En el caso de la alarma es un String de 8 caracteres.
- 10o Byte: Byte fin mensaje (0x00)

| Typo de mensaje | Dato | Fin de mensaje |
| --- | --- | --- |
| 1 Byte | 8 Bytes | 1 Byte |

### Visualizacion y log
El nodo debe guardar en un log (archivo de texto) o mostrar en pantalla el parseo en tiempo real del mensaje, mostrando el tipo y el dato traducido a float.

### Envío de datos al nodo edge
Este nodo se debe comunicar a través de WiFi con el nodo edge para enviarle los mensajes en formato JSON empleando un protocolo IoT (MQTT, REST/HTTP, CoAP, MQTT-SN, etc.).

Los JSON deben cumplir el siguiente modelo de datos (el timestamp esta definido como Linux Epoch)
```
{
  "timestamp": 1554199331,
  "type": "temp",
  "value": 24.52
}
```
```
{
  "timestamp": 1554199331,
  "type": "speed_blade",
  "value": 84.52
}
```
```
{
  "timestamp": 1554199331,
  "type": "energy",
  "value": 24.52
}
```
```
{
  "timestamp": 1554199331,
  "type": "speed_wind",
  "value": 22.52
}
```
```
{
  "timestamp": 1554199331,
  "type": "pressure",
  "value": 1500
}
```
```
{
  "timestamp": 1554199331,
  "type": "alarm",
  "value": "CRITICAL"
}
```

## Nodo edge
El nodo edge está implementado en la segunda Raspberry Pi.

### Ingesta de datos desde nodos sensores
Debe implementar un servidor o broker que permita recibir los mensajes del nodo sensor (Broker MQTT como Mosquitto, Servidor/API Rest en caso de HTTP, etc.).

**TIP**: En la Raspberry se encuentra preinstalado el broker MQTT Mosquito.

### Gateway(bridge) con la nube
El nodo edge debe hacer de puente con Internet. 

Para ello, debe mandar a un servidor MQTT remoto todos los datos agregados cada un tiempo configurable (por defecto 10 segundos).
Estará habilitado un servidor remoto de prueba para desarrollo en la IP 192.168.1.222. Se debe publicar en el topic "NombreEquipo" para no colisionar con otros equipos.

**TIP**: Con las aplicaciones "mosquitto_pub" y "mosquitto_sub" preinstaladas en las Raspberrys se puede publicar y subscribirse de forma manual para acelerar el desarrollo y testear.

EJ: mosquitto_sub -h "192.168.1.222" -t "NombreEquipo" permite subscribirse al topic "NombreEquipo" y ver que se recibe en el.

EJ: mosquitto_pub -h "192.168.1.222" -t "NombreEquipo" -m "TEST" permite publicar un mensaje en el topic "NombreEquipo".

### Inteligencia
El nodo edge puede implementar inteligencia para desarrollar un sistema de alarmas. Se valorará si se puede setear un límite o threshold a las variables recibidas desde el nodo sensor, que en el caso de ser superado genere un mensaje asíncrono que se mande a la nube.

## Tips!
### Protocolos comunicaciones IoT
Los protocolos estándar de comunicaciones IoT más comunes son los siguientes:

- MQTT (Standard IoT Protocol)
  - https://github.com/mqtt/mqtt.github.io/wiki
  - https://randomnerdtutorials.com/what-is-mqtt-and-how-it-works/
- HTTP (REST)
  - https://spring.io/understanding/REST
- CoAP
  - https://coap.technology/
- MQTT-SN
  - http://www.steves-internet-guide.com/mqtt-sn/

### Lenguajes de programación sugeridos
- Python ([What Is](https://www.python.org/))
- C/C++ ([What Is](https://www.programiz.com/c-programming))
- JavaScript ([NodeJS](https://nodejs.org/en/about/), [Node-RED](https://nodered.org/))
