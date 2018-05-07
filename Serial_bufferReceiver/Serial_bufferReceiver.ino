Dynamixel Dxl(1); 
 
void setup() {
  Dxl.begin(3);
  SerialUSB.attachInterrupt(usbInterrupt); 
  pinMode(BOARD_LED_PIN, OUTPUT);
}
 
void usbInterrupt(byte* buffer, byte nCount){
  char cmd[3];
  for(int i=0; i < nCount;i++){  //printf_SerialUSB_Buffer[N]_receive_Data
    cmd[i] = buffer[i];
     SerialUSB.println(cmd[i]);}
}

void loop(){
  toggleLED();
  delay(100);
  
  // test interrupt
//  Dxl.writeWord(17,25,6);
//  
//  Dxl.writeWord(5,30,200) ;
//   delay(1000); 
//  Dxl.writeWord(5, 30,800);
//  delay(1000);


}

