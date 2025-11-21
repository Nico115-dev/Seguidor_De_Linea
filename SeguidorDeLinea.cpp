from microbit import *
import music
import time
import mecanumRobotV2

# ===============================
# CONFIGURACIÓN DE SENSORES
# ===============================

# Sensores de línea (DIGITALES)
left_sensor = pin3
right_sensor = pin10

# Sensor ultrasónico HC-SR04
trig = pin1
echo = pin2


# ===============================
# FUNCIÓN: LEER DISTANCIA
# ===============================

def read_distance():
    """
    Devuelve distancia en cm.
    Retorna 999 si no logra medir.
    """
    trig.write_digital(0)
    time.sleep_us(5)
    trig.write_digital(1)
    time.sleep_us(10)
    trig.write_digital(0)

    start = time.ticks_us()
    timeout = start + 30000

    while echo.read_digital() == 0:
        if time.ticks_us() > timeout:
            return 999

    start = time.ticks_us()

    while echo.read_digital() == 1:
        if time.ticks_us() > timeout:
            return 999

    end = time.ticks_us()
    duration = end - start

    return int(duration / 58)


# ===============================
# MOVIMIENTOS
# ===============================

def stop():
    mecanumRobotV2.CarStop()

def forward():
    mecanumRobotV2.CarRun(mecanumRobotV2.RunState.RUN_FORWARD)

def backward():
    mecanumRobotV2.CarRun(mecanumRobotV2.RunState.RUN_BACK)

def turn_left():
    mecanumRobotV2.CarRun(mecanumRobotV2.RunState.RUN_LEFT)

def turn_right():
    mecanumRobotV2.CarRun(mecanumRobotV2.RunState.RUN_RIGHT)


# ===============================
# EVASIÓN DE OBSTÁCULOS
# ===============================

def avoid_obstacle():
    stop()
    sleep(200)

    backward()
    sleep(400)

    turn_left()
    sleep(350)

    stop()


# ===============================
# PROGRAMA PRINCIPAL
# ===============================

display.scroll("MECANUM AUTO")
music.play(music.POWER_UP)

while True:

    # ------- 1. Verificación de obstáculos -------
    distancia = read_distance()

    if distancia < 15:
        display.show(Image.SAD)
        avoid_obstacle()
        continue  # saltar seguidor de línea


    # ------- 2. SEGUIDOR DE LÍNEA -------
    left_val = left_sensor.read_digital()
    right_val = right_sensor.read_digital()

    # Interpretación:
    # negro = 0 (línea detectada)
    # blanco = 1 (fuera de línea)

    if left_val == 0 and right_val == 0:
        forward()

    elif left_val == 0 and right_val == 1:
        turn_left()

    elif left_val == 1 and right_val == 0:
        turn_right()

    else:
        stop()

    sleep(40)
