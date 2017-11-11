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
#include "nRF24L01.h"
#include "RF24.h"

//#define DEBUG_NRF   Serial

#define NRF_CE    7
#define NRF_CS    8

#define STOP_ENCODE     0xA0
#define START_ENCODE    0xA1
#define LEFT_ENCODE     0xA2
#define RIGHT_ENCODE    0xA3
#define UP_ENCODE       0xA4
#define DOWN_ENCODE     0xA5
#define SHOOT_ENCODE    0xA6
#define CONFIG_ENCODE   0xA7

typedef enum nrf_rs_e{
  RS_OK = 0,
  RS_FAIL
}nrf_rs_t;

typedef enum nrf_role_e{
  RF_RX = 0,
  RF_TX
}nrf_role_m;


typedef enum control_type_e{
  STOP_CTL = 0,
  START_CTL,
  LEFT_CTL,
  RIGHT_CTL,
  UP_CTL,
  DOWN_CTL,
  SHOOT_CTL,
  CONFIG_CTL
}ctl_type_m;

typedef struct ctl_obj_s{
  ctl_type_m ctl_type;
  unsigned char value;
}ctl_obj_t;

void nrf_init(nrf_role_m role);

nrf_rs_t set_ctl(ctl_obj_t *ctl_obj);

nrf_rs_t get_ctl(ctl_obj_t *ctl_obj);

bool check_radio(void);

#endif
