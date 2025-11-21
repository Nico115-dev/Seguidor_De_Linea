from microbit import *
from keyes_mecanum_Car_V2 import *
mecanumCar = Mecanum_Car_Driver_V2()
display.off()

val_L = 0
val_C = 0
val_R = 0

Sch1 = Image("00900:""09090:""90009:""09090:""00900:")
Sch2 = Image("00000:""00900:""09990:""00900:""00000:")

while True:
    val_L = pin3.read_digital()
    val_C = pin4.read_digital()
    val_R = pin10.read_digital()
    if val_C == 0:
        if val_L == 0 and val_R == 1:
            mecanumCar.Motor_Upper_L(1, 65)
            mecanumCar.Motor_Lower_L(1, 65)
            mecanumCar.Motor_Upper_R(0, 65)
            mecanumCar.Motor_Lower_R(0, 65)
        elif val_L == 1 and val_R == 0:

            mecanumCar.Motor_Upper_L(0, 65)
            mecanumCar.Motor_Lower_L(0, 65)
            mecanumCar.Motor_Upper_R(1, 65)
            mecanumCar.Motor_Lower_R(1, 65)
        else:
            display.show(Sch1)
            display.show(Sch2)
            mecanumCar.Motor_Upper_L(0, 40)
            mecanumCar.Motor_Lower_L(0, 40)
            mecanumCar.Motor_Upper_R(0, 40)
            mecanumCar.Motor_Lower_R(0, 40)
            sleep(10)
    else :
        if val_L == 0 and val_R == 1:

            mecanumCar.Motor_Upper_L(1, 65)
            mecanumCar.Motor_Lower_L(1, 65)
            mecanumCar.Motor_Upper_R(1, 45)
            mecanumCar.Motor_Lower_R(1, 45)
        elif val_L == 1 and val_R == 0:

            mecanumCar.Motor_Upper_L(1, 45)
            mecanumCar.Motor_Lower_L(1, 45)
            mecanumCar.Motor_Upper_R(1, 80)
            mecanumCar.Motor_Lower_R(1, 80)
        else:

            mecanumCar.Motor_Upper_L(1, 70)
            mecanumCar.Motor_Lower_L(1, 70)
            mecanumCar.Motor_Upper_R(1, 70)
            mecanumCar.Motor_Lower_R(1, 70)