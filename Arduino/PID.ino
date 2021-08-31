#define encoderPinA 2
#define encoderPinB 3
#define MotorCW 9
#define MotorCWW 10
int SetPoint=3000;
int PV=0;
int err=0;
double P, It, D=0.0;
double kP=0.76;
int kI=0.05;
int kD=0.03;
int dt=1000;
int output=255;

void setup() {
  Serial.begin(9600);
  pinMode(encoderPinA, INPUT);
  pinMode(encoderPinB, INPUT);
  pinMode(MotorCW, OUTPUT);
  pinMode(MotorCWW, OUTPUT);
  pinMode(6, OUTPUT);
  
  attachInterrupt(0, doEncoderA, RISING);

}

void loop() {
  int t1=millis();
  int perr=err;
  err= SetPoint-PV;
  P= kP*err;  
  It+=kI*err*dt;
  D=kD*((perr-err)/dt);
  double out=P+It+D;
  output=(int)out;
  if(output>255)
  {
  output=255;
  }
  digitalWrite(MotorCW, HIGH );
  //digitalWrite(MotorCWW, HIGH);
  if(output>0)
  analogWrite(6, output);
  else
  analogWrite(6,0);
  int t2=millis();
  dt=t2-t1;
  if(output>=0)
  {
  Serial.print(PV);
  Serial.print("                ");
  
  Serial.print(output);
  Serial.print("                ");
  Serial.print(It);
  Serial.print("                ");
  Serial.println(D);
  }
  if(output==0)
  {
  Serial.println("Workssssssssssssssssssssssssssssssssssss");
  delay(3000);
  }
  
  
}

void doEncoderA() {
  
  if (digitalRead(encoderPinA) == HIGH) {

    
    if (digitalRead(encoderPinB) == LOW) {
      PV = PV + 1;         
    }
    else {
      PV = PV - 1;         
  }
  }

  else   
  {
    
    if (digitalRead(encoderPinB) == HIGH) {
      PV = PV + 1;          
    }
    else {
      PV = PV - 1;          
    }
  }
  
}
