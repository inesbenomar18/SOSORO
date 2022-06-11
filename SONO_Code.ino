

***********************************************************************************************************
***                                                                                                     ***
*** // Modified  SONO/Breathing Robot code to test different Breathing Patterns on SOSORO               ***
***                                                                                                     ***
***********************************************************************************************************




//Pumps and valves initiated 
int pumpPin1 = 3; //pump 1 
int valvePin1 = 11; //valve 1 

int pumpPin2 = 6; //pump 2 
int valvePin2 = 5; //valve 2 

int pumpPin3 = 0; //pump 3 
int valvePin3 = 0; //valve 3


//Breathing parameters
//"Normal respiration rates for an adult person at rest range from 12 to 16 breaths per minute." https://www.hopkinsmedicine.org/health/conditions-and-diseases/vital-signs-body-temperature-pulse-rate-respiration-rate-blood-pressure
float respRate;//Respiratory rate in breaths per minunte
float breathPeriod=60000/respRate; //The time it takes to complete inhalation, pause, exhalation

int minRespRate=8; //Minimum allowed respiratory rate of robot
int maxRespRate=60; //Maximum allowed respiratory rate of robot

float breathPulseWidth=0.40; //Proportion (0 to 1) of breathPeriod that is spent on inhalation
float breathPauseWidth=0.01; //Proportion (0 to 1) of breathPeriod that is spent on the pause between inhalation and exhalation

float inhaleTime=breathPulseWidth*breathPeriod;
float pauseTime=breathPauseWidth*breathPeriod;
float exhaleTime=(1-breathPulseWidth-breathPauseWidth)*breathPeriod;

//Set parameter to use an offset for the breath, so e.g. the robot's breathing rate is always 3 BPM less than the human (set to -3) or 3 BPM higher (set to 3):
int breathRateOffSet=0;

long i;
bool breathsOn=0;


void setup() {
 Serial.begin(9600); // opens serial port, sets data rate to 9600 bps
 deflateComplete(); //Deflates the robot before
}

void loop() {
    
    respRate = 8; // Manually changed to test the respiratory rate
    i=20;
    breathsOn=1; 
    Serial.println("Starting");
 
    respRate=i+breathRateOffSet;//Respiratory rate in breaths per minunte   
    if (respRate<minRespRate) respRate=minRespRate;
    if (respRate>maxRespRate) respRate=maxRespRate;

    Serial.print("Robot respiratory rate set to:");
    Serial.println(respRate);
    //Calculate the time it takes to complete inhalation, pause, exhalation 
    breathPeriod=60000/respRate; 
    inhaleTime=breathPulseWidth*breathPeriod;
    pauseTime=breathPauseWidth*breathPeriod;
    exhaleTime=(1-breathPulseWidth-breathPauseWidth)*breathPeriod;
   
runAll();
  
}


void runAll() {

  if (breathsOn==1){

    inflate1();
    inflate2();
    inflate3();
    delay(inhaleTime);

    hold1();
    hold2();
    hold3();
    delay(pauseTime);

    deflate1();
    deflate2();
    deflate3();
    delay(exhaleTime);
    }
}


void testAll() {

  inflate1();
  inflate2();
  inflate3();
  delay(inhaleTime);

  hold1();
  hold2();
  hold3();
  delay(pauseTime);

  deflate1();
  deflate2();
  deflate3();
  delay(exhaleTime);
}


void test2() {
  inflate2();
  delay(2000);

  hold2();
  delay(2000);

  deflate2();
  delay(3000);
}


void test3() {
  inflate3();
  delay(1000);

  hold3();
  delay(2000);

  deflate3();
  delay(3000);
}



//Declaration of pump and valve functions below [changed in order to use NO valves]

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


void inflate2(){
  digitalWrite(pumpPin2,HIGH);
  digitalWrite(valvePin2,HIGH);
}

void deflate2(){
  digitalWrite(pumpPin2,LOW);
  digitalWrite(valvePin2,LOW);
}

void hold2(){
  digitalWrite(pumpPin2,LOW);
  digitalWrite(valvePin2,HIGH);
}


void inflate3(){
  digitalWrite(pumpPin3,HIGH);
  digitalWrite(valvePin3,HIGH);
}

void deflate3(){
  digitalWrite(pumpPin3,LOW);
  digitalWrite(valvePin3,LOW);
}

void hold3(){
  digitalWrite(pumpPin3,LOW);
  digitalWrite(valvePin3,HIGH);
}


void deflateComplete() {
  deflate1();
  deflate2();
  deflate3();
  delay(5000);

}
