from microbit import *
import music

# ==== Configuración de pines ====
# Motores
A1 = pin8    # Motor izquierdo adelante
A2 = pin12   # Motor izquierdo atrás
B1 = pin14   # Motor derecho adelante
B2 = pin15   # Motor derecho atrás

# Sensores de línea
left_sensor = pin3
right_sensor = pin10

# ==== Funciones de movimiento ====
def stop():
    A1.write_digital(0)
    A2.write_digital(0)
    B1.write_digital(0)
    B2.write_digital(0)
    display.show(Image.NO)

def forward():
    A1.write_digital(1)
    A2.write_digital(0)
    B1.write_digital(1)
    B2.write_digital(0)
    display.show(Image.ARROW_N)

def turn_left():
    A1.write_digital(0)
    A2.write_digital(0)
    B1.write_digital(1)
    B2.write_digital(0)
    display.show(Image.ARROW_W)

def turn_right():
    A1.write_digital(1)
    A2.write_digital(0)
    B1.write_digital(0)
    B2.write_digital(0)
    display.show(Image.ARROW_E)

# ==== Inicio Del Programa ====
display.scroll("SEGUIDOR DE LINEA")
music.play(music.POWER_UP)

# ==== Bucle principal Para El Programa ====
while True:
    left_val = left_sensor.read_digital()
    right_val = right_sensor.read_digital()

    # Interpretación:
    # Sensor sobre línea negra → 0
    # Sensor sobre blanco → 1

    if left_val == 0 and right_val == 0:
        forward()
    elif left_val == 0 and right_val == 1:
        turn_left()
    elif left_val == 1 and right_val == 0:
        turn_right()
    else:
        stop()

    sleep(50)
