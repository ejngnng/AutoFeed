/*
* Description: common source file
* Hardware   : Arduino nano 328p
* Version    : V1.1
* Author     : Ninja
* Date       : 2017-10
*/

#include "common.h"

void uart_init(){
  Serial.begin(BAUD_RATE);
}
