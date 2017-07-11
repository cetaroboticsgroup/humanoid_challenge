//Upper Body Control Greeting
Dynamixel Dxl(1);

//Angle conversion
int d (float input){
  int output;
  if (input < 0){
    output = (input+150)/300*1024;
  }
  else{
    output = input/300*1023+512;
  }
 return (output);
} 

//syncwordpage
word Page1[30]=
{ 
  1,d(0),100,  //ID, Postion, speed
  3,d(-60),100,  
  5,d(0),100,
  2,d(0),100,
  4,d(60),100, 
  6,d(0),100,
  9,d(-45),100,
  10,d(45),100,
  11,952,100,
  12,69,100};
  
word Page2[6]=
{
  1,d(-60),500,
  2,d(-60),500};

word Page3[6]=
{
  5,d(-90),500,
  6,d(90),500};
  
word Page4[6]=
{
  9,d(-80),100,
  10,d(80),100};
  
word Page5[6]=
{
  9,d(-45),200,
  10,d(45),200};
  
word Page6[6]=
{
  5,d(0),500,
  6,d(0),500};
  
word Page7[6]=
{
  1,d(0),500,
  2,d(0),500};
  
void setup(){
// Dynamixel 2.0 Protocol -> 0: 9600, 1: 57600, 2: 115200, 3: 1Mbps 
  Dxl.begin(3);
}

void loop(){
/*
 * byte syncWrite(byte start_addr, byte num_of_data, int *param, int array_length);
 */
  Dxl.syncWrite(30,2,Page1,30);
  delay(1000);
  Dxl.syncWrite(30,2,Page2,6);
  delay(1000);
  Dxl.syncWrite(30,2,Page3,6);
  delay(1000);
  Dxl.syncWrite(30,2,Page4,6);
  delay(2000);
  Dxl.syncWrite(30,2,Page5,6);
  delay(2000);
  Dxl.syncWrite(30,2,Page6,6);
  delay(1000);
  Dxl.syncWrite(30,2,Page7,6);
  delay(1000);
}




