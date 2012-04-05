const int MAX_THRESHOLD = 190;//190
const int MIN_THRESHOLD = 150;//115

const int analogInPin = A0;  // Analog input pin that the sensor is attached to
int millisInSecond = 1000;
int secondsInMinute = 60;
int sensorValue = 0;        // value read from the sensor
void setup(){
pinMode(13,OUTPUT); // viene settato il pin 13 come uscita
  Serial.begin(9600); 
}

void loop(){
  sensorValue = analogRead(analogInPin);            
  if(sensorValue>MAX_THRESHOLD)
  digitalWrite(13,LOW); // mette il pin 13 a livello alto facendo andare il bjt in saturazione 
			// ed eccitando il relè 
  if(sensorValue<MIN_THRESHOLD)
digitalWrite(13,HIGH); // pone il pin 13 a livello basso spegnendo il bjt e spegnendo il relè
  Serial.print("sensor = " );                       
  Serial.println(sensorValue);    
delay(1000); // attende 2 minuti e poi il ciclo si ripete
}
