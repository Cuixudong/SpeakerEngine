/*
 * lcd.h
 *
 *  Created on: Mar 10, 2022
 *      Author: 27731
 */

#ifndef USER_LCD_H_
#define USER_LCD_H_

#include <stdint.h>

#define USE_HORIZONTAL 3  //���ú�������������ʾ 0��1Ϊ���� 2��3Ϊ����
#if USE_HORIZONTAL==0||USE_HORIZONTAL==1
#define LCD_W 80
#define LCD_H 160
#else
#define LCD_W 160
#define LCD_H 80
#endif

#define WHITE           0xFFFF
#define BLACK           0x0000
#define BLUE            0x001F
#define BRED            0XF81F
#define GRED            0XFFE0
#define GBLUE           0X07FF
#define RED             0xF800
#define MAGENTA         0xF81F
#define GREEN           0x07E0
#define CYAN            0x7FFF
#define YELLOW          0xFFE0
#define BROWN           0XBC40 //��ɫ
#define BRRED           0XFC07 //�غ�ɫ
#define GRAY            0X8430 //��ɫ
#define DARKBLUE        0X01CF //����ɫ
#define LIGHTBLUE       0X7D7C //ǳ��ɫ
#define GRAYBLUE        0X5458 //����ɫ
#define LIGHTGREEN      0X841F //ǳ��ɫ
#define LGRAY           0XC618 //ǳ��ɫ(PANNEL),���屳��ɫ
#define LGRAYBLUE       0XA651 //ǳ����ɫ(�м����ɫ)
#define LBBLUE          0X2B12 //ǳ����ɫ(ѡ����Ŀ�ķ�ɫ)

#define LCD_BLK_Set()       GPIOB_SetBits(GPIO_Pin_12)
#define LCD_BLK_Clr()       GPIOB_ResetBits(GPIO_Pin_12)
#define LCD_RES_Set()       GPIOA_SetBits(GPIO_Pin_15)
#define LCD_RES_Clr()       GPIOA_ResetBits(GPIO_Pin_15)
#define LCD_CS_Set()        GPIOA_SetBits(GPIO_Pin_12)
#define LCD_CS_Clr()        GPIOA_ResetBits(GPIO_Pin_12)
#define LCD_DC_Set()        GPIOA_SetBits(GPIO_Pin_5)   //д����
#define LCD_DC_Clr()        GPIOA_ResetBits(GPIO_Pin_5) //д����

#define LCD_SCLK_Clr()      GPIOA_SetBits(GPIO_Pin_13)
#define LCD_SCLK_Set()      GPIOA_ResetBits(GPIO_Pin_13)
#define LCD_MOSI_Set()      GPIOA_SetBits(GPIO_Pin_14)
#define LCD_MOSI_Clr()      GPIOA_ResetBits(GPIO_Pin_14)

extern const uint8_t bmp_16x16_sel_ico[];

void LCD_GPIO_Init(void);//��ʼ��GPIO
void LCD_Writ_Bus(uint8_t dat);//ģ��SPIʱ��
void LCD_WR_DATA8(uint8_t dat);//д��һ���ֽ�
void LCD_WR_DATA(uint16_t dat);//д�������ֽ�
void LCD_WR_REG(uint8_t dat);//д��һ��ָ��
void LCD_Address_Set(uint16_t x1,uint16_t y1,uint16_t x2,uint16_t y2);//�������꺯��
void LCD_Init(void);//LCD��ʼ��

void LCD_Fill(uint16_t xsta,uint16_t ysta,uint16_t xend,uint16_t yend,uint16_t color);
void LCD_DrawPoint(uint16_t x,uint16_t y,uint16_t color);
void LCD_ShowChar(uint8_t x,uint8_t y,char chr,uint8_t size,uint16_t color);
uint32_t mypow(uint8_t m,uint8_t n);
void LCD_ShowNum(uint8_t x,uint8_t y,uint32_t num,uint8_t len,uint8_t size,uint16_t color);
void LCD_ShowString(uint8_t x,uint8_t y,char *p,uint8_t size,uint16_t color);
void show_str_mid(uint16_t x,uint16_t y,char *str,uint8_t f_h,uint16_t color,uint16_t len);
void LCD_showPicture(uint8_t x,uint8_t y,uint8_t *p,uint8_t p_w,uint8_t p_h,uint16_t color);
void show_str(uint16_t x,uint16_t y,char *str,uint8_t f_h,uint16_t color);

void LCD_Draw_Bitmap(int16_t x, int16_t y, uint8_t *bitmap, uint16_t p_w, uint16_t p_h,uint16_t color);
void LCD_DrawLine(int8_t x1,int8_t y1,int8_t x2,int8_t y2,uint16_t color);
void LCD_DrawCircle(int8_t x,int8_t y,uint8_t r,uint16_t color);
#endif /* USER_LCD_H_ */
