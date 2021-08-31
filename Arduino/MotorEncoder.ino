#define EncoderA 2
#define EncoderB 3
#define MotorCW 8
#define MotorCWW 11
int Setpoint=10000;
int temp=0;
int PV=0;

void setup() {
  Serial.begin(9600);
  pinMode(EncoderA, INPUT);
 
  pinMode(EncoderB, INPUT);
 
  pinMode(MotorCW, OUTPUT);
  pinMode(MotorCWW, OUTPUT);
  pinMode(9, OUTPUT);
  attachInterrupt(0, doEncoderA, RISING);
 Serial.println("Start");
  
  // put your setup code here, to run once:

}


void loop() {
  
    digitalWrite(MotorCW, HIGH);
    digitalWrite(MotorCWW, LOW);
    analogWrite(9, 150);
    Serial.println(PV);
  

}

void doEncoderA() {
  
  if (digitalRead(EncoderA) == HIGH) {

    
    if (digitalRead(EncoderB) == LOW) {
      PV = PV + 1;         // CW
    }
    else {
      PV = PV - 1;         // CCW
    }
  }

  else   
  {
    
    if (digitalRead(EncoderB) == HIGH) {
      PV = PV + 1;          // CW
    }
    else {
      PV = PV - 1;          // CCW
    }
  }
  
}
