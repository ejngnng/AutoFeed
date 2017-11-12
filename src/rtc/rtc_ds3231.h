/*
* Description: ds3231 rtc header file
* Hardware   : Arduino nano 328p
* Version    : V1.1
* Author     : Ninja
* Date       : 2017-10
*/
#ifndef __RTC_DS3231_H
#define __RTC_DS3231_H

#include "config/common.h"

#include <Wire.h>
#include <DS3231.h>

#define  DEBUG_DS3231     Serial

typedef struct date_time_s{
  unsigned char year;
  unsigned char month;
  unsigned char date;
  unsigned char hour;
  unsigned char minute;
  unsigned char second;
  unsigned char week;
}date_time_t;

void ds3231_init();

void set_clock();

void show_clock();

void get_time(date_time_t *date_time);

#endif
