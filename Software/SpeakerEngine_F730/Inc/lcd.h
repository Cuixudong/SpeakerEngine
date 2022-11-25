/*
 * lcd.h
 *
 *  Created on: Mar 10, 2022
 *      Author: 27731
 */

#ifndef USER_LCD_H_
#define USER_LCD_H_

#include "main.h"

#define USE_HORIZONTAL 0  //���ú�������������ʾ 0��1Ϊ���� 2��3Ϊ����

#define LCD_W 240
#define LCD_H 240

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

#define LCD_BLK_Set()       HAL_GPIO_WritePin(LCD_BLK_GPIO_Port,LCD_BLK_Pin,GPIO_PIN_SET)
#define LCD_BLK_Clr()       HAL_GPIO_WritePin(LCD_BLK_GPIO_Port,LCD_BLK_Pin,GPIO_PIN_RESET)
#define LCD_RES_Set()       HAL_GPIO_WritePin(LCD_RST_GPIO_Port,LCD_RST_Pin,GPIO_PIN_SET)
#define LCD_RES_Clr()       HAL_GPIO_WritePin(LCD_RST_GPIO_Port,LCD_RST_Pin,GPIO_PIN_RESET)
#define LCD_CS_Set()        HAL_GPIO_WritePin(LCD_CS_GPIO_Port,LCD_CS_Pin,GPIO_PIN_SET)
#define LCD_CS_Clr()        HAL_GPIO_WritePin(LCD_CS_GPIO_Port,LCD_CS_Pin,GPIO_PIN_RESET)
#define LCD_DC_Set()        HAL_GPIO_WritePin(LCD_DC_GPIO_Port,LCD_DC_Pin,GPIO_PIN_SET)   //д����
#define LCD_DC_Clr()        HAL_GPIO_WritePin(LCD_DC_GPIO_Port,LCD_DC_Pin,GPIO_PIN_RESET) //д����

#define LCD_SCLK_Clr()      HAL_GPIO_WritePin(LCD_SCK_GPIO_Port,LCD_SCK_Pin,GPIO_PIN_RESET)
#define LCD_SCLK_Set()      HAL_GPIO_WritePin(LCD_SCK_GPIO_Port,LCD_SCK_Pin,GPIO_PIN_SET)
#define LCD_MOSI_Clr()      HAL_GPIO_WritePin(LCD_SDA_GPIO_Port,LCD_SDA_Pin,GPIO_PIN_RESET)
#define LCD_MOSI_Set()      HAL_GPIO_WritePin(LCD_SDA_GPIO_Port,LCD_SDA_Pin,GPIO_PIN_SET)

void LCD_GPIO_Init(void);//��ʼ��GPIO
void LCD_Writ_Bus(uint8_t dat);//ģ��SPIʱ��
void LCD_WR_DATA8(uint8_t dat);//д��һ���ֽ�
void LCD_WR_DATA(uint16_t dat);//д�������ֽ�
void LCD_WR_REG(uint8_t dat);//д��һ��ָ��
void LCD_Address_Set(uint16_t x1,uint16_t y1,uint16_t x2,uint16_t y2);//�������꺯��
void LCD_Init(void);//LCD��ʼ��

void LCD_Fill(uint16_t xsta,uint16_t ysta,uint16_t xend,uint16_t yend,uint16_t color);
void LCD_DrawPoint(int16_t x,int16_t y,uint16_t color);
void LCD_DrawLine(int16_t x1,int16_t y1,int16_t x2,int16_t y2,uint16_t color);
void LCD_DrawCircle(int16_t x,int16_t y,uint16_t r,uint16_t color);
void LCD_ShowChar(int16_t x,int16_t y,char chr,uint8_t size,uint16_t color);
void LCD_ShowNum(int16_t x,int16_t y,uint32_t num,uint8_t len,uint8_t size,uint16_t color);
void LCD_ShowString(int16_t x,int16_t y,char *p,uint8_t size,uint16_t color);
void show_font(int16_t x,int16_t y,const char *font,uint8_t f_w,uint8_t f_h,uint16_t color);
void show_str(int16_t x,int16_t y,char *str,uint8_t f_h,uint16_t color);
void show_str_mid(int16_t x,int16_t y,char *str,uint8_t f_h,uint16_t color,uint16_t len);
void LCD_showPicture(int16_t x,int16_t y,uint8_t *p,uint8_t p_w,uint8_t p_h,uint16_t color);
void LCD_Draw_Bitmap(int16_t x, int16_t y, uint8_t *bitmap, uint16_t p_w, uint16_t p_h,uint16_t color);
#endif /* USER_LCD_H_ */
