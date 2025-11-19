from microbit import *
import music
import time

# ==== Configuración de pines ====
# Motores 
A1 = pin8    # Motor izquierdo adelante
A2 = pin12   # Motor izquierdo atrás
B1 = pin14   # Motor derecho adelante
B2 = pin15   # Motor derecho atrás

# Sensores de línea
left_sensor = pin3
right_sensor = pin10

# Sensor ultrasónico HC-SR04 (obstáculos frontales)
trig = pin1
echo = pin2


# ==== Funciones de movimiento ====
def stop():
    A1.write_digital(0); A2.write_digital(0)
    B1.write_digital(0); B2.write_digital(0)
    display.show(Image.NO)

def forward():
    A1.write_digital(1); A2.write_digital(0)
    B1.write_digital(1); B2.write_digital(0)
    display.show(Image.ARROW_N)

def backward():
    A1.write_digital(0); A2.write_digital(1)
    B1.write_digital(0); B2.write_digital(1)
    display.show(Image.ARROW_S)

def turn_left():
    A1.write_digital(0); A2.write_digital(0)
    B1.write_digital(1); B2.write_digital(0)
    display.show(Image.ARROW_W)

def turn_right():
    A1.write_digital(1); A2.write_digital(0)
    B1.write_digital(0); B2.write_digital(0)
    display.show(Image.ARROW_E)

def read_distance():
    """
    Lectura del sensor ultrasónico en centímetros.
    Devuelve: distancia en cm (int) o 999 si la lectura falla.
    """
    # Pulso de disparo (10 microsegundos)
    trig.write_digital(0)
    time.sleep_us(5)
    trig.write_digital(1)
    time.sleep_us(10)
    trig.write_digital(0)

    # Esperar el pulso de respuesta
    start = time.ticks_us()
    timeout = start + 30000  # 30 ms máximo

    while echo.read_digital() == 0:
        if time.ticks_us() > timeout:
            return 999  # Sin lectura

    start = time.ticks_us()

    while echo.read_digital() == 1:
        if time.ticks_us() > timeout:
            return 999

    end = time.ticks_us()

    duration = end - start
    distance = int(duration / 58)  # Conversión a cm

    return distance


def avoid_obstacle():
    """
    Maniobra de evasión básica:
    1. Se detiene
    2. Retrocede un poco
    3. Gira a la izquierda
    """
    stop()
    sleep(200)

    backward()
    sleep(400)

    turn_left()
    sleep(350)

    stop()


# ==== Inicio del Programa ====
display.scroll("SEGUIDOR")
music.play(music.POWER_UP)

# ==== BUCLE PRINCIPAL ====
while True:

    # ---- 1. Leer distancia y validar obstáculos ----
    distancia = read_distance()

    if distancia < 15:    # Menos de 15 cm = obstáculo
        display.show(Image.SAD)
        avoid_obstacle()
        continue          # Saltar la lógica del seguidor

    # ---- 2. Lector de sensores de línea ----
    left_val = left_sensor.read_digital()
    right_val = right_sensor.read_digital()

    # Interpretación:
    # Negro → 0
    # Blanco → 1

    if left_val == 0 and right_val == 0:
        forward()
    elif left_val == 0 and right_val == 1:
        turn_left()
    elif left_val == 1 and right_val == 0:
        turn_right()
    else:
        stop()

    sleep(40)
