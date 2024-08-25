#include <PID_v1.h>
double Setpoint, Input, Output , error;
double Kp=7, Ki=100, Kd=0.0001;
int pwm=10;
int sensor=5;
int duty;
int i;
const int sampleRate = 1; // Variable that determines how fast our PID loop runs
PID myPID(&Input, &Output, &Setpoint, Kp, Ki, Kd, DIRECT);
void setup()
{
 int Setpoint=100;
 i = 0;
 duty=127;
 Serial.begin(9600);
 pinMode(pwm,OUTPUT);
 pinMode(sensor,INPUT);
 myPID.SetMode(AUTOMATIC); //Turn on the PID loop 
myPID.SetSampleTime(sampleRate); //Sets the sample rate
}
void loop() 
{


 if( i>= 500)
 {
   if (Setpoint == 100)
   {
   Setpoint = 180;
   }
   else{
     Setpoint = 100;
   }
   i=0;
 }



Input=analogRead(A5);
Input=map(Input,0,1023,0,255);
error=Setpoint-Input;
myPID.Compute(); //Run the PID loop
duty=Output;
analogWrite(pwm,duty);
Serial.print(Input);
Serial.print(" ");
Serial.print(duty);
Serial.print(" ");
Serial.println(error); 

i ++;


}
