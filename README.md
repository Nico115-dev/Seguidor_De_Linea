# 🤖 Robot Seguidor de Línea

Este proyecto consiste en la construcción y programación de un **robot seguidor de línea** y **robot controlado via bluetooth**, capaz de detectar y seguir un recorrido trazado en el suelo (generalmente una línea negra sobre fondo blanco) de forma autónoma utilizando sensores infrarrojos y un microcontrolador.

---

## 🧩 Descripción General 

El **robot seguidor de línea** es un sistema mecatrónico que combina **electrónica**, **control** y **programación**. Su objetivo principal es mantenerse sobre una línea predefinida mediante la lectura de sensores y el ajuste dinámico de sus motores.


---

## ⚙️ Componentes Utilizados Para Construir El Robot

| Componente | Cantidad | Descripción |
|-------------|-----------|-------------|
| Arduino UNO | 1 | Microcontrolador principal |
| Módulo L298N | 1 | Controlador de motores DC |
| Motores DC con ruedas | 2 | Para el movimiento del robot |
| Sensor infrarrojo (TCRT5000 o módulo QTR-8A) | 3 - 5 | Detectan la línea |
| Batería (7.4V o 9V) | 1 | Fuente de alimentación |
| Chasis para robot | 1 | Estructura base |
| LED indicador (opcional) | 1 | Señal visual de funcionamiento |


## 📖 Que encontrarás en este repositorio?

En este repositorio encontrarás 2 tipos de programación para el robot 4WD Mecanum Robot Car.

El archivo que se llama Bluetooth es un programa para usar el robot via bluetooth con un programa llamado Mecanum Car, este contiene una programación bastante basica que consta de un par de funciones que se le asignan a unas entradas que coinciden con el programa que se encuentra en la play store o la app store.

Y el archivo cuyo nombre tiene Seguidor De Linea hace que el robot una vez esta con la programación que se encuentra allí, el robot empezará a seguir una linea negra (El funcionamiento es sencillo los sensores detectan la diferencia de color cuando el robot ejecuta una función se activa una imagen que indica lo que el robot esta haciendo), el robot se pondrá a seguir la linea y cuando encuentre un objeto que obstruye el camino se detendrá y buscará la mejor manera de evadirlo (Todo esto gracias a validaciones que se hicieron para que el robot se mantuviera en su camino a salvo).
