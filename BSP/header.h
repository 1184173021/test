#ifndef __HEADER_H__
#define __HEADER_H__

#include "N76E003.h"
#include "SFR_Macro.h"
#include "Function_define.h"

#include "uart.h"
#include "Delay.h"
#include "PWM.h"
#include "LED.h"
#include "key.h"

#define   LONG_PRESS_TIME        12     //100ms*12   长按超时
#define   MODE_SWITCH_TIME       200    //10ms*200   前2s可以进行档位切换，按下按键后重新计算120s
#define   BRUSH_FINISH_TIME      9114  //10ms*12000 120s
   

#define   true                   1
#define   false                  0 

void proces_mode(void);

#endif