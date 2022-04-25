/* 
*
*****************VOITENCO*************************09_07_2019**********************************************
*
*/
 


#include <IRremote.h>
//tttutuuh

int RECV_PIN = 5;
int RELAY = 6;
int STATUS_PIN = 2; //DINAMIC 
IRrecv irrecv(RECV_PIN);
IRsend irsend;
//const int buttonPin = 3;                  
 
decode_results results;
 
void setup()
{
  


  pinMode(STATUS_PIN, OUTPUT);
 digitalWrite(STATUS_PIN,1);
  
  pinMode(RELAY, OUTPUT);
  digitalWrite(RELAY,1);
  
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
  //irsend.sendNEC(0x80BFA15E, 32);
   
}
 
void loop() {
  if (irrecv.decode(&results)) {
    digitalWrite(STATUS_PIN,HIGH);
    //Serial.println(results.value,HEX);
  
    irrecv.resume(); // Receive the next value
    if ((results.value == 0x807FCA35)&&(digitalRead(7) == LOW)) //Если пришел сигнал на  вкл.выкл Т-2 и был включен тв (((LOW(7)-ON))))
    {
      irsend.sendSAMSUNG(0xE0E040BF, 32);//Код вкл.выкл  SamsungTV
      irrecv.enableIRIn();
      digitalWrite(RELAY,1);//OFF
    }
    
    if ((results.value == 0x807FCA35)&&(digitalRead(7) == HIGH)) //Если пришел сигнал на  вкл.выкл Т-2 и был off тв (((LOW(7)-OFF))))
    {
      irsend.sendSAMSUNG(0xE0E040BF, 32);//Код вкл.выкл  SamsungTV
      irrecv.enableIRIn();
      digitalWrite(RELAY,0);//ON
    }
    
    
  }
  digitalWrite(STATUS_PIN,LOW);
 
 /*if (digitalRead(7) == LOW)
    {digitalWrite(STATUS_PIN,HIGH);}

 */ 
}
