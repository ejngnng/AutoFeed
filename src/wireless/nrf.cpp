/*
* Description: nrf2401 header file
* Hardware   : Arduino nano 328p
* Version    : V1.1
* Author     : Ninja
* Date       : 2017-10
*/

#include "nrf.h"

RF24 radio(NRF_CE, NRF_CS);   // CE, CS Set up nRF24L01 radio on SPI bus plus pins 7 & 8

const unsigned char radio_addr[5] = {'C', 'T', 'L', 'R', 'C'};

// nRF24L01 init RF_TX or RF_RX
void nrf_init(nrf_role_m role){
  radio.begin();                           // Setup and configure rf radio
  radio.setDataRate(RF24_250KBPS);
  radio.setRetries(3, 5);
  if(role == RF_TX){
    radio.openWritingPipe(radio_addr);
  }else{
    radio.openReadingPipe(1,radio_addr);
    radio.startListening();
  }

}

// send control data
nrf_rs_t set_ctl(ctl_obj_t *ctl_obj){
  unsigned char data[2] = {0, 0};
  data[0] = ctl_obj->ctl_type;
  data[1] = ctl_obj->value;
#ifdef DEBUG_NRF
  DEBUG_NRF.println(data[0]);
  DEBUG_NRF.println(data[1]);
#endif
  if(!radio.write(data, sizeof(data))){
    return RS_FAIL;
  }
  return RS_OK;
}

// check if data arrived
bool check_radio(){
  if(radio.available()){
    return true;
  }else{
    return false;
  }
}

// get arrived data
nrf_rs_t get_ctl(ctl_obj_t *ctl_obj){
  unsigned char data[2] = {0};
  radio.read(&data, sizeof(data));
#ifdef DEBUG_NRF
  DEBUG_NRF.print("receive data: ");
  DEBUG_NRF.print(data[0]);
  DEBUG_NRF.print("  ");
  DEBUG_NRF.println(data[1]);
#endif
  ctl_obj->ctl_type = (ctl_type_m)data[0];
  ctl_obj->value = data[1];

  return RS_OK;

}
