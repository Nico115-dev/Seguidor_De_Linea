from microbit import *
import music

# ==== Configuración de pines para la placa ====
# Motor A (frontal izquierdo)
A1 = pin8
A2 = pin12

# Motor B (frontal derecho)
B1 = pin14
B2 = pin15

# Motor C (trasero izquierdo)
C1 = pin16
C2 = pin13

# Motor D (trasero derecho)
D1 = pin1
D2 = pin2

# ==== Funciones de movimiento para el robot ====
def stop():
    for m in [A1, A2, B1, B2, C1, C2, D1, D2]:
        m.write_digital(0)
    display.show(Image.NO)

def forward():
    A1.write_digital(1); A2.write_digital(0)
    B1.write_digital(1); B2.write_digital(0)
    C1.write_digital(1); C2.write_digital(0)
    D1.write_digital(1); D2.write_digital(0)
    display.show(Image.ARROW_N)

def backward():
    A1.write_digital(0); A2.write_digital(1)
    B1.write_digital(0); B2.write_digital(1)
    C1.write_digital(0); C2.write_digital(1)
    D1.write_digital(0); D2.write_digital(1)
    display.show(Image.ARROW_S)

def left():
    A1.write_digital(0); A2.write_digital(1)
    B1.write_digital(1); B2.write_digital(0)
    C1.write_digital(1); C2.write_digital(0)
    D1.write_digital(0); D2.write_digital(1)
    display.show(Image.ARROW_W)

def right():
    A1.write_digital(1); A2.write_digital(0)
    B1.write_digital(0); B2.write_digital(1)
    C1.write_digital(0); C2.write_digital(1)
    D1.write_digital(1); D2.write_digital(0)
    display.show(Image.ARROW_E)

def forward_left():
    A1.write_digital(0); A2.write_digital(0)
    B1.write_digital(1); B2.write_digital(0)
    C1.write_digital(1); C2.write_digital(0)
    D1.write_digital(0); D2.write_digital(0)
    display.show(Image.ARROW_NW)

def forward_right():
    A1.write_digital(1); A2.write_digital(0)
    B1.write_digital(0); B2.write_digital(0)
    C1.write_digital(0); C2.write_digital(0)
    D1.write_digital(1); D2.write_digital(0)
    display.show(Image.ARROW_NE)

def backward_left():
    A1.write_digital(0); A2.write_digital(1)
    B1.write_digital(0); B2.write_digital(0)
    C1.write_digital(0); C2.write_digital(1)
    D1.write_digital(0); D2.write_digital(0)
    display.show(Image.ARROW_SW)

def backward_right():
    A1.write_digital(0); A2.write_digital(0)
    B1.write_digital(0); B2.write_digital(1)
    C1.write_digital(0); C2.write_digital(0)
    D1.write_digital(0); D2.write_digital(1)
    display.show(Image.ARROW_SE)

# ==== Inicio Del Programa ====
display.scroll("CONTROLADO")
music.play(music.POWER_UP)

# ==== Bucle principal ====
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
    sleep(50)
