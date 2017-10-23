/*
* Description: move sersor source file
* Hardware   : Arduino nano 328p
* Version    : V1.1
* Author     : Ninja
* Date       : 2017-10
*/

#include "sensor.h"

void sensor_port_init(){
  pinMode(SENSOR_MOTION, INPUT);
  pinMode(SENSOR_LASER, INPUT);
  pinMode(SENSOR_POWER, OUTPUT);

  digitalWrite(SENSOR_POWER, LOW);
}
