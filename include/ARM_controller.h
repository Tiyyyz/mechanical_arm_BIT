/*
 * @Author: Iccccy.xie(binicey@outlook.com) 
 * @Date: 2020-11-14 17:59:11 
 * @Last Modified by:   Iccccy.xie(binicey@outlook.com) 
 * @Last Modified time: 2020-11-14 17:59:11 
 */
//���õ������
#include <AccelStepper.h>
const int enablePin = 8;
const int Stepper_x_direction = 4;
const int Stepper_x = 2;
const int Stepper_y_direction = 5;
const int Stepper_y = 3;
const int Stepper_z_direction = 6;
const int Stepper_z = 4;
const int SERVO = 9;
//�ⲿ��������
extern void BT_ERROR(int Error_NUM);
// �����������
AccelStepper stepperX(1, Stepper_x, Stepper_x_direction);
AccelStepper stepperY(1, Stepper_y, Stepper_y_direction);
AccelStepper stepperZ(1, Stepper_z, Stepper_z_direction);
// ���Ƶ�����ŵĳ�ʼ��
void stepperStup()
{
    // �������
    pinMode(Stepper_x, OUTPUT);
    pinMode(Stepper_y, OUTPUT);
    pinMode(Stepper_z, OUTPUT);
    pinMode(Stepper_x_direction, OUTPUT);
    pinMode(Stepper_z_direction, OUTPUT);
    pinMode(Stepper_z_direction, OUTPUT);
    // ��������
    pinMode(enablePin, OUTPUT);
}
//������ư忪��
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


// ��е�۳�ʼλ�õ�ȷ��
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
// �������˶����
void ARMError()
{
    String ErrorMessage = "Invalid Argument!";
    Serial.println(ErrorMessage);
}

// ����Ԥ������ģʽ
// ����ģʽ�������趨
void ARM_setted_mod(int data)
{
    Serial.println(data);
}

// �ֶ��ٿ�ģʽ��������
//�����˶�
void ARM_UP_move(int data)
{
    // ��������

    Serial.println(data);
}
//����
void ARM_DOWN_move(int data)
{
    Serial.println(data);
}
//����ת��
void ARM_RIGHT_move(int data)
{
    Serial.println(data);
}
//����ת��
void ARM_LEFT_move(int data)
{
    Serial.println(data);
}
//ǯצ���ƺ�������
void armClaw(int data)
{
    //0Ϊ�ſ�
    //1Ϊ�ӽ�
    if (data == 1)
    {
        Serial.println("Claw close");
    }
    else if (data == 0)
    {
        Serial.println("Claw open");
    }
    else
    {
        ARMError();
    }
}
// Ԥ���˶�ģʽ
// ��Ӧ5��λ���и�����
