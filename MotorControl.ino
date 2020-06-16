#define echoPin 12
#define trigPin 13

#define MotorR1 7 //OUT3 or OUT4
#define MotorR2 6 //OUT4 or OUT3
#define MotorRE 9

#define MotorL1 4 //OUT1 or OUT2
#define MotorL2 5 //OUT2 or OUT1
#define MotorLE 3

long sensorSignalTime, distance;
int motorPower = 255;


void setup() {
  pinMode(echoPin, INPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(MotorR1, OUTPUT);
  pinMode(MotorR2, OUTPUT);
  pinMode(MotorRE, OUTPUT);
  pinMode(MotorL1, OUTPUT);
  pinMode(MotorL2, OUTPUT);
  pinMode(MotorLE, OUTPUT);

  pinMode(11, OUTPUT);
  

}

void loop() {

  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  sensorSignalTime = pulseIn(echoPin, HIGH);
  distance = sensorSignalTime / 29.1 / 2;

  
  if( distance < 15)
  {
    digitalWrite(11, HIGH);
    backwards();
    delay(500);
    right();
    delay(200);
  }
  else
  {
    forward();
    digitalWrite(11, LOW);
  }
  
}

void left()
{
  digitalWrite( MotorR1, HIGH );
  digitalWrite( MotorR2, LOW );
  digitalWrite( MotorRE, motorPower);


  digitalWrite( MotorL1, HIGH );
  digitalWrite( MotorL2, LOW );
  digitalWrite( MotorLE, motorPower);
  
}

void right()
{
  digitalWrite( MotorR1, LOW );
  digitalWrite( MotorR2, HIGH  );
  digitalWrite( MotorRE, motorPower);


  digitalWrite( MotorL1, LOW );
  digitalWrite( MotorL2, HIGH );
  digitalWrite( MotorLE, motorPower);
  
}


void forward()
{
  digitalWrite( MotorR1, HIGH );
  digitalWrite( MotorR2, LOW );
  digitalWrite( MotorRE, motorPower );


  digitalWrite( MotorL1, LOW );
  digitalWrite( MotorL2, HIGH );
  digitalWrite( MotorLE, motorPower );
  
}

void backwards()
{
  digitalWrite( MotorR1, LOW );
  digitalWrite( MotorR2, HIGH );
  digitalWrite( MotorRE, motorPower );


  digitalWrite( MotorL1, HIGH );
  digitalWrite( MotorL2, LOW );
  digitalWrite( MotorLE, motorPower);
  
}
