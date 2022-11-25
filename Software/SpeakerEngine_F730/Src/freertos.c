/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * File Name          : freertos.c
  * Description        : Code for freertos applications
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "FreeRTOS.h"
#include "task.h"
#include "main.h"
#include "cmsis_os.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "adc.h"
#include "spi.h"
#include "tim.h"
#include "lcd.h"

#define MOS1_SET(sta)   HAL_GPIO_WritePin(MOS1_GPIO_Port,MOS1_Pin,sta)
#define MOS2_SET(sta)   HAL_GPIO_WritePin(MOS2_GPIO_Port,MOS2_Pin,sta)

#define MOS_OFF         do{MOS1_SET(GPIO_PIN_RESET);MOS2_SET(GPIO_PIN_RESET);}while(0)
#define MOS_ON1         do{MOS2_SET(GPIO_PIN_RESET);MOS1_SET(GPIO_PIN_SET);}while(0)
#define MOS_ON2         do{MOS1_SET(GPIO_PIN_RESET);MOS2_SET(GPIO_PIN_SET);}while(0)

uint16_t adc_data[200];
__IO uint8_t  adc_cmp_flag = 0;
__IO uint16_t adc_avg[240];
__IO uint8_t  adc_pos = 0;
__IO int16_t  adc_calc = 0;
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN Variables */

/* USER CODE END Variables */
osThreadId defaultTaskHandle;
osThreadId myTaskLCDHandle;
osThreadId myTaskADCHandle;
osMessageQId myQueue01Handle;
osMessageQId myQueue02Handle;

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN FunctionPrototypes */

/* USER CODE END FunctionPrototypes */

void StartDefaultTask(void const * argument);
void StartTaskLCD(void const * argument);
void StartTaskADC(void const * argument);

void MX_FREERTOS_Init(void); /* (MISRA C 2004 rule 8.1) */

/* GetIdleTaskMemory prototype (linked to static allocation support) */
void vApplicationGetIdleTaskMemory( StaticTask_t **ppxIdleTaskTCBBuffer, StackType_t **ppxIdleTaskStackBuffer, uint32_t *pulIdleTaskStackSize );

/* USER CODE BEGIN GET_IDLE_TASK_MEMORY */
static StaticTask_t xIdleTaskTCBBuffer;
static StackType_t xIdleStack[configMINIMAL_STACK_SIZE];

void vApplicationGetIdleTaskMemory( StaticTask_t **ppxIdleTaskTCBBuffer, StackType_t **ppxIdleTaskStackBuffer, uint32_t *pulIdleTaskStackSize )
{
    *ppxIdleTaskTCBBuffer = &xIdleTaskTCBBuffer;
    *ppxIdleTaskStackBuffer = &xIdleStack[0];
    *pulIdleTaskStackSize = configMINIMAL_STACK_SIZE;
    /* place for user code */
}
/* USER CODE END GET_IDLE_TASK_MEMORY */

/**
  * @brief  FreeRTOS initialization
  * @param  None
  * @retval None
  */
void MX_FREERTOS_Init(void) {
  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* USER CODE BEGIN RTOS_MUTEX */
    /* add mutexes, ... */
  /* USER CODE END RTOS_MUTEX */

  /* USER CODE BEGIN RTOS_SEMAPHORES */
    /* add semaphores, ... */
  /* USER CODE END RTOS_SEMAPHORES */

  /* USER CODE BEGIN RTOS_TIMERS */
    /* start timers, add new ones, ... */
  /* USER CODE END RTOS_TIMERS */

  /* Create the queue(s) */
  /* definition and creation of myQueue01 */
  osMessageQDef(myQueue01, 64, uint16_t);
  myQueue01Handle = osMessageCreate(osMessageQ(myQueue01), NULL);

  /* definition and creation of myQueue02 */
  osMessageQDef(myQueue02, 32, uint16_t);
  myQueue02Handle = osMessageCreate(osMessageQ(myQueue02), NULL);

  /* USER CODE BEGIN RTOS_QUEUES */
    /* add queues, ... */
  /* USER CODE END RTOS_QUEUES */

  /* Create the thread(s) */
  /* definition and creation of defaultTask */
  osThreadDef(defaultTask, StartDefaultTask, osPriorityNormal, 0, 64);
  defaultTaskHandle = osThreadCreate(osThread(defaultTask), NULL);

  /* definition and creation of myTaskLCD */
  osThreadDef(myTaskLCD, StartTaskLCD, osPriorityNormal, 0, 512);
  myTaskLCDHandle = osThreadCreate(osThread(myTaskLCD), NULL);

  /* definition and creation of myTaskADC */
  osThreadDef(myTaskADC, StartTaskADC, osPriorityHigh, 0, 256);
  myTaskADCHandle = osThreadCreate(osThread(myTaskADC), NULL);

  /* USER CODE BEGIN RTOS_THREADS */
    /* add threads, ... */
  /* USER CODE END RTOS_THREADS */

}

/* USER CODE BEGIN Header_StartDefaultTask */
/**
  * @brief  Function implementing the defaultTask thread.
  * @param  argument: Not used
  * @retval None
  */
