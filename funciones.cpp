from microbit import *


def forward():
    pin8.write_digital(1)
    pin12.write_digital(1)
    pin13.write_digital(0)
    pin14.write_digital(0)

def back():
    pin8.write_digital(0)
    pin12.write_digital(0)
    pin13.write_digital(1)
    pin14.write_digital(1)

def left():
    pin8.write_digital(0)
    pin12.write_digital(1)
    pin13.write_digital(1)
    pin14.write_digital(0)

def right():
    pin8.write_digital(1)
    pin12.write_digital(0)
    pin13.write_digital(0)
    pin14.write_digital(1)

def stop():
    pin8.write_digital(0)
    pin12.write_digital(0)
    pin13.write_digital(0)
    pin14.write_digital(0)

#  Prueba de movimientos
while True:
    forward()
    display.show(Image.ARROW_N)
    sleep(1000)
    
    back()
    display.show(Image.ARROW_S)
    sleep(1000)
    
    left()
    display.show(Image.ARROW_W)
    sleep(1000)
    
    right()
    display.show(Image.ARROW_E)
    sleep(1000)
    
    stop()
    display.clear()
    sleep(1000)