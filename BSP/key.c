#include "header.h"



static xdata uint8_t brush_start;//��ʼˢ��

KEY key;//����״̬

void EXT_INT0(void) interrupt 0
{   
    Timer1_Delay10ms(10);
    key.key_time++;
    if (key.key_time == LONG_PRESS_TIME)//������ʱ
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
    //set_PD; //����
}

/*****************************************************
*�������ܣ���ʼ���ⲿ�ж�
*���������NULL
*�� �� ֵ��NULL
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
    if(PIF == 0x01)				//�ܽ�0�ж�
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
*�������ܣ�key��ʼ��
*���������NULL
*�� �� ֵ��NULL
*****************************************************/
void key_init(void)
{
    //�����ش��� ����Ϊ�������� ʩ���ش������� �����������������ӿ��������� ���Ǹߵ�ƽҲ�ᴥ���ж�
    P00_Input_Mode;			    //P0.0�����ش���
    set_P0S_0;					//����ʩ���ش�������  ���ӿ���������
    Enable_INT_Port0;
    Enable_BIT0_RasingEdge_Trig;

    set_EPI;					//�����ж�ʹ��
    set_EA;						//�������ж�					
}

//����������
void key_dispose(void)
{
    if (key.short_press == true)
        brush_start = true;

    if (brush_start == true)//��ʼˢ��
    {
        key.brush_timer++;
        if (key.short_press == true)//
        {
            key.short_press = false; 
            if (key.brush_timer < MODE_SWITCH_TIME)//����2S���л�ģʽ
            {
                if (key.work_mode == CLOSE && key.gear_memory !=0)
                {
                   key.work_mode = key.gear_memory;//��λ�ָ�
                }
                else
                    key.work_mode++;
                    
                if (key.work_mode == 5)
                {
                    key.gear_memory = WHITEN_ONE;//���û�лᵼ�¿������ĵ�
                    key.work_mode = CLOSE;
                    printf("close1\n");
                    brush_start = false;//ˢ������
                }
                key.brush_timer = 0;
                key.short_press = false;
                printf("cut\n");
            }
            else if (key.brush_timer < BRUSH_FINISH_TIME)//��������2s��С��120S���йر�
            {
                key.gear_memory = key.work_mode;//��λ����
                key.work_mode = CLOSE;
                printf("close2\n");
                brush_start = false;//ˢ������ 
                key.brush_timer = 0;          
            }          
        }       
       if(key.brush_timer == BRUSH_FINISH_TIME) //120S������ػ�
        {
            key.gear_memory = key.work_mode;//��λ����
            key.work_mode = CLOSE;
            brush_start = false;//ˢ������
            printf("close\n");
            key.brush_timer =0;
        }  
    }       
}

