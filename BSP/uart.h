#ifndef __UART_H__
#define __UART_H__

#include "N76E003.h"
#include "SFR_Macro.h"
#include "Function_define.h"
#include "Common.h"

#define MAX_RECEIVE_PACK   100//最大接收组

void uart_send(UINT8 *buf,UINT8 len);

void  InitialUART0_Timer3(uint32_t u32Baudrate); //Timer3 as Baudrate, SMOD=1, Prescale=0

void uart_dispose(void);

#endif