from machine import Pin,PWM
import time

#L293D对应引脚，设为输出 
IN1_Pin = 2
IN2_Pin = 15
ENA_Pin = 0 #控制电机的速度

# speed：速度为0 - 100
# direction:旋转方向，1为顺时针，0为停止，-1为逆时针
# speed_pin:控制电机启动和停止的引脚编号
def motorRun(speed, direction, speed_pin, clockwise_pin, anti_clockwise_pin):
    if speed > 100: speed=100
    if speed < 0: speed=0
    in1 = Pin(anti_clockwise_pin, Pin.OUT)
    in2 = Pin(clockwise_pin, Pin.OUT)
    pwm = PWM(Pin(speed_pin))
    pwm.freq(50)
    pwm.duty(int(speed/100*1023))
    if direction < 0:
        in2.value(0)
        in1.value(1)
    if direction == 0:
        in2.value(0)
        in1.value(0)
    if direction > 0:
        in2.value(1)
        in1.value(0)

while True:
    motorRun(100, 1, ENA_Pin, IN2_Pin, IN1_Pin)
    time.sleep(5)
    motorRun(100, 0, ENA_Pin, IN2_Pin, IN1_Pin)
    time.sleep(2)
    motorRun(100, -1, ENA_Pin, IN2_Pin, IN1_Pin)
    time.sleep(5)
    motorRun(100, 0, ENA_Pin, IN2_Pin, IN1_Pin)
    time.sleep(2)