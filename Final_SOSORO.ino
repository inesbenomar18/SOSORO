//**********************************************************************
//*** SOft SOcial RObotic Actuator Control With Arduino Motor Shield ***
//***              SOSORO - Final Code                               ***
//***                   Ines Benomar                                 ***
//**********************************************************************

//Pumps and valves initiated 

//Arms
int pumpPin1 = 3;  
int valvePin1 = 11;

//Belly
int pumpPin2 = 6;
int valvePin2 = 5;

void setup() {
 Serial.begin(9600);
 deflateComplete();
 Serial.setTimeout(20); 
 Serial.println("Beginning...");
}


void loop() {
  
 runAll();

}

void runAll(){
    Serial.println("Inflation...");
  
  //inflate
  digitalWrite(pumpPin2,HIGH);
  digitalWrite(valvePin2,HIGH);
  digitalWrite(pumpPin1,HIGH);
  digitalWrite(valvePin1,HIGH);
  delay(20000);

  Serial.println("Hold...");
  //hold
  digitalWrite(pumpPin1,LOW);
  digitalWrite(valvePin1,HIGH);
  digitalWrite(pumpPin2,LOW);
  digitalWrite(valvePin2,HIGH);
  delay(2000);

  Serial.println("Deflation...");
  //deflate
  digitalWrite(pumpPin2,LOW);
  digitalWrite(valvePin2,LOW);
  digitalWrite(pumpPin1,LOW);
  digitalWrite(valvePin1,LOW);
  delay(2000);
}

//Declaration of pump and valve functions below: 
//**********************************************************************
//  Pump and valve functions for SOSORO's arms
//**********************************************************************

void inflate1(){
  digitalWrite(pumpPin1,HIGH);
  digitalWrite(valvePin1,HIGH);
}

void deflate1(){
  digitalWrite(pumpPin1,LOW);
  digitalWrite(valvePin1,LOW);
}

void hold1(){
  digitalWrite(pumpPin1,LOW);
  digitalWrite(valvePin1,HIGH);
}


//**********************************************************************
//  Pump and valve functions for SOSORO's belly
//**********************************************************************

void hold2(){
  digitalWrite(pumpPin2,LOW);
  digitalWrite(valvePin2,HIGH);
}
void inflate2(){
  digitalWrite(pumpPin2,HIGH);
  digitalWrite(valvePin2,HIGH);
}

void deflate2(){
  digitalWrite(pumpPin2,LOW);
  digitalWrite(valvePin2,LOW);
}
//**********************************************************************

void deflateComplete() {
  deflate1();
  deflate2();
  delay(5000);
}
