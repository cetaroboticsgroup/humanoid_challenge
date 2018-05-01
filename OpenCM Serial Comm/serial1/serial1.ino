void setup(){
  SerialUSB.begin();
}

byte temp = 0;
volatile int nCount=0;
void loop(){

  if ( SerialUSB.available() ){
     temp = SerialUSB.read();
    char a = (char)temp;
    
    if(a == '1'){
      SerialUSB.print((char)a);}
    else if((char)a == 'a'){
    SerialUSB.println("Hello World!!");
    SerialUSB.print("nCount : "); // display nCount variable and increase nCount.
    SerialUSB.println(nCount++);//SerialUSB.print("\r\n");  
    }
  }
}
