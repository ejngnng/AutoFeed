/*
* Description: ds3231 rtc source file
* Hardware   : Arduino nano 328p
* Version    : V1.1
* Author     : Ninja
* Date       : 2017-10
*/
#include "rtc_ds3231.h"

DS3231 Clock;

bool Century=false;
bool h12;
bool PM;

void ds3231_init(){
  Wire.begin();
//  set_clock(); //only set once
}

void set_clock(){
  Clock.setYear(17);
  Clock.setMonth(11);
  Clock.setDate(12);
  Clock.setDoW(7);
  Clock.setHour(2);
  Clock.setMinute(12);
  Clock.setSecond(10);
}

void show_clock(){
  Serial.print(Clock.getYear(), DEC);
  Serial.print("-");
  Serial.print(Clock.getMonth(Century), DEC);
  Serial.print("-");
  Serial.print(Clock.getDate(), DEC);
  Serial.print(" ");
  Serial.print(Clock.getHour(h12, PM), DEC);
  Serial.print(":");
  Serial.print(Clock.getMinute(), DEC);
  Serial.print(":");
  Serial.print(Clock.getSecond(), DEC);
  Serial.print(" ");
  Serial.println(Clock.getDoW(), DEC);
}

void get_time(date_time_t *date_time){
  date_time->year = Clock.getYear();
  date_time->month = Clock.getMonth(Century);
  date_time->date = Clock.getDate();
  date_time->hour = Clock.getHour(h12, PM);
  date_time->minute = Clock.getMinute();
  date_time->second = Clock.getSecond();
  date_time->second = Clock.getSecond();
}
