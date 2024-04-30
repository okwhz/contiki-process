#ifndef _ZK_H_
#define _ZK_H_

struct LED_ELEMENT
{
    char           ch;   //字符
    unsigned char  led; //显示数据
};

#define TABLE_NUMBER_MAX sizeof(LED_TABLE)/sizeof(struct LED_ELEMENT)
#define NO_CHAR    0X40


struct LED_ELEMENT const LED_TABLE[]={
    {'*',   0x00}, // ---熄灭
    {'-',   0X01}, // --'-' 负号
    {'0',   0X7E}, // ---0
    {'1',   0X30}, // ---1
    {'2',   0X6D}, // ---2
    {'3',   0X79}, // ---3
    {'4',   0X33}, // ---4
    {'5',   0X5B}, // ---5
    {'6',   0X5F}, // ---6
    {'7',   0X70}, // ---7
    {'8',   0X7F}, // ---8
    {'9',   0X7B}, // ---9
    {'@',   0X63}, // ---'0'  摄氏度
    {'A',   0X77}, // ---A
    {'B',   0X1F}, // ---B
    {'C',   0X4E}, // ---C
    {'D',   0X3D}, // ---D
    {'E',   0X4F}, // ---'E'字母 E
    {'E',   0X4F}, // ---E
    {'F',   0X47}, // ---F
    {'J',   0X38}, // ---'J' 字母 J
    {'L',   0X0E}, // ---'L'字母 L
    {'N',   0X76}, // ---'N' 字母 N
    {'O',   0X7E}, // ---'O'
    {'P',   0X67}, // --'P' 字母 P
    {'S',   0X4F}, // ---'S' 字母 S
    {'T',   0X0F}, // ---'T'字母 T
    {'U',   0X3E}, // ---'U' 字母 U
    {'V',   0X3E}, // ---'V'字母 V
    {'Y',   0X27}, // ---'Y' 字母 Y
};

#endif
