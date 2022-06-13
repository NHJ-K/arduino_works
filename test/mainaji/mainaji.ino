
#define echoPin 2 // attach pin D2 Arduino to pin Echo of HC-SR04
#define trigPin 3 //attach pin D3 Arduino to pin Trig of HC-SR04
#define Hall_Sensor A0  
#define minspeed 4
#define minhight 10

const int IN1 = 7;
const int IN2 = 6;
const int IN3 = 5;
const int IN4 = 4;

long duration; // variable for the duration of sound wave travel
int distance; // variable for the distance measurement

const int WHEEL_DIAMETER = 18;
const int RPM_SAMPLE_PERIOD = 10;


void setup() {
  pinMode (IN1, OUTPUT);
  pinMode (IN2, OUTPUT);
  pinMode (IN3, OUTPUT);
  pinMode (IN4, OUTPUT);
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(echoPin, INPUT); // Sets the echoPin as an INPUT
  pinMode(Hall_Sensor_D,INPUT);
  Serial.begin(115200); // // Serial Communication is starting with 9600 of baudrate speed
}
void loop() {

  static bool firstTime = true;
  static long thisMagValue = 0;
  static int rpm = 0;
  static long kph = 0;
  static float magnetCount = 0.00;
  static unsigned long timeOld = 0;

  long previousMagValue = thisMagValue;
  thisMagValue = analogRead(Hall_Sensor);

  if(!firstTime){
    int change = abs(thisMagValue-previousMagValue);
    if(change > 1000){
      ++magnetCount;
    }
    if(floor((millis()-timeOld)/1000)/60))>0.01){
      rpm = (magnetCount/2)/(((float)(millis()-timeOld)/1000)/60);
    }
    delay(15);
    kph = ((WHEEL_DIAMETER*PI)*rpm)/1666.67;

    Serial.println("KPH :");
    Serial.print(kph);
    
    
  }
  firstTime = false;

  if(kph<minspeed){
  // Clears the trigPin condition
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
  // Displays the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
   if(distance>minheight){
     while(distance != minhieght){ 
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
     }
    
  }
  }
}
