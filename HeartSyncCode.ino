
/*  Pulse Sensor Amped 1.4    by Joel Murphy and Yury Gitman  


Modified by Caitlin Pickall for Physical Computing 1 - Spring 2015
Modified to read from two sensors at once and check if they are in sync.

*/

//  Variables
int pulsePin = A0;                 // Pulse Sensor purple wire connected to analog pin 0
int pulsePin2 = A1;
int motorPin = 8;
int motorPin2 = 9;


// Volatile Variables, used in the interrupt service routine!
volatile int BPM;                   // int that holds raw Analog in 0. updated every 2mS
volatile int Signal;                // holds the incoming raw data
volatile int IBI = 600;             // int that holds the time interval between beats! Must be seeded! 
volatile boolean Pulse = false;     // "True" when User's live heartbeat is detected. "False" when not a "live beat". 
volatile boolean QS = false;        // becomes true when Arduoino finds a beat.


volatile int BPM2;                   // int that holds raw Analog in 0. updated every 2mS
volatile int Signal2;                // holds the incoming raw data
volatile int IBI2 = 600;             // int that holds the time interval between beats! Must be seeded! 
volatile boolean Pulse2 = false;     // "True" when User's live heartbeat is detected. "False" when not a "live beat". 
volatile boolean QS2 = false;        // becomes true when Arduoino finds a beat.


void setup(){
  Serial.begin(115200);             
  interruptSetup();                 // sets up to read Pulse Sensor signal every 2mS 
  pinMode(motorPin, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  for(int i = 14; i < 34; i++){
  pinMode(i, OUTPUT);
}
}


void loop(){
  
  if (QS == true){     
        serialOutputWhenBeatHappens();    
        digitalWrite(motorPin2, HIGH); 
        QS = false;                      
       } else {
         digitalWrite(motorPin2, LOW);
       }
       
    if (QS2 == true){     
        serialOutputWhenBeatHappens2();  
        digitalWrite(motorPin, HIGH);      
        QS2 = false;                      
       } else {
         digitalWrite(motorPin, LOW);  
       }
       
    if (QS == true && QS2 == true){
      Serial.println("###BEAT AT THE SAME TIME####");

    }
    
    if (abs(BPM - BPM2) < 2){
      Serial.println("####HEARTRATES MATCH!!####");
      for (int i = 14; i < 34; i++){
        digitalWrite(i, HIGH);
      }
    } else {
      for (int i = 14; i < 34; i++){
        digitalWrite(i, LOW);
      }
    }
       
  delay(20);                            
}







