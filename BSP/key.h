#ifndef __KEY_H__
#define __KEY_H__

#include "N76E003.h"
#include "SFR_Macro.h"
#include "Function_define.h"
#include "uart.h"
#include "Delay.h"

typedef enum
{
    CLOSE = 0,      //关机模式
    WHITEN_ONE,     //清洁模式
    CLEAN_TWO,      //美白模式
    MASSAGE_THREE,  //按摩模式
    SENSITIVE_FOUR,//敏感模式     
};

typedef struct 
{
    uint8_t work_mode;//工作模式
    uint8_t gear_memory;//档位记忆
    uint8_t long_press;//按键长按
    uint8_t short_press;//按键短按
    uint8_t key_time;//按键计时
    uint16_t brush_timer;//刷牙计时 
}KEY;

extern KEY key;

void exti0_init(void);
void exti1_init(void);

void key_dispose(void);

#endif
