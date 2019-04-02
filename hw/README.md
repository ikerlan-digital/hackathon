# Hardware

A cada equipo se le repartirán dos Raspberry Pi para implementar un escenario de monitorización con un elemento de edge computing (gateway).
Una de las Raspberry Pi hará el papel de nodo sensor mientras que la otra realizará funciones de nodo edge.

## Sistema operativo

Cada Raspberry Pi viene preinstalada con un sistema operativo GNU/Linux Raspbian basado en Debian. El sistema viene preinstalado con aplicaciones básicas para la implementación de la solución de los retos. Se puede utilizar apt-get para instalar aplicaciones.

## Conectividad

Las Raspberry Pi tienen dos interfaces de red:
- Ethernet: Sólo para acceso de administración desde un portatil a través de la IP 192.168.0.1
- Wifi: Para acceso a Internet y a otras raspberry pi

Las Raspberry Pi vienen previamente configuradas para conectarse automáticamente al punto de acceso WiFi configurado en la sala por Ikerlan. Este punto de acceso es únicamente para las Raspberry Pi, los ordenadores portatiles deben conectarse al WiFi de la escuela.

El puerto Ethernet de la Raspberry Pi está configurado con una IP fija y permite la conexión SSH para poder interaccionar con la Raspberry Pi. Además se pueden utilizar los protocolos SCP o SFTP para la transmisión de archivos.

__¿Cuál son los datos de conexión de la Raspberry?__
- Interfaz: Ethernet
- Direccion IP: 192.168.0.1
- Mascara de red: 255.255.255.0
- Usuario: pi
- Contraseña: raspberry

Para poder conectaros debéis setear vuestra conexión de Ethernet con IP fija en el rango IP de la Raspberry, por ejemplo, 192.168.0.2.
https://www.redeszone.net/windows/ip-privada-fija-en-windows-7/

__¿Cómo conectarse mediante SSH a la Raspberry?__
Por ejemplo utilizando el programa Putty.
https://www.chiark.greenend.org.uk/~sgtatham/putty/latest.html

__¿Cómo conectarse mediante SCP/SFTP a la Raspberry?__
Por ejemplo utilizando el programa WinSCP.
https://winscp.net/eng/download.php
