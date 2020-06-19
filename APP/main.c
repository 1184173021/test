#include "header.h"

#define TH0_INIT        50000 
#define TL0_INIT        50000
#define TH1_INIT        50000 
#define TL1_INIT        50000

UINT8 u8TH0_Tmp,u8TL0_Tmp,u8TH1_Tmp,u8TL1_Tmp;
/************************************************************************************************************
*    TIMER 0 interrupt subroutine
************************************************************************************************************/
void Timer0_ISR (void) interrupt 1  //interrupt address is 0x000B
{
    TH0 = u8TH0_Tmp;
    TL0 = u8TL0_Tmp;    
    
    P12 = ~P12;                     // GPIO1 toggle when interrupt
}

/************************************************************************************************************
*    TIMER 1 interrupt subroutine
************************************************************************************************************/
void Timer1_ISR (void) interrupt 3  //interrupt address is 0x001B
{
    TH1 = u8TH1_Tmp;
    TL1 = u8TL1_Tmp;   

    P03 = ~P03;                     //P0.3 toggle when interrupt
}
void Timer_init(void) 
{
    Set_All_GPIO_Quasi_Mode;
        TIMER0_MODE1_ENABLE;
        TIMER1_MODE1_ENABLE;

    clr_T1M;
    //set_T1M;

    u8TH0_Tmp = (6536-TH0_INIT)/256;
    u8TL0_Tmp = (65536-TL0_INIT)%256;    
    u8TH1_Tmp = (65536-TH1_INIT)/256;
    u8TL1_Tmp = (65536-TL1_INIT)%256;
    
    TH0 = u8TH0_Tmp;
    TL0 = u8TL0_Tmp;
    TH1 = u8TH1_Tmp;
    TL1 = u8TL1_Tmp;
    
    set_ET0;                                    //enable Timer0 interrupt
    set_ET1;                                    //enable Timer1 interrupt
    set_EA;                                     //enable interrupts
    set_TR0;                                    //Timer0 run
    set_TR1;                                    //Timer1 run
}

void main(void)
{
	uint8_t i = 0;

	InitialUART0_Timer3(9600);
	Timer_init();
	//LED_init();
	//key_init();
	exti0_init();
	//pwm_init();
	//exti1_init();
	printf("xti\n");
	while (1)
	{
		//Timer0_Delay1ms(10);
		//led_glint();
	//key_dispose();
		//charging_mode();
		//proces_mode();
	}
}
