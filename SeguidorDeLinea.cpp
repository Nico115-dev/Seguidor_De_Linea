from microbit import *
from keyes_mecanum_Car_V2 import *
mecanumCar = Mecanum_Car_Driver_V2()
display.off()

Left = 0
Center = 0
Right = 0

// 0 → Está sobre la línea negra

// 1 → Está sobre el piso claro
while True:
    Left = pin3.read_digital()
    Center = pin4.read_digital()
    Right = pin10.read_digital()
    if Center == 0:
        if Left == 0 and Right == 1:
            mecanumCar.Motor_Upper_L(1, 65)  //Si es 0 va en reversa, si es 1 va hacia delante
            mecanumCar.Motor_Lower_L(1, 65)  
            mecanumCar.Motor_Upper_R(0, 65)
            mecanumCar.Motor_Lower_R(0, 65)

        elif Left == 1 and Right == 0:

            mecanumCar.Motor_Upper_L(0, 65)
            mecanumCar.Motor_Lower_L(0, 65)
            mecanumCar.Motor_Upper_R(1, 65)
            mecanumCar.Motor_Lower_R(1, 65)

        else:

            mecanumCar.Motor_Upper_L(0, 40)
            mecanumCar.Motor_Lower_L(0, 40)
            mecanumCar.Motor_Upper_R(0, 40)
            mecanumCar.Motor_Lower_R(0, 40)
            sleep(10)
    else :
        if Left == 0 and Right == 1:

            mecanumCar.Motor_Upper_L(1, 65)
            mecanumCar.Motor_Lower_L(1, 65)
            mecanumCar.Motor_Upper_R(1, 45)
            mecanumCar.Motor_Lower_R(1, 45)
            
        elif Left == 1 and Right == 0:

            mecanumCar.Motor_Upper_L(1, 45)
            mecanumCar.Motor_Lower_L(1, 45)
            mecanumCar.Motor_Upper_R(1, 80)
            mecanumCar.Motor_Lower_R(1, 80)
        else:

            mecanumCar.Motor_Upper_L(1, 70)
            mecanumCar.Motor_Lower_L(1, 70)
            mecanumCar.Motor_Upper_R(1, 70)
            mecanumCar.Motor_Lower_R(1, 70)