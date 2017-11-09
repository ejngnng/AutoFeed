/*
* Description: nrf2401 header file
* Hardware   : Arduino nano 328p
* Version    : V1.1
* Author     : Ninja
* Date       : 2017-10
*/

#include "nrf.h"

RF24 radio(NRF_CE, NRF_CS);   // CE, CS Set up nRF24L01 radio on SPI bus plus pins 7 & 8

const uint64_t pipes[2] = { 0xABCDABCD71LL, 0x544d52687CLL };   // Radio pipe addresses for the 2 nodes to communicate.

void nrf_init(nrf_role_m role){
  radio.begin();                           // Setup and configure rf radio
  radio.setChannel(1);
  radio.setPALevel(RF24_PA_MAX);
  radio.setDataRate(RF24_1MBPS);
  radio.setAutoAck(1);                     // Ensure autoACK is enabled
  radio.setRetries(2,15);                  // Optionally, increase the delay between retries & # of retries

  radio.setCRCLength(RF24_CRC_8);          // Use 8-bit CRC for performance

  radio.openWritingPipe(pipes[0]);
  radio.openReadingPipe(1,pipes[1]);

  radio.startListening();                 // Start listening
  radio.printDetails();                   // Dump the configuration of the rf unit for debugging

  radio.powerUp();                        //Power up the radio

  if(role == RF_TX){
    radio.openWritingPipe(pipes[1]);
    radio.openReadingPipe(1,pipes[0]);
    radio.stopListening();
  }else{
    radio.openWritingPipe(pipes[0]);
    radio.openReadingPipe(1,pipes[1]);
    radio.startListening();
  }

}


nrf_rs_t set_ctl(ctl_obj_t *ctl_obj){
  if(!radio.writeFast(ctl_obj, sizeof(ctl_obj_t))){
    return RS_FAIL;
  }
  return RS_OK;
}


void get_ctl(ctl_obj_t *ctl_obj){
  memset(ctl_obj, 0, sizeof(ctl_obj_t));
  while(radio.available()){
    radio.read(ctl_obj, sizeof(ctl_obj_t));
  }
}
