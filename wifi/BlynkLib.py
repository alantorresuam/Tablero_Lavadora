# Definición de la versión del código
__version__ = "1.0.0"
 
# Importación de módulos necesarios
import struct  # Módulo para manejar datos estructurados binarios
import time  # Módulo para trabajar con el tiempo
import sys  # Módulo que proporciona acceso a algunas variables usadas o mantenidas por el intérprete
import os  # Módulo que proporciona funciones para interactuar con el sistema operativo
 
# Manejo de importaciones condicionales según el entorno
try:
    import machine  # Importa el módulo "machine" si está disponible (microPython)
    gettime = lambda: time.ticks_ms()  # Función para obtener el tiempo en milisegundos
    SOCK_TIMEOUT = 0  # Tiempo de espera de socket
except ImportError:
    const = lambda x: x  # Función de identidad
    gettime = lambda: int(time.time() * 1000)  # Función para obtener el tiempo en milisegundos
    SOCK_TIMEOUT = 0.05  # Tiempo de espera de socket
 
