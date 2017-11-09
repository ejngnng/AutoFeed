/*
* Description: move sersor header file
* Hardware   : Arduino nano 328p
* Version    : V1.1
* Author     : Ninja
* Date       : 2017-10
*/

#ifndef __NRF_H
#define __NRF_H

#include <Arduino.h>

#include <SPI.h>
#include "RF24.h"

#define NRF_CE    7
#define NRF_CS    8

typedef enum nrf_rs_e{
  RS_OK = 0,
  RS_FAIL
}nrf_rs_t;

typedef enum nrf_role_e{
  RF_RX = 0,
  RF_TX
}nrf_role_m;

typedef struct control_obj_s{
  unsigned char left_ctl;
  unsigned char right_ctl;
  unsigned char up_ctl;
  unsigned char down_ctl;
  unsigned char stop_ctl;
  unsigned char start_ctl;
  unsigned char shoot_ctl;
}ctl_obj_t;

typedef enum control_type_e{
  STOP = 0,
  START,
  LEFT,
  RIGHT,
  UP,
  DOWN,
  SHOOT
}ctl_type_m;

void nrf_init(nrf_role_m role);

nrf_rs_t set_ctl(ctl_obj_t *ctl_obj);

void get_ctl(ctl_obj_t *ctl_obj);

#endif
