from microbit import *
import music
import time
import mecanumRobotV2

// ===============================
// CONFIGURACIÓN DE SENSORES
// ===============================

// # Sensores de línea (DIGITALES)
left_sensor = pin3
right_sensor = pin10

# Sensor ultrasónico HC-SR04
trig = pin1
echo = pin2


// ===============================
// FUNCIÓN: LEER DISTANCIA
// ===============================

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


// ===============================
// MOVIMIENTOS
// ===============================

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


// ===============================
// EVASIÓN DE OBSTÁCULOS
// ===============================

def avoid_obstacle():
    stop()
    sleep(200)

    backward()
    sleep(400)

    turn_left()
    sleep(350)

    stop()


// ===============================
// Recuperar línea
// ===============================

def line_recovery():
    // Mostrar que está buscando línea
    mecanumRobotV2.CarRunSpeed(mecanumRobotV2.RunState.RUN_LEFT, 40)
    sleep(200)
    // ¿Encontró la línea al girar?
    if left_sensor.read_digital() == 0 or right_sensor.read_digital() == 0:
        display.show(Image.HAPPY)
        return

    // Gira hacia el otro lado si no encontró nada
    mecanumRobotV2.CarRunSpeed(mecanumRobotV2.RunState.RUN_RIGHT, 40)
    sleep(200)


// ===============================
// Control proporcional
// ===============================

def follow_line_proportional():
    left_val = left_sensor.read_digital()
    right_val = right_sensor.read_digital()

    // negro = 0 (línea)
    // blanco = 1 (fuera)

    // Detecta pérdida total
    if left_val == 1 and right_val == 1:
        return line_recovery()

    //  Error proporcional
    if left_val == 0 and right_val == 1:
        error = -1      # mover hacia la izquierda
    elif left_val == 1 and right_val == 0:
        error = +1      # mover hacia la derecha
    else:
        error = 0       # centro perfecto

    // Control De Velocidad
    base_speed = 60     # velocidad base
    kp = 35             # ganancia proporcional

    correction = kp * error

    left_speed = base_speed - correction
    right_speed = base_speed + correction

    // Limitar valores (0 – 100)
    left_speed = max(0, min(100, left_speed))
    right_speed = max(0, min(100, right_speed))

    // Movimiento proporcional
    mecanumRobotV2.CarRunSpeed(
        mecanumRobotV2.RunState.RUN_FORWARD,
        left_speed,
        right_speed
    )


// ===============================
// PROGRAMA PRINCIPAL
// ===============================

display.scroll("SEGUIDOR DE LINEA")
music.play(music.POWER_UP)

while True:

    //  ------- 1. Verificación de obstáculos -------
    distancia = read_distance()

    if distancia < 15:
        display.show(Image.SAD)
        avoid_obstacle()
        continue  # saltar seguidor de línea

    //  ------- 2. SEGUIDOR DE LÍNEA (MEJORADO) -------
    follow_line_proportional()
    sleep(40)
