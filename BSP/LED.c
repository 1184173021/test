#include "header.h"

UINT8 count_time;
UINT8 count_time1;
static uint16_t xdata charging_time=0;

void led_charging(uint8_t led_bit);
/*****************************************************
*函数功能：初始化LED
*输入参数：NULL
*返 回 值：NULL
*****************************************************/
void LED_init(void)
{
	P12_PushPull_Mode;
	
	P10_PushPull_Mode;
	//P01_PushPull_Mode;
	P03_PushPull_Mode;
	P04_PushPull_Mode;

  P10 = 1;
  //P01 = 1;
  P03 = 1;
  P04 = 1;
}
/*****************************************************
*函数功能：LED灯闪烁
*输入参数：NULL
*返 回 值：NULL
*****************************************************/
void led_glint(void)
{
    count_time++;
    if (count_time == 5)
    {
      P12 = 0;
			
			// P10 = 0;
			// P01 = 0;
			// P04 = 0;
			// P03 = 0;
    }
    if (count_time == 10)
    {
      P12 = 1;
			
			// P10 = 1;
			// P01 = 1;
			// P03 = 1;
			// P04 = 1;
      count_time = 0;
      //count_time1++;
      //set_PD;// 进入掉电模式
    } 
    if (count_time1 == 10)
    {
      set_PD;// 进入掉电模式
     // count_time1 =0;
    }
    
}

//充电模式下LED闪烁
void charging_mode(void)
{
  charging_time++;
  if (charging_time == 10)
  {
    led_charging(1);
  }
  else if (charging_time == 20)
  {
    led_charging(2);
  }
  else if (charging_time == 30)
  {
    led_charging(3);
  }  
  else if (charging_time == 40)
  {
    led_charging(4);
  } 
  else if (charging_time == 50)
  {
    led_charging(0);
    charging_time = 0;
  } 
}

//充电时LED闪烁
void led_charging(uint8_t led_bit)
{
  if (led_bit == 0)
  {
    P04 = 1;
    P03 = 1;
   // P01 = 1;
    P10 = 1;    
  }
  else if (led_bit ==1)
  {
    P04 = 1;
    P03 = 1;
   // P01 = 1;
    P10 = 0;  
  }
  else if (led_bit ==2)
  {
    P04 = 1;
    P03 = 1;
    //P01 = 0;
    P10 = 0;  
  } 
  else if (led_bit ==3)
  {
    P04 = 1;
    P03 = 0;
   //P01 = 0;
    P10 = 0;  
  }   
    else if (led_bit ==4)
  {
    P04 = 0;
    P03 = 0;
    //P01 = 0;
    P10 = 0;  
  } 
}

//处理模式LED闪烁
void led_dispose(uint8_t led_bit)
{
  if (led_bit == 0)
  {
    P04 = 1;
    P03 = 1;
   // P01 = 1;
    P10 = 1;    
  }
  else if (led_bit ==1)
  {
    P04 = 1;
    P03 = 1;
   // P01 = 1;
    P10 = 0;  
  }
  else if (led_bit ==2)
  {
    P04 = 1;
    P03 = 1;
    //P01 = 0;
    P10 = 1;  
  } 
  else if (led_bit ==3)
  {
    P04 = 1;
    P03 = 0;
    //P01 = 1;
    P10 = 1;  
  }   
    else if (led_bit ==4)
  {
    P04 = 0;
    P03 = 1;
   // P01 = 1;
    P10 = 1;  
  } 
}
