/*** 
 * @Author: Tikear
 * @Date: 2020-12-07 19:13:22
 * @LastEditTime: 2020-12-13 18:45:53
 * @FilePath: \mechanical_arm_BIT\include\ARM_controller.h
 */
/*** 
 * @Author: Iccccy.xie
 * @Date: 2020-11-14 16:00:26
 * @LastEditTime: 2020-12-12 23:40:56
 * @LastEditors: Please set LastEditors
 * @FilePath: \Mechanical _Arm\include\ARM_controller.h
 */
//设置电机引脚
#include <AccelStepper.h>
#include <servo.h>
const int enablePin = 8;
//x与y电机加有减速器减速比1：20
const int stepper_de = 20;
const int Stepper_x_direction = 10;
const int Stepper_x = 8;
const int Stepper_y_direction = 0;
const int Stepper_y = 0;
//z电机为带轮减速，减速比为1：4
const int stepper_de_z = 0;
const int Stepper_z_direction = 0;
const int Stepper_z = 0;
const int SERVO = 0;
//外部函数声明
extern void BT_ERROR(int Error_NUM);
// 建立电机对象
AccelStepper stepperX(8, 8, 10, 9, 11);
// AccelStepper stepperX(8, Stepper_x, Stepper_x_direction);
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
void initPosition(int stepperNUM, int data)
{
    if (data == -1)
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
    else
    {
        switch (stepperNUM)
        {
        case 1:
            stepperX.setCurrentPosition(data);
            break;
        case 2:
            stepperY.setCurrentPosition(data);
            break;
        case 3:
            stepperZ.setCurrentPosition(data);
            break;
        case 4:
            stepperX.setCurrentPosition(data);
            stepperY.setCurrentPosition(data);
            stepperZ.setCurrentPosition(data);
        default:
            BT_ERROR(1);
            break;
        }
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
void ARM_setted_mod()
{
    Serial.println(data);
    //参数与步骤输入
    int commend[1] = {};
    int data[1] = {};
    int time[1] = {};
    //x,y,z分别对应三个电机的旋转输入参数为转角
    // 正数为正转，负数为逆转（考虑坐标系参数输入）
    // k为夹爪控制命令
    // 1为加紧，0为松开

    for (int i = 0; i < sizeof(commend) / sizeof(int); i++)
    {
        switch (commend[i])
        {
        case 'x':
            /* code */
            break;
        case 'y':
            /* code */
            break;
        case 'z':
            /* code */
            break;
        case 'k':
            /* code */
            break;
        default:
            ARMError();
            break;
        }
    }
}

// 手动操控模式函数集合列举
// moveto(绝对位置)
// move(相对位置)
// setMaxSpeed(speed)
// 上述speed单位是步/分钟
// targetPosition()
// distanceToGo()

//前后运动
void ARM_ForwordAndBack_move(int data)
{
    int One_step = 10;
    if (data == 0)
    {
        int step = stepperX.currentPosition() + One_step;
        Serial.println(stepperX.currentPosition());
        stepperX.setAcceleration(500.0);
        stepperX.setSpeed(000.0);
        while (stepperX.currentPosition() != step)
        {
            // Serial.println(stepperX.currentPosition());
            stepperX.runSpeed();
        }
        Serial.println(stepperX.currentPosition());
    }
    else if (data == 1)
    {
        int step = stepperX.currentPosition() - One_step;
        Serial.println(stepperX.currentPosition());
        stepperX.setAcceleration(500.0);
        stepperX.setSpeed(000.0);
        while (stepperX.currentPosition() != step)
        {
            // Serial.println(stepperX.currentPosition());
            stepperX.runSpeed();
        }
        Serial.println(stepperX.currentPosition());
    }
    else
    {
        ARMError();
    }
}
//上下运动
void ARM_UpAndDown_move(int data)
{
    Serial.println(data);
    int One_step = 10;
    if (data == 0)
    {
        int step = stepperY.currentPosition() + One_step;
        Serial.println(stepperY.currentPosition());
        stepperY.setAcceleration(500.0);
        stepperY.setSpeed(000.0);
        while (stepperY.currentPosition() != step)
        {
            // Serial.println(stepperY.currentPosition());
            stepperY.runSpeed();
        }
        Serial.println(stepperY.currentPosition());
    }
    else if (data == 1)
    {
        int step = stepperY.currentPosition() - One_step;
        Serial.println(stepperY.currentPosition());
        stepperY.setAcceleration(500.0);
        stepperY.setSpeed(000.0);
        while (stepperY.currentPosition() != step)
        {
            // Serial.println(stepperY.currentPosition());
            stepperY.runSpeed();
        }
        Serial.println(stepperY.currentPosition());
    }
    else
    {
        ARMError();
    }
}
//左右转动
void ARM_RightAndLeft_move(int data)
{

    // 参数检验
    Serial.println(data);
    int One_step = 10;
    if (data == 0)
    {
        int step = stepperZ.currentPosition() + One_step;
        Serial.println(stepperZ.currentPosition());
        stepperZ.setAcceleration(500.0);
        stepperZ.setSpeed(000.0);
        while (stepperZ.currentPosition() != step)
        {
            // Serial.println(stepperZ.currentPosition());
            stepperZ.runSpeed();
        }
        Serial.println(stepperZ.currentPosition());
    }
    else if (data == 1)
    {
        int step = stepperZ.currentPosition() - One_step;
        Serial.println(stepperZ.currentPosition());
        stepperZ.setAcceleration(500.0);
        stepperZ.setSpeed(000.0);
        while (stepperZ.currentPosition() != step)
        {
            // Serial.println(stepperZ.currentPosition());
            stepperZ.runSpeed();
        }
        Serial.println(stepperZ.currentPosition());
    }
    else
    {
        ARMError();
    }
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