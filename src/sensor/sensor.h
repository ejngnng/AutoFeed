/*
* Description: move sersor header file
* Hardware   : Arduino nano 328p
* Version    : V1.1
* Author     : Ninja
* Date       : 2017-10
*/

#ifndef __SENSOR_H
#define __SENSOR_H

#include "config/common.h"

typedef enum sensor_state_e{
  OFF = 0,
  ON
}sensor_state_t;

typedef enum sensor_rs_e{
  RS_OK = 0,
  RS_FAIL
}sensor_rs_t;

#define SENSOR_MOTION   5
#define SENSOR_POWER    7
#define SENSOR_LASER    10

void sensor_port_init(void);

#endif
