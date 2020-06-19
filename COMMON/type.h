/*********************************************************************************************
* Copyright (c) 2018, Vigo
* All rights reserved.
*
* File Name       : type.h
* Description     : Definition of basic types and define
* Creation By     : Thunder
* Creation Date   : 2018/10/15
* Modify By       : Thunder
* Modify Date     : 2018/10/15
* Device(s)       : SOC92F754x
*********************************************************************************************/
#ifndef __TYPE_H__
#define __TYPE_H__
/*_____________ Include Files ______________________________________________________________*/

#include <intrins.h>

/*_____________ Global Definition __________________________________________________________*/
#define _Nop() _nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_()
/*_____________ Global Types _______________________________________________________________*/

/* basic types definition */
typedef unsigned char       uint8_t;  /* unsigned byte       (1 byte ) */
typedef unsigned short int  uint16_t; /* short unsigned word (2 bytes) */
typedef unsigned long  int  uint32_t;  /* long unsigned word  (4 bytes) */
typedef signed   char       int8_t;  /* signed byte         (1 byte ) */
typedef signed   short int  int16_t; /* short signed word   (2 bytes) */
typedef signed   long  int  int32_t;  /* long signed word    (4 bytes) */

/* basic types definition */
typedef unsigned char       ubyte;  /* unsigned byte       (1 byte ) */
typedef unsigned short int  ushort; /* short unsigned word (2 bytes) */
typedef unsigned long  int  ulong;  /* long unsigned word  (4 bytes) */
typedef signed   char       sbyte;  /* signed byte         (1 byte ) */
typedef signed   short int  sshort; /* short signed word   (2 bytes) */
typedef signed   long  int  slong;  /* long signed word    (4 bytes) */
/* boolean type definition */

//  typedef enum
//  {
//    FALSE = 0,
//    TRUE
//  } bool_t;
#define FALSE   0
#define TRUE    1
typedef bit bool_t;

typedef enum
{
    eFALSE,
    eTRUE
} eBoolean;



#endif /* __TYPE_H__ */

/*_____________ End File ____ (type.h) _____________________________________________________*/
