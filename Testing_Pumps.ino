//**********************************************************************
//*** SOft SOcial RObotic Actuator Control With Arduino Motor Shield ***
//***              SOSORO - Testing the Pumps                        ***
//***                   Ines Benomar                                 ***
//**********************************************************************


//Arms
int pumpPin1 = 3;  
int valvePin1 = 11;

//Belly
int pumpPin2 = 6;
int valvePin2 = 5;

void setup() {
 Serial.begin(9600);
 Serial.setTimeout(20); 
 Serial.println("Beginning...");
}


void loop() {

  Serial.println("Inflation...");
  
  //inflate
  digitalWrite(pumpPin2,HIGH);
  digitalWrite(valvePin2,HIGH);
  digitalWrite(pumpPin1,HIGH);
  digitalWrite(valvePin1,HIGH);
  delay(10000);

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
