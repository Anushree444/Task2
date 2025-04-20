//C++ code
////////////////////////////////
//inputs
int potpin=A5;
int ury=2;
//outputs
int motor = 9; //pwmpin
int dir=4; //dir pin 
////////////////////////////////


int potval; //value
int speed; //value for range change

void setup()
{  
  pinMode(motor, OUTPUT);
  Serial.begin(9600);
  pinMode(potpin, INPUT);
  pinMode(dir, INPUT);
  pinMode(ury, INPUT);
  //since using analog read and write, using only loop for speed
}

void loop()
{
  
  //--------speed control---------
  //pot is reading of A0
  potval=analogRead(potpin);
  //changing range of A0 from 
  speed=map(potval, 0, 1023,0, 255);
  analogWrite(motor, speed);
  //-------direction control-----
char Serial_data=Serial.read();
Serial.println(Serial_data);
Serial.println(potpin);
// Serial.println(speed);
 if(Serial_data=='c')
 {
    digitalWrite(dir,HIGH);
 }
 else if(Serial_data=='d')
 {
  digitalWrite(dir, LOW);

 }
 delay(200);
 //checking pwm value for 0 to 255
}
