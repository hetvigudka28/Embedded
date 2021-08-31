int valueog=0;
int value1=0;
int value2=0;
float volt1=0.0;
float volt2=0.0;
int key1=0;
int key2=0;
int counter=0;

long fin=0;
void setup() {
  Serial.begin(9600);
  Serial.println(valueog);
  value1=analogRead(A0);
  volt1=value1*5.0/1023.0;
  key1=(int)volt1;
  // put your setup code here, to run once:

}

void loop() {
  value2=analogRead(A0);
  volt2=value2*5.0/1023.0;
  key2=(int)volt2;
  if((key1==5 && key2==0) || (key1==4 && key2==0))
  {
    counter= (value2-0)+(1023-value1);
    fin+=counter;
  }
  else if((key1==0 && key2==5) || (key1==0 && key2==4))
  {
    counter=(value1-0)+(1023-value2);
    fin-=counter;
  }
  else{
  counter=value2-value1;
  fin+=counter;
  }
  Serial.println(fin);
  value1=value2;
  volt1=volt2;
  key1=key2;
}


  

  


 
