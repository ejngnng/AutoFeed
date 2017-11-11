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

void ds3231_init();

void set_clock();

void show_clock();

#endif
