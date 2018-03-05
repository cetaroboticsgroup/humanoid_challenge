void setup(){
SerialUSB.begin();
}

byte temp = 0;  

void loop(){
  
if ( SerialUSB.available() ){
temp = SerialUSB.read();
char a = (char)temp;
//int b = a+1;
if(a == '1'){
SerialUSB.print((char)a);}
else if((char)a == 'a'){
SerialUSB.print((char)a);}
}

}

