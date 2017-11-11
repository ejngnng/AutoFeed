
/*
 * Description: auto feed system
 * Hardware   : Arduino nano 328p
 * Version    : V1.1
 * Author     : Ninja
 * Date       : 2017-10
 */

#include <Arduino.h>
#include "config/common.h"
#include "wireless/nrf.h"

ctl_obj_t ctl_obj;
ctl_obj_t receive_obj;
extern RF24 radio;


//#define TX_TEST

unsigned long currentMillis;
unsigned long prevMillis;
unsigned long txIntervalMillis = 1000; // send once per second

void updateMessage();

void setup(){
  uart_init();
#ifdef TX_TEST
  nrf_init(RF_TX);
#else
  nrf_init(RF_RX);
#endif
  memset(&ctl_obj, 0, sizeof(ctl_obj_t));
  memset(&receive_obj, 0, sizeof(ctl_obj_t));
}

void loop(){
#ifdef TX_TEST
  currentMillis = millis();
  if (currentMillis - prevMillis >= txIntervalMillis) {
      ctl_obj.ctl_type = CONFIG_CTL;
      updateMessage();
      set_ctl(&ctl_obj);
      prevMillis = millis();
  }
#else
  if(check_radio()){
    get_ctl(&receive_obj);
    Serial.print("type: ");
    Serial.print(receive_obj.ctl_type);
    Serial.print(" ");
    Serial.print("value: ");
    Serial.println(receive_obj.value);
  }
#endif
}

void updateMessage() {
  Serial.println("update message...");
  ctl_obj.value += 1;
  Serial.println(ctl_obj.value);
}
