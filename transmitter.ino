int LED = 12; 
const int trigPin = 6;
const int echoPin = 7;
int duration = 0;
int distance = 0;


int vib_pin=3;
int count = 0;
 
int ALCOHOL_sensor = 3;// MQ-3 SENSOR  
int ALCOHOL_detected; 


void setup() {
  pinMode(trigPin , OUTPUT);
  pinMode(echoPin , INPUT);
  
  pinMode(LED , OUTPUT);
  pinMode(ALCOHOL_sensor, INPUT);
  pinMode(vib_pin,INPUT);
  
  Serial.begin(9600);

}

void loop() {
 digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);  
  duration = pulseIn(echoPin, HIGH);
  distance = duration/58.2;

  if ( distance <= 7 )
  {
    digitalWrite(LED, HIGH);
  }
  else
  {
    digitalWrite(LED, LOW);
  }
  delay(100);

  ALCOHOL_detected = digitalRead(ALCOHOL_sensor);  
  Serial.println(ALCOHOL_detected);  
  if (ALCOHOL_detected == 1)  
     {  
        Serial.println("ALCOHOL detected...");  
        digitalWrite(LED,HIGH);  
     }  
 else  
     {  
       Serial.println("No ALCOHOL detected ");  
       digitalWrite(LED, LOW);  
     }

     int val;
  val=digitalRead(vib_pin);
  if(val==1)
  {
    digitalWrite(LED,HIGH);
    delay(1000);
    digitalWrite(LED,LOW);
    delay(1000);
   }
   else
   digitalWrite(LED,LOW);

}