/* USER CODE END Header_StartDefaultTask */
void StartDefaultTask(void const * argument)
{
  /* USER CODE BEGIN StartDefaultTask */
    /* Infinite loop */
    if(0)
    {
        MOS_OFF;
        MOS_ON1;//PULL DOWN
        osDelay(100);
        MOS_ON2;//PULL UP
        osDelay(100);
        MOS_OFF;
    }
    for(;;)
    {
        osDelay(100);
    }
  /* USER CODE END StartDefaultTask */
}

/* USER CODE BEGIN Header_StartTaskLCD */
/**
* @brief Function implementing the myTaskLCD thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartTaskLCD */
void StartTaskLCD(void const * argument)
{
  /* USER CODE BEGIN StartTaskLCD */
    #define SCALE 5
    uint8_t i;
    uint32_t NotifyValue;
    uint16_t adcbuf[200];
    char buf[128];
    LCD_Init();
    LCD_Fill(0, 0, 240, 240, BLACK);
    HAL_TIM_PWM_Start(&htim2,TIM_CHANNEL_3);
    __HAL_TIM_SetCompare(&htim2,TIM_CHANNEL_3,720);
    LCD_ShowString(0, 0, "Hello World", 12, RED);
    show_str(0, 16, "Hello ¹Ì¼þÉý¼¶", 16, RED);
    /* Infinite loop */
    for(;;)
    {
//        NotifyValue=ulTaskNotifyTake(pdFALSE,portMAX_DELAY);
//        if(NotifyValue > 1)
//        {
//            LCD_Fill(0, 0, 240, 240, BLACK);
//            for(i=0;i<240-1;i++)
//            {
//                LCD_DrawLine(i,240-(adc_avg[i] / SCALE)%240,i + 1,240-(adc_avg[i + 1] / SCALE)%240,RED);
//            }
//            for(i=0;i<200-1;i++)
//            {
//                LCD_DrawLine(i,adcbuf[i]   / 20,i + 1,adcbuf[i + 1]   / 20,BLACK);
//                LCD_DrawLine(i,adc_data[i] / 20,i + 1,adc_data[i + 1] / 20,RED);
//                //printf("%d,%d,%d,%d\r\n",adcbuf[i] / 20,adcbuf[i + 1] / 20,\
//                //adc_data[i] / 20,adc_data[i + 1] / 20);
//                adcbuf[i] = adc_data[i];
//            }
//        }
        NotifyValue=ulTaskNotifyTake(pdTRUE,5);
        if(NotifyValue>0)
        {
            uint32_t sum=0;
            for(i=0;i<50;i++)
            {
                sum += adc_avg[i + 50];
            }
            sum /= 50;
            sprintf(buf,"Init ADC:%5d,%7d",sum,HAL_GetTick()/100);
            show_str(0, 48, buf, 16, RED);
        }
        sprintf(buf,"Calc:%6d  ",adc_calc);
        show_str(0, 64, buf, 16, BLUE);
        
        osDelay(5);
        if(0)
        {
            LCD_Fill(0,32,120,48,BLACK);
            sprintf(buf,"Cnt:%d",NotifyValue);
            show_str(0, 32, buf, 16, RED);
            osDelay(50);
            if(NotifyValue == 5)
                osDelay(500);
        }
    }
  /* USER CODE END StartTaskLCD */
}

/* USER CODE BEGIN Header_StartTaskADC */
/**
* @brief Function implementing the myTaskADC thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartTaskADC */
void StartTaskADC(void const * argument)
{
  /* USER CODE BEGIN StartTaskADC */
    HAL_ADC_Start_DMA(&hadc1,(uint32_t *)adc_data,200);
    BaseType_t err;
    int i;
    uint8_t adc_zero_flag = 0;
    int16_t data_change = 0;
    uint16_t adc_last = 0;
    /* Infinite loop */
    for(;;)
    {
        if(adc_cmp_flag == 1)
        {
            adc_cmp_flag = 0;
            uint32_t sum = 0;
            for(i=0;i<200;i++)
            {
                sum += adc_data[i];
            }
            sum /= 200;
            adc_avg[adc_pos] = sum;
            
            
            if(adc_zero_flag == 1)
            {
                data_change += (sum - adc_last);
                adc_last = sum;
                adc_calc = data_change;
                if(adc_calc > 5)
                {
                    MOS_ON2;//PULL UP
                }
                else
                {
                    MOS_OFF;
                }
            }
            
            adc_pos ++;
            if(adc_pos >= 240)
            {
                adc_pos = 0;
                if(adc_zero_flag == 0)
                {
                    adc_zero_flag = 1;
                    adc_last = sum;
                }
                xTaskNotifyGive(myTaskLCDHandle);
            }
            //HAL_ADC_Start_DMA(&hadc1,(uint32_t *)adc_data,200);
        }
        osDelay(1);
    }
  /* USER CODE END StartTaskADC */
}

/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */
void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef* hadc)
{
    if(adc_cmp_flag == 0)adc_cmp_flag = 1;
    //HAL_ADC_Start_DMA(&hadc1,(uint32_t *)adc_data,200);
}
/* USER CODE END Application */

