const int st1_trigPin = 2;
const int st1_echoPin = 3;
const int st1_redLed  = 11;
const int st1_greenLed = 12;

bool stationDone = false;
void setup() {
  Serial.begin(9600);
  pinMode(st1_trigPin, OUTPUT);
  pinMode(st1_echoPin, INPUT);
  pinMode(st1_redLed, OUTPUT);
  pinMode(st1_greenLed, OUTPUT);
  
  randomSeed(analogRead(0)); 

  Serial.println("Station_1 Ready :)");
}

void loop() {
  if (stationDone == false){
  long result = runStation1();
  Serial.print("Reflex Time: ");
  Serial.print(result);
  Serial.println(" ms");
  stationDone = true;
  Serial.print("STATION_1 FINISHED");
  }
}

long runStation1() {
  for (int i = 0; i < 3; i++) {
    digitalWrite(st1_redLed, HIGH);
     delay(700);
    digitalWrite(st1_redLed, LOW);
      delay(700);
  }

  delay(random(1000, 4000));
  
  digitalWrite(st1_greenLed, HIGH);
  long startTime = millis();

  // while (getSt1Distance() > 2) {
    
  // }

  while (true)
  {
    long d1 = getSt1Distance();
    delay(5);
    long d2 = getSt1Distance();
    delay(5);
    long d3 = getSt1Distance();
    if(d1 >0 && d1 <=3 && d2 > 0 && d2 <= 3 && d3 > 0 && d3 <= 3){
      break;
    }
  }
  long reflexTime = millis() - startTime;
  digitalWrite(st1_greenLed, LOW);

  return reflexTime;
}
long getSt1Distance() {
  digitalWrite(st1_trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(st1_trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(st1_trigPin, LOW);
  long duration = pulseIn(st1_echoPin, HIGH, 30000); 
  if (duration == 0) return 999;
  return duration * 0.034 / 2;
}
