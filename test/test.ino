#define relaypi 9
#define relay2 7
void setup() {
  // put your setup code here, to run once:
  pinMode(relaypi,OUTPUT);
  pinMode(relay2,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  Serial.println(digitalRead(relaypi));
  digitalWrite(relaypi,HIGH);
  Serial.println(digitalRead(relaypi));
  delay(5000);
  digitalWrite(relaypi,LOW);
  
  Serial.println(digitalRead(relay2));
  digitalWrite(relay2,HIGH);
  Serial.println(digitalRead(relay2));
  // put your main code here, to run repeatedly:
  delay(5000);
  digitalWrite(relay2,LOW);
  delay(1000);
  
}
