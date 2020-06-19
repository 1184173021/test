#ifndef __LED_H__
#define __LED_H__
#include "N76E003.h"
#include "SFR_Macro.h"
#include "Function_define.h"
#include "Common.h"

void LED_init(void);
void led_glint(void);

void led_dispose(uint8_t led_bit);
void charging_mode(void);
#endif