#include <SoftwareSerial.h>
#include <Stepper.h>

// Find Dust
SoftwareSerial mySerial(7,6); // Arudino Uno port RX, TX

// Stepping Motor
const int stepsPerRevolution = 64;
Stepper myStepper(stepsPerRevolution, 11,9,10,8); 

// Bluetooth
SoftwareSerial BTSerial(2, 3); 
byte buffer[1024];
int bufferPosition; 

void setup() {
  // for debuging 
  Serial.begin(9600);  


  BTSerial.begin(9600);
  
  // Use software serial
  mySerial.begin(9600);

  myStepper.setSpeed(500);
  bufferPosition = 0; 
}

void loop() {
  // put your main code here, to run repeatedly:
  static int CheckFirst=0;
  static int pm_add[3][5]={0,};
  static int pm_old[3]={0,};
  int chksum=0,res=0;;
  unsigned char pms[32]={0,};
  
 //mySerial.listen();
  if(mySerial.available()>=32){

    for(int j=0; j<32 ; j++){
      pms[j]=mySerial.read();
      if(j<30)
        chksum+=pms[j];
    }

    if(pms[30] != (unsigned char)(chksum>>8) 
        || pms[31]!= (unsigned char)(chksum) ){

      return res;
    }
    if(pms[0]!=0x42 || pms[1]!=0x4d )
      return res;

     Serial.print(pms[13]);
     BTSerial.println(pms[13]);
     } 

     
//BTSerial.listen();
//if (BTSerial.available()){ // 블루투스로 데이터 수신
//  Serial.write(BTSerial.read());
//
//byte data = BTSerial.read();
//  String myString = String(data);
//
//      if (myString.compareTo("Open")) {
//        for(int i=0; i<64; i++) {  // 64 * 32 = 2048 한바퀴
//          myStepper.step(stepsPerRevolution);
//         }
//      }
//  }
}

