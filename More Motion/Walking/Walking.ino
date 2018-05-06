
//Dynamixel on Serial1(USART1)  <-OpenCM9.04
Dynamixel Dxl(1);

//Angle conversion (degree to 0-1023)
int d (float input){
  int output;
  if (input < 0){
    output = (input+150)/300*1023;
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
  
  for ( ID=1; ID <= 16;ID ++){    
    GP[ID]=d(GPI[ID]);   
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
  
  Dxl.syncWrite(30,2,SyncPage1,48);
  
  delay(1.1*T); // move delay time from SJC to here
}

void setup() {
  // Dynamixel 2.0 Baudrate -> 0: 9600, 1: 57600, 2: 115200, 3: 1Mbps
  Dxl.begin(3);
  int ID;
  
  for ( ID=1; ID <= 16;ID ++){  
    Dxl.writeByte(ID,24,1);
  }
  
  double GP1[17] = {0,0,0,-73.24,73.24,0,0,0,0,-26.37,26.37,29.3,-29.3,13.18,-13.18,0,0};
    MJC(GP1,500);

}

void loop(){
  
int T=75;      // Run Time
int I;
float leak = 1.2;

for( I=0; I <= 2;I ++){
   //motion 2
    double GP2[17] = {0,0,0,-73.24,73.24,0,0,0,0,-32.23,20.51,29.3,-29.3,10.25,-21.97,2.93,11.72};
    GP2[13] *= leak;
    GP2[14] *= leak;  
    MJC(GP2,T);
    delay(15);
    
  //motion3
    double GP3[17] = {0,8.79,8.79,-73.24,73.24,0,0,-2.93,2.93,-26.37,41.02,29.3,-58.59,16.11,-30.76,2.93,8.79};
    GP3[13] *= leak;
    GP3[14] *= leak; 
    MJC(GP3,T);
    
  //motion4
    double GP4[17] = {0,29.3,14.65,-73.24,73.24,0,0,0,0,-20.51,32.23,29.3,-29.3,21.97,-10.25,0,0};
    GP4[13] *= leak;
    GP4[14] *= leak; 
    MJC(GP4,T);
  
  //motion 5
    double GP5[17] = {0,-0.29,-0.29,-73.54,72.95,-0.29,-0.29,-0.29,-0.29,-20.8,31.93,29,-29.59,21.68,-10.55,-12.01,-3.22};
    GP5[13] *= leak;
    GP5[14] *= leak;
    MJC(GP5,T);
    delay(15);
  
  //motion 6
    double GP6[17] = {0,-9.08,-9.08,-73.54,72.95,-0.29,-0.29,-3.22,2.64,-41.31,26.07,58.3,-29.59,30.47,-16.41,-9.08,-3.22};
    GP6[13] *=  leak;
    GP6[14] *= leak;
    MJC(GP6,T);
    
  //motion 7
    double GP7[17] = {0,-14.65,-29.3,-73.24,73.24,0,0,0,0,-32.23,20.51,29.3,-29.3,10.25,-21.97,0,0};
    GP7[13] *= leak;
    GP7[14] *= leak;
    MJC(GP7,T);
    
    }
  
////motion 8
//  int GP8[17] = {0,0,0,-73.24,73.24,0,0,0,0,-32.23,20.51,29.3,-29.3,10.25,-21.97,2.93,11.72};
//  T = 70;
//  MJC(GP8,T);
//  
////motion 9
//  int GP9[17] = {0,8.79,8.79,-73.24,73.24,0,0,-2.93,2.93,-26.37,41.02,29.3,-58.59,16.11,-30.76,2.93,8.79};
//  T = 78;
//  MJC(GP9,T);
//  delay(15);
//
////motion 10
//  int GP10[17] = {0,-14.65,-29.3,-73.24,73.24,0,0,0,0,-32.23,20.51,29.3,-29.3,10.25,-21.97,0,0};
//  T = 70;
//  MJC(GP10,T);
}
