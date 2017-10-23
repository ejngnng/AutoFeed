/*
* Description: keyboard source file
* Hardware   : Arduino nano 328p
* Version    : V1.1
* Author     : Ninja
* Date       : 2017-10
*/

#include "key.h"

void key_port_init(){
  pinMode(KEY_START, INPUT);
  pinMode(KEY_CONFIG, INPUT);
  pinMode(KEY_ESTOP, INPUT);
  pinMode(KEY_CUT_START, INPUT);
  pinMode(KEY_CUT_STOP, OUTPUT);

  digitalWrite(KEY_START, HIGH);
  digitalWrite(KEY_CONFIG, HIGH);
  digitalWrite(KEY_ESTOP, HIGH);
  digitalWrite(KEY_CUT_START, HIGH);
  digitalWrite(KEY_CUT_STOP, HIGH);
}
