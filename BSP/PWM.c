#include "header.h"


void PWM_DEAD_TIME_VALUE(UINT16	DeadTimeData)
{
	UINT8 deadtmphigh,deadtmplow;
	deadtmplow = DeadTimeData;
	deadtmphigh = DeadTimeData>>8;
	BIT_TMP = EA;
	if (deadtmphigh==0x01)
	{
		EA = 0;
		TA = 0xAA;
		TA = 0x55;
		PDTEN|=0x10;
	}
	TA = 0xAA;
	TA = 0x55;
	PDTCNT = deadtmplow;
	EA = BIT_TMP;
}

/*****************************************************
*函数功能：PWM初始化
*输入参数：NULL
*返 回 值：NULL
*****************************************************/
//uint8_t count8[10]; 
void pwm_init(void)
{
     Set_All_GPIO_Quasi_Mode;
    PWM4_P01_OUTPUT_ENABLE;
    PWM5_P15_OUTPUT_ENABLE;  

    PWM_COMPLEMENTARY_MODE;					//Only this mode support deat time function
    PWM_CLOCK_DIV_8;
    PWMPH = 0x07;
	PWMPL = 0xCF;

    set_SFRPAGE;										// PWM4 and PWM5 duty value need set SFPPAGE 1
    PWM4H = 0x01;
    PWM4L = 0xCF;
    PWM45_DEADTIME_ENABLE;
    PWM_DEAD_TIME_VALUE(0x1FF);			//value never over 0x1FF
    clr_SFRPAGE;
    //Please always setting Dead time if needed before PWM run.		
    set_LOAD;
    set_PWMRUN;
}
/*****************************************************
*函数功能：PWM模式改变
*输入参数：1.清洁模式，2.美白模式，3.敏感模式 4.停机模式
*返 回 值：TRUE 成功， FASLE 失败
*****************************************************/
void pwm_change_mode(void)
{

}