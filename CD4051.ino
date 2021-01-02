#define ANALOG_PIN A0
#define OUT_A 2
#define OUT_B 3
#define OUT_C 4
 
void setup() {
  pinMode(OUT_A, OUTPUT);
  pinMode(OUT_B, OUTPUT);
  pinMode(OUT_C, OUTPUT);
  Serial.begin(9600);
}

void loop() {   
   for (int i = 0b000; i <= 0b111; i++) {
     digitalWrite(OUT_A, bitRead(i, 0));
     digitalWrite(OUT_B, bitRead(i, 1));
     digitalWrite(OUT_C, bitRead(i, 2));
     
     Serial.print(analogRead(ANALOG_PIN));
     Serial.print(" | ");
   }
   Serial.println();
   delay(500);
}
