/*** 
 * @Author: Tikear
 * @Date: 2020-12-07 19:13:22
 * @LastEditTime: 2020-12-13 18:22:52
 * @FilePath: \mechanical_arm_BIT\include\ARM_controller.h
 */
/*
 * @Author: Iccccy.xie(binicey@outlook.com) 
 * @Date: 2020-11-14 17:59:11 
 * @Last Modified by:   Iccccy.xie(binicey@outlook.com) 
 * @Last Modified time: 2020-11-14 17:59:11 
 */
//设置电机引脚
#include <AccelStepper.h>
#include <servo.h>
const int enablePin = 8;
const int Stepper_x_direction = 4;
const int Stepper_x = 2;
const int Stepper_y_direction = 5;
const int Stepper_y = 3;
const int Stepper_z_direction = 6;
const int Stepper_z = 4;
const int SERVO = 9;
//外部函数声明
extern void BT_ERROR(int Error_NUM);
// 建立电机对象
AccelStepper stepperX(1, Stepper_x, Stepper_x_direction);
AccelStepper stepperY(1, Stepper_y, Stepper_y_direction);
AccelStepper stepperZ(1, Stepper_z, Stepper_z_direction);
// 控制电机引脚的初始化
void stepperStup()
{
    // 电机引脚
    pinMode(Stepper_x, OUTPUT);
    pinMode(Stepper_y, OUTPUT);
    pinMode(Stepper_z, OUTPUT);
    pinMode(Stepper_x_direction, OUTPUT);
    pinMode(Stepper_z_direction, OUTPUT);
    pinMode(Stepper_z_direction, OUTPUT);
    // 开关引脚
    pinMode(enablePin, OUTPUT);
}
//电机控制板开关
void adminControl(bool data)
{
    if (data == true)
    {
        digitalWrite(enablePin, LOW);
    }
    else
    {
        digitalWrite(enablePin, HIGH);
    }
}


// 机械臂初始位置的确定
void initPosition(int stepperNUM)
{
    switch (stepperNUM)
    {
    case 1:
        stepperX.setCurrentPosition(stepperX.currentPosition());
        break;
    case 2:
        stepperY.setCurrentPosition(stepperY.currentPosition());
        break;
    case 3:
        stepperZ.setCurrentPosition(stepperZ.currentPosition());
        break;
    case 4:
        stepperX.setCurrentPosition(stepperX.currentPosition());
        stepperY.setCurrentPosition(stepperY.currentPosition());
        stepperZ.setCurrentPosition(stepperZ.currentPosition());
    default:
        BT_ERROR(1);
        break;
    }
}
// 错误与运动检测
void ARMError()
{
    String ErrorMessage = "Invalid Argument!";
    Serial.println(ErrorMessage);
}

// 调用预设离线模式
// 离线模式参数的设定
void ARM_setted_mod(int data)
{
    Serial.println(data);
}

// 手动操控模式函数集合



//向上运动
void ARM_UP_move(int data)
{
    // 参数检验

    Serial.println(data);
}


//向下
void ARM_DOWN_move(int data)
{
    Serial.println(data);
}

//向右转动
void ARM_RIGHT_move(int data)
{
    Serial.println(data);
}


//向左转动
void ARM_LEFT_move(int data)
{
    Serial.println(data);
}
//钳爪控制函数集合
void armClaw(int data)
{   
    Servo myservo;
    int pos;
    myservo.attach(9);  // Servo对象连接在9号引脚 
    //0为张开
    //1为加紧
    if (data == 1)
    {
        Serial.println("Claw close");
        for (pos = 0; pos <= 70; pos += 5) { // 0度转到70度
        // 每一步增加1度
        myservo.write(pos);              // 告诉伺服电机达到'pos'变量的角度
        Serial.println(pos);
        delay(1000);
        }
    }
    else if (data == 0)
    {
        Serial.println("Claw open");
        for (pos = 70; pos >= 0; pos -= 5) { // 70度转到0度
        myservo.write(pos);              // 告诉伺服电机达到'pos'变量的角度
        Serial.println(pos);
        delay(1000); 
        }
    }
    else
    {
        ARMError();
    }
}
// 预设运动模式
// 对应5个位置有个参数
