/********************************** (C) COPYRIGHT *******************************
 * File Name          : Main.c
 * Author             : WCH
 * Version            : V1.1
 * Date               : 2022/01/25
 * Description        : 模拟USB复合设备，键鼠，支持类命令
 * Copyright (c) 2021 Nanjing Qinheng Microelectronics Co., Ltd.
 * SPDX-License-Identifier: Apache-2.0
 *******************************************************************************/

#include "CH57x_common.h"
#include "lcd.h"

uint16_t RoughCalib_Value;
/*********************************************************************
 * @fn      DebugInit
 *
 * @brief   调试初始化
 *
 * @return  none
 */
void DebugInit(void)
{
    GPIOA_SetBits(GPIO_Pin_9);
    GPIOA_ModeCfg(GPIO_Pin_8, GPIO_ModeIN_PU);
    GPIOA_ModeCfg(GPIO_Pin_9, GPIO_ModeOut_PP_5mA);
    UART1_DefInit();

    GPIOA_ModeCfg(GPIO_Pin_4, GPIO_ModeIN_Floating);
    ADC_ExtSingleChSampInit(SampleFreq_3_2, ADC_PGA_0);
    RoughCalib_Value = ADC_DataCalib_Rough(); // 用于计算ADC内部偏差，记录到全局变量 RoughCalib_Value中
    ADC_ChannelCfg(0);

    GPIOB_SetBits(GPIO_Pin_22);
    GPIOB_ModeCfg(GPIO_Pin_22, GPIO_ModeIN_PU);
}

/*********************************************************************
 * @fn      main
 *
 * @brief   主函数
 *
 * @return  none
 */
int main()
{
    int del = 0;
    int i;
    SetSysClock(CLK_SOURCE_PLL_60MHz);

    DebugInit();
    printf("start\n");

    LCD_Init();
    LCD_Fill(0, 0, 240, 240, BLACK);

    LCD_ShowString(0, 0, "Speaker Engine V1.5", 16, RED);
    show_str(0, 16, "Hello 固件升级", 16, BLUE);
    LCD_BLK_Set();//打开背光

    while(1)
    {
        DelayMs(20);
        if(GPIOB_ReadPortPin(GPIO_Pin_22) == 0x00)
        {
            LCD_ShowString(0, 16, "Key0 down", 12, RED);
        }
    }
}

