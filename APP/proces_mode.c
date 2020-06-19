#include "header.h"



//关机处理
void close_process(void)
{
    led_dispose(0x00);
    printf("m0\n");
}

//清洁模式
void whiten_process(void)
{
    led_dispose(1);
    printf("m1\n");
}
//美白模式
void clean_process(void)
{
    led_dispose(2);
    printf("m2\n");
}
//按摩模式
void massage_process(void)
{
    led_dispose(3);
    printf("m3\n");
}
//敏感模式
void sensitive_process(void)
{
    led_dispose(4);
    printf("m4\n");
}

//处理模式
void proces_mode(void)
{
    switch (key.work_mode)
    {
    case CLOSE:
        close_process();
        break;
    case WHITEN_ONE://清洁模式
        whiten_process();
        break;
    case CLEAN_TWO://美白模式
        clean_process();
        break;
    case MASSAGE_THREE://按摩模式
        massage_process();
        break;
    case SENSITIVE_FOUR://敏感模式
        sensitive_process();
        break;
    default:
        break;
    }
}

