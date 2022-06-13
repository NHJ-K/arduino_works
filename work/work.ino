int clutch,neul;


#define relay1 8
#define relay2 7

void setup() {
  Serial.begin(9600);
  pinMode(13,INPUT);
  pinMode(12,INPUT);
  pinMode(relay1,OUTPUT);
  pinMode(relay2,OUTPUT);

  digitalWrite(relay1,HIGH);
  // put your setup code here, to run once:

}

void loop() {
  clutch = digitalRead(13);
  neul = digitalRead(12);
  Serial.print("Clutch");
  Serial.println(clutch);
  delay(1000);
  Serial.print("Neu");  
  Serial.println(neul);

  if(neul == 1 && clutch == 0){
    delay(5000);
    digitalWrite(relay1,LOW);
    
  }
  if(digitalRead(relay1) == 0 && clutch == 1){

    digitalWrite(relay2,HIGH);
  }
  // put your main code here, to run repeatedly:
  delay(100);
}
