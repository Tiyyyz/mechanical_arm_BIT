/*** 
 * @Author: Tikear
 * @Date: 2020-12-13 18:29:14
 * @LastEditTime: 2020-12-13 18:40:08
 * @FilePath: \mechanical_arm_BIT\Arm_main.cpp
 */
#include <iostream>
#include "ARM_conreoller.h"

int main(void)
{
    BT_ERROR(int Error_NUM)//建立电机对象
    stepperStup() //建立电机引脚
    adminControl(1) //打开电机控制板开关
    initPosition(int stepperNUM, int data) //确定机械臂初始位置
    ARMError() //运动检测
    
}