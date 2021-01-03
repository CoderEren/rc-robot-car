// motor one
int enA = 9;
int in1 = 2;
int in2 = 3;

// motor two
int enB = 10;
int in3 = 4;
int in4 = 5;

#include <IRremote.h>

const int RECV_PIN = 7;
IRrecv irrecv(RECV_PIN);
decode_results results;

void setup() {
  irrecv.enableIRIn();
  irrecv.blink13(true);
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  analogWrite(enA, 200);
  analogWrite(enB, 200);
}

void loop() {
  if (irrecv.decode(&results)){
        switch(results.value){
          case 0xFF38C7: //Keypad button "5"
          digitalWrite(in1, LOW);
          digitalWrite(in2, LOW);  
          digitalWrite(in3, LOW);
          digitalWrite(in4, LOW);
     }

        switch(results.value){
          case 0xFF18E7: //Keypad button "2"
          digitalWrite(in1, LOW);
          digitalWrite(in2, HIGH);
          digitalWrite(in3, LOW);
          digitalWrite(in4, HIGH);
        }

        switch(results.value){
          case 0xFF4AB5: //Keypad button "8"
          digitalWrite(in1, HIGH);
          digitalWrite(in2, LOW);
          digitalWrite(in3, HIGH);
          digitalWrite(in4, LOW);
        }

        switch(results.value){
          case 0xFF10EF: //Keypad button "4"
          digitalWrite(in1, LOW);
          digitalWrite(in2, HIGH);
          digitalWrite(in3, LOW);
          digitalWrite(in4, LOW);
        }

        switch(results.value){
          case 0xFF5AA5: //Keypad button "6"
          digitalWrite(in1, LOW);
          digitalWrite(in2, LOW);
          digitalWrite(in3, LOW);
          digitalWrite(in4, HIGH);
        }
        irrecv.resume(); 
    }
}
