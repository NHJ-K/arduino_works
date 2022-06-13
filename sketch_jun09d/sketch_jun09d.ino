int clutch,neul;

#define clupin 4
#define neupin 7
#define relay1 13
#define relay2 12

void setup() {
  Serial.begin(9600);
  pinMode(clupin,INPUT);
  pinMode(neupin,INPUT);
  pinMode(relay1,OUTPUT);
  pinMode(relay2,OUTPUT);
  pinMode(7,INPUT);
  // put your setup code here, to run once:
digitalWrite(relay1,0);
}

void loop() {
  digitalWrite(relay1,LOW);
  digitalWrite(relay2,HIGH);
  //clutch = digitalRead(4);
  neul = digitalRead(7);

  //Serial.println(clutch);
  Serial.println(neul);
  delay(1000);
  // put your main code here, to run repeatedly:

}
