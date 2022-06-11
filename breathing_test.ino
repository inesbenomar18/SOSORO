
//**********************************************************************
//*** SOft SOcial RObotic Actuator Control With Arduino Motor Shield ***
//***              SOSORO - Breathing Test                           ***
//***                   Ines Benomar                                 ***
//**********************************************************************


//Pumps and valves initiated 
int pumpPin1 = 5; //Pump 1 
int valvePin1 = 10; //valve 1

bool breathsOn=1;

void setup() {
 Serial.begin(9600); // opens serial port, sets data rate to 9600 bps
 deflateComplete(); //Deflates the robot before
 Serial.println("Beginning...");
}

void loop() {

runAll();
}

void runAll() {

  if (breathsOn==1){

  digitalWrite(pumpPin1,HIGH);
  digitalWrite(valvePin1,HIGH);
    delay(3400);

  digitalWrite(pumpPin1,LOW);
  digitalWrite(valvePin1,LOW);
    delay(4400);
    }
}


//Declaration of pump and valve functions below: 
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

void deflateComplete() {
  deflate1();
  delay(5000);
}
