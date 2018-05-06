//Dynamixel on Serial1(USART1)  <-OpenCM9.04
Dynamixel Dxl(1);


//Angle conversion (degree to 0-1023)
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



///////////////////////////////////////
///Multiple Joint Control Part
///////////////////////////////////////

//current present and the prior goal present
double CP[17]={512,512,512,512,512,512,512,512,512,512,512,512,512,512,512,512,512};

//Multiple Joint Control function
void MJC(double GPI[17],int T){;
  int speed[17];
  double GP[17];
  int ID;
  CP[0]=0;
  
//Fix rotation direction
    GP[1] = -GPI[1];
    GP[2] = GPI[2];
    GP[3] = -GPI[3];
    GP[4] = -GPI[4];
    GP[5] = -GPI[5];
    GP[6] = -GPI[6];
    GP[7] = GPI[7];
    GP[8] = GPI[8];
    GP[9] = GPI[9];
    GP[10] = -GPI[10];
    GP[11] = GPI[11];
    GP[12] = -GPI[12];
    GP[13] = -GPI[13];
    GP[14] = GPI[14];
    GP[15] = -GPI[15];
    GP[16] = -GPI[16];   
  
  for ( ID=1; ID <= 16;ID ++){    
    GP[ID]=d(GP[ID]);   
    speed[ID] = ((GP[ID]-CP[ID])*1000/T)/2.286; //unit is about 0.111rpm = 0.67deg/s=2.286 num  
    if(speed[ID]<0){speed[ID]=-speed[ID];}  
    if(speed[ID]>2047){speed[ID] = 2047;}   
    CP[ID] = GP[ID]; // store the goal present to current postion       
  }
   
  word SyncPage1[48]=
  { 
  1,GP[1],speed[1],  
  2,GP[2],speed[2],  
  3,GP[3],speed[3],
  4,GP[4],speed[4],
  5,GP[5],speed[5],
  6,GP[6],speed[6],
  7,GP[7],speed[7],
  8,GP[8],speed[8],
  9,GP[9],speed[9],
  10,GP[10],speed[10],
  11,GP[11],speed[11],
  12,GP[12],speed[12],
  13,GP[13],speed[13],
  14,GP[14],speed[14],
  15,GP[15],speed[15],
  16,GP[16],speed[16]};
 
  // byte syncWrite(byte start_addr, byte num_of_data, int *param, int array_length); 
  Dxl.syncWrite(30,2,SyncPage1,48);
  // delay time for movment
  delay(1.1*T); 
}

void setup(){
  // Dynamixel 2.0 Baudrate -> 0: 9600, 1: 57600, 2: 115200, 3: 1Mbps
  Dxl.begin(3);
  
  double GP0[17] = {  0, 0, 0, 73.0, -73.0, 0, 0, 0, 0, -26.0, -26.0, 29.0, 29.0, -13.0, -13.0, 0, 0 };
   MJC(GP0,500);
   

//   
//   double GP5[17] = {  0, 22.0, -44.0, 73.0, -73.0, 0, 0, 0, 0, -26.0, -26.0, 29.0, 29.0, -13.0, -13.0, 0, 0 };
//   MJC(GP5,600);
//   
//   double GP6[17] = { 0, 0, 0, 73.0, -73.0, 0, 0, 0, 0, -26.0, -26.0, 29.0, 29.0, -13.0, -13.0, 0, 0};
//   MJC(GP6,400);
}

void loop()
{
   double GP1[17] = {   0, 0, 0, 73.0, -73.0, 0, 0, -12.0, 12.0, -35.0, -26.0, 47.0, 29.0, -22.0, -13.0, 0, 0 };
   MJC(GP1,100);
   
   double GP2[17] = { 0, 0, 0, 73.0, -73.0, 0, 0, -12.0, 12.0, -35.0, -26.0, 47.0, 29.0, -22.0, -13.0, 0, 0 };
   MJC(GP2,10);
   
   double GP3[17] = {  0, 0, 0, 73.0, -73.0, 0, 0, 0, 0, -26.0, -26.0, 29.0, 29.0, -13.0, -13.0, 0, 0 };
   MJC(GP3,100);
   
   double GP4[17] = {  0, 0, 0, 73.0, -73.0, 0, 0, 0, 0, -26.0, -26.0, 29.0, 29.0, -13.0, -13.0, 0, 0  };
    MJC(GP4,20);
}
