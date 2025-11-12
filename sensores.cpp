from microbit import *

left_sensor = pin3
middle_sensor = pin4
right_sensor = pin10

while True:
    left_val = left_sensor.read_digital()
    middle_val = middle_sensor.read_digital()
    right_val = right_sensor.read_digital()
    
    display.scroll("L{} M{} R{}".format(left_val, middle_val, right_val))
    sleep(500)
