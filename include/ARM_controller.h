/*
 * @Author: Iccccy.xie(binicey@outlook.com) 
 * @Date: 2020-11-14 17:59:11 
 * @Last Modified by:   Iccccy.xie(binicey@outlook.com) 
 * @Last Modified time: 2020-11-14 17:59:11 
 */
//���õ������
int SEPPER_X = 1;
int SEPPER_F = 2;
int STPPER_W = 3;
int SERVO = 4;
// ��е�۳�ʼλ�õ�ȷ��

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
