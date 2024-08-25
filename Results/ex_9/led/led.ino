int pwm=10;
int sensor=5;
int duty;
int counter;

void setup()
{
 duty=127;
 counter=0;
 Serial.begin(9600);
 pinMode(pwm,OUTPUT);
 pinMode(sensor,INPUT);
}

void loop() 
{ 
 if(counter>=200)
 {
 if(duty==10) //90
 {
 duty=250; //200
 }
 else
 {
 duty=10;
 }
 counter=0;
 }
 analogWrite(pwm,duty);
 sensor=analogRead(A5);
 sensor=map(sensor,0,1023,0,255);
 

Serial.println(sensor);

counter ++;

//delay(50);
}
