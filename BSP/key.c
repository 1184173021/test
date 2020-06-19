#include "header.h"



static xdata uint8_t brush_start;//开始刷牙

KEY key;//按键状态

void EXT_INT0(void) interrupt 0
{   
    Timer1_Delay10ms(10);
    key.key_time++;
    if (key.key_time == LONG_PRESS_TIME)//长按超时
    {
        printf("long\n");
        key.long_press = true;
        key.key_time = 0;
    }
    if(P30 == 1 )
    {
        if (key.long_press == false)
        {
            printf("down \n");
            key.short_press = true;
        }
        else
        {
           key.long_press = false; 
        }
         key.key_time = 0; 
    }  
    //set_PD; //休眠
}

/*****************************************************
*函数功能：初始化外部中断
*输入参数：NULL
*返 回 值：NULL
*****************************************************/
void exti0_init(void)
{
	P30_PushPull_Mode;
	clr_IT0;
    //set_EPI;							// Enable pin interrupt
	set_EX0;
    set_EA;								// global enable bit
}


void PinInterrupt_ISR (void) interrupt 7
{
    if(PIF == 0x01)				//管脚0中断
    {
        PIF &= ~(1 << 0);
        printf("pin0 \n");
    }
    else if(PIF == 0x02 )
    {
        PIF  &= ~(1 << 1);
        printf("pin1 \n");
    }
    else if(PIF == 0x04)
    {
        PIF  &= ~(1 << 2);
        printf("pin2 \n");
    }
    else if(PIF == 0x08)
    {
        PIF  &= ~(1 << 3);
        printf("pin3 \n");
    }
}

/*****************************************************
*函数功能：key初始化
*输入参数：NULL
*返 回 值：NULL
*****************************************************/
void key_init(void)
{
    //上升沿触发 设置为高阻输入 施密特触发输入 加上下拉电阻能增加抗干扰能力 但是高电平也会触发中断
    P00_Input_Mode;			    //P0.0上升沿触发
    set_P0S_0;					//设置施密特触发输入  增加抗干扰能力
    Enable_INT_Port0;
    Enable_BIT0_RasingEdge_Trig;

    set_EPI;					//引脚中断使能
    set_EA;						//开启总中断					
}

//按键处理函数
void key_dispose(void)
{
    if (key.short_press == true)
        brush_start = true;

    if (brush_start == true)//开始刷牙
    {
        key.brush_timer++;
        if (key.short_press == true)//
        {
            key.short_press = false; 
            if (key.brush_timer < MODE_SWITCH_TIME)//开启2S内切换模式
            {
                if (key.work_mode == CLOSE && key.gear_memory !=0)
                {
                   key.work_mode = key.gear_memory;//档位恢复
                }
                else
                    key.work_mode++;
                    
                if (key.work_mode == 5)
                {
                    key.gear_memory = WHITEN_ONE;//如果没有会导致卡死在四档
                    key.work_mode = CLOSE;
                    printf("close1\n");
                    brush_start = false;//刷牙结束
                }
                key.brush_timer = 0;
                key.short_press = false;
                printf("cut\n");
            }
            else if (key.brush_timer < BRUSH_FINISH_TIME)//开启大于2s，小于120S进行关闭
            {
                key.gear_memory = key.work_mode;//档位保存
                key.work_mode = CLOSE;
                printf("close2\n");
                brush_start = false;//刷牙结束 
                key.brush_timer = 0;          
            }          
        }       
       if(key.brush_timer == BRUSH_FINISH_TIME) //120S结束后关机
        {
            key.gear_memory = key.work_mode;//档位保存
            key.work_mode = CLOSE;
            brush_start = false;//刷牙结束
            printf("close\n");
            key.brush_timer =0;
        }  
    }       
}

