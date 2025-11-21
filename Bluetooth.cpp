from microbit import *
import music
import mecanumRobotV2

# ===============================
# FUNCIÓN: MOVIMIENTOS
# ===============================

def stop():
    mecanumRobotV2.CarStop()
    display.show(Image.NO)

def forward():
    mecanumRobotV2.CarRun(mecanumRobotV2.RunState.RUN_FORWARD)
    display.show(Image.ARROW_N)

def backward():
    mecanumRobotV2.CarRun(mecanumRobotV2.RunState.RUN_BACK)
    display.show(Image.ARROW_S)

def left():
    mecanumRobotV2.CarRun(mecanumRobotV2.RunState.RUN_LEFT)
    display.show(Image.ARROW_W)

def right():
    mecanumRobotV2.CarRun(mecanumRobotV2.RunState.RUN_RIGHT)
    display.show(Image.ARROW_E)

def forward_left():
    mecanumRobotV2.CarRun(mecanumRobotV2.RunState.RUN_UP_LEFT)
    display.show(Image.ARROW_NW)

def forward_right():
    mecanumRobotV2.CarRun(mecanumRobotV2.RunState.RUN_UP_RIGHT)
    display.show(Image.ARROW_NE)

def backward_left():
    mecanumRobotV2.CarRun(mecanumRobotV2.RunState.RUN_DOWN_LEFT)
    display.show(Image.ARROW_SW)

def backward_right():
    mecanumRobotV2.CarRun(mecanumRobotV2.RunState.RUN_DOWN_RIGHT)
    display.show(Image.ARROW_SE)


# ===============================
# INICIO DEL PROGRAMA
# ===============================

display.scroll("CONTROL BT")
music.play(music.POWER_UP)

uart.init(baudrate=115200)


# ===============================
# BUCLE PRINCIPAL
# ===============================

while True:
    if uart.any():
        cmd = uart.read().decode().strip()

        if cmd == "F": 
            forward()
        elif cmd == "B": 
            backward()
        elif cmd == "L": 
            left()
        elif cmd == "R": 
            right()
        elif cmd == "S": 
            stop()
        elif cmd == "G": 
            forward_left()
        elif cmd == "I": 
            forward_right()
        elif cmd == "H": 
            backward_left()
        elif cmd == "J": 
            backward_right()
        else:
            display.show("?")

    sleep(40)