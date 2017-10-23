/*
* Description: keyboard header file
* Hardware   : Arduino nano 328p
* Version    : V1.1
* Author     : Ninja
* Date       : 2017-10
*/

#ifndef __KEY_H
#define __KEY_H

#include "config/common.h"

#define KEY_START     19
#define KEY_CONFIG    18
#define KEY_ESTOP     17

#define KEY_CUT_START 9
#define KEY_CUT_STOP  8

typedef enum key_rs_e{
  RS_OK = 0,
  RS_FAIL
}key_rs_t;

void key_port_init(void);

#endif
