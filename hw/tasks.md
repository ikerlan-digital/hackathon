# Hardware

A cada equipo se le repartirán dos Raspberry Pi para implementar un escenario de monitorización con un elemento de edge computing (gateway).
Una de las Raspberry Pi hará el papel de nodo sensor mientras que la otra realizará funciones de nodo edge.

# Sistema operativo

Cada Raspberry Pi viene preinstalada con un sistema operativo GNU/Linux Raspbian basado en Debian. El sistema viene preinstalado con aplicaciones básicas para la implementación de la solución de los retos. Se puede utilizar apt-get para instalar aplicaciones.

# Acceso remoto

Las Raspberry Pi vienen previamente configuradas para conectarse automáticamente al punto de acceso WiFi configurado en la sala por Ikerlan. Este punto de acceso es únicamente para las Raspberry Pi, los ordenadores portatiles deben conectarse al WiFi de la escuela.

El puerto Ethernet de la Raspberry Pi está configurado con una IP fija y permite la conexión SSH para poder interaccionar con la Raspberry Pi. Además se pueden utilizar los protocolos SCP o SFTP para la transmisión de archivos.

__¿Cuál son los datos de conexión de la Raspberry?__
- Interfaz: Ethernet
- Direccion IP: 192.168.0.1
- Mascara de red: 255.255.255.0
- Usuario: pi
- Contraseña: raspberry

__¿Cómo conectarse mediante SSH a la Raspberry?__
Por ejemplo utilizando el programa Putty.

__¿Cómo conectarse mediante SCP/SFTP a la Raspberry?__
Por ejemplo utilizando el programa WinSCP.
