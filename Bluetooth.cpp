from microbit import *
import music
from keyes_mecanum_Car_V2 import *

mecanumCar = Mecanum_Car_Driver_V2()

# ===============================
# FUNCIONES DE MOVIMIENTO
# ===============================

def stop():
    mecanumCar.Motor_Upper_L(0, 0)
    mecanumCar.Motor_Lower_L(0, 0)
    mecanumCar.Motor_Upper_R(0, 0)
    mecanumCar.Motor_Lower_R(0, 0)
    display.show(Image.NO)

def forward():
    mecanumCar.Motor_Upper_L(1, 80)
    mecanumCar.Motor_Lower_L(1, 80)
    mecanumCar.Motor_Upper_R(1, 80)
    mecanumCar.Motor_Lower_R(1, 80)
    display.show(Image.ARROW_N)

def backward():
    mecanumCar.Motor_Upper_L(0, 80)
    mecanumCar.Motor_Lower_L(0, 80)
    mecanumCar.Motor_Upper_R(0, 80)
    mecanumCar.Motor_Lower_R(0, 80)
    display.show(Image.ARROW_S)

def left():
    # Giro puro hacia la izquierda
    mecanumCar.Motor_Upper_L(0, 80)
    mecanumCar.Motor_Lower_L(0, 80)
    mecanumCar.Motor_Upper_R(1, 80)
    mecanumCar.Motor_Lower_R(1, 80)
    display.show(Image.ARROW_W)

def right():
    # Giro puro hacia la derecha
    mecanumCar.Motor_Upper_L(1, 80)
    mecanumCar.Motor_Lower_L(1, 80)
    mecanumCar.Motor_Upper_R(0, 80)
    mecanumCar.Motor_Lower_R(0, 80)
    display.show(Image.ARROW_E)

def forward_left():
    # Adelante + giro suave a la izquierda
    mecanumCar.Motor_Upper_L(1, 40)
    mecanumCar.Motor_Lower_L(1, 40)
    mecanumCar.Motor_Upper_R(1, 80)
    mecanumCar.Motor_Lower_R(1, 80)
    display.show(Image.ARROW_NW)

def forward_right():
    # Adelante + giro suave a la derecha
    mecanumCar.Motor_Upper_L(1, 80)
    mecanumCar.Motor_Lower_L(1, 80)
    mecanumCar.Motor_Upper_R(1, 40)
    mecanumCar.Motor_Lower_R(1, 40)
    display.show(Image.ARROW_NE)

def backward_left():
    mecanumCar.Motor_Upper_L(0, 40)
    mecanumCar.Motor_Lower_L(0, 40)
    mecanumCar.Motor_Upper_R(0, 80)
    mecanumCar.Motor_Lower_R(0, 80)
    display.show(Image.ARROW_SW)

def backward_right():
    mecanumCar.Motor_Upper_L(0, 80)
    mecanumCar.Motor_Lower_L(0, 80)
    mecanumCar.Motor_Upper_R(0, 40)
    mecanumCar.Motor_Lower_R(0, 40)
    display.show(Image.ARROW_SE)


# ===============================
# INICIO DEL SISTEMA
# ===============================

display.scroll("BT")
music.play(music.POWER_UP)

uart.init(baudrate=115200)


# ===============================
# BUCLE PRINCIPAL
# ===============================

while True:
    if uart.any():
        cmd = uart.read().decode().strip()

        if cmd == "F": forward()
        elif cmd == "B": backward()
        elif cmd == "L": left()
        elif cmd == "R": right()
        elif cmd == "S": stop()
        elif cmd == "G": forward_left()
        elif cmd == "I": forward_right()
        elif cmd == "H": backward_left()
        elif cmd == "J": backward_right()
        else:
            display.show("?")

    sleep(20)
