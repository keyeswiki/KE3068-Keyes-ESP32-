//**********************************************************************************
/*
 * 文件名  : 小风扇
 * 描述 : 小风扇逆时针旋转，停止，顺时针旋转，停止，循环。
*/
#define IN1 2  // L293D的IN1引脚
#define IN2 15  //L293D的IN2引脚
#define ENA_pwm 0  //L293D的ENA-pwm引脚
void setup()
{
pinMode(IN1,OUTPUT); //设置N1为OUTPUT
pinMode(IN2,OUTPUT); //设置N2为OUTPUT
ledcSetup(2, 1200, 8);//设置ledc通道2，频率为1200,PWM分辨率为8，占空比为256。
ledcAttachPin(0, 2); //将ledc通道2绑定到指定的ENA_pwm引脚GPIO0进行输出。
}
void loop()
{
//逆时针旋转5秒
digitalWrite(IN1,LOW);
digitalWrite(IN2,HIGH);
ledcWrite(2, 250); //ledc通道2被绑定到指定的ENA_pwm输出PWM值250。
delay(5000);
//停止 2s 
ledcWrite(2, 0); //ledc通道2被绑定到指定的ENA_pwm输出PWM值0。
delay(2000);
//顺时针旋转5秒
digitalWrite(IN1,HIGH);
digitalWrite(IN2,LOW);
ledcWrite(2, 250); //ledc通道2被绑定到指定的ENA_pwm输出PWM值250。
delay(5000);
//停止 2s
ledcWrite(2, 0); //ledc通道2被绑定到指定的ENA_pwm输出PWM值0。
delay(2000);
}
//********************************************************************************
