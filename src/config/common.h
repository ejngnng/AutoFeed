/*
* Description: common header file
* Hardware   : Arduino nano 328p
* Version    : V1.1
* Author     : Ninja
* Date       : 2017-10
*/

#ifndef __COMMON_H
#define __COMMON_H

#include <Arduino.h>

#ifndef BAUD_RATE
#define BAUD_RATE 115200
#endif


void uart_init(void);


#endif
