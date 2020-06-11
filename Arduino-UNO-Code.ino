
#include<AFMotor.h>   // Include motor shield library

AF_DCMotor motor_right(3);  // Define right pair of motors on channel 3
AF_DCMotor motor_left(4);   // Define left pair of motors on channel 3

int forward;    // This variable will store the value of movement in forward direction
int backward;   // This variable will store the value of movement in backward direction
int right;      // This variable will store the value of movement in right direction
int left;       // This variable will store the value of movement in left direction

void setup()      // This code will run once the program is executed
{
 pinMode(A2,INPUT);   // Set A2 pin mode as Input 
 pinMode(A3,INPUT);   // Set A3 pin mode as Input 
 pinMode(A4,INPUT);   // Set A4 pin mode as Input 
 pinMode(A5,INPUT);   // Set A5 pin mode as Input
  
 Serial.begin(9600);  // Begin the serial communication at 9600 baud rate.
 
 motor_right.setSpeed(255);  // Set the speed of right pair of motors as full
 motor_left.setSpeed(255);   // Set the speed of left pair of motors as full
 motor_right.run(RELEASE);   // Do not turn right pair of motors
 motor_left.run(RELEASE);    // Do not turn left pair of motors
}

void loop()   // This code will run repeatedly until the program is executed.
{
  forward=digitalRead(A2);  // Read the digital state A2 pin and store the value in forward variable
  backward=digitalRead(A3); // Read the digital state A3 pin and store the value in backward variable
  right=digitalRead(A4);    // Read the digital state A4 pin and store the value in right variable
  left=digitalRead(A5);     // Read the digital state A4 pin and store the value in left variable
  
   if(forward==HIGH)       // If the state of the forward variable is HIGH
    {
     motor_right.run(FORWARD);  // Run the right pair of motors in forward direction
     motor_left.run(FORWARD);   // Run the left pair of motors in forward direction
     Serial.println("Forward"); // Print this command heading
    }
   if(backward==HIGH)    // If the state of the backward variable is HIGH
    {       
     motor_right.run(BACKWARD);  // Run the right pair of motors in backward direction
     motor_left.run(BACKWARD);   // Run the left pair of motors in backward direction
     Serial.println("Reverse");  // Print this command heading
    }
    if(right==HIGH)     // If the state of the right variable is HIGH
     {
      motor_right.run(FORWARD);  // Run the right pair of motors in forward direction
      motor_left.run(RELEASE);   // Do not run the left pair of motors.
      Serial.println("RIGHT");   // Print this command heading
     }
     if(left==HIGH)    // If the state of the right variable is HIGH
      {
       motor_right.run(RELEASE);  // Do not run the right pair of motors.
       motor_left.run(FORWARD);   // Run the left pair of motors in forward direction
       Serial.println("LEFT");    // Print this command heading
      }
   if(left==LOW&&right==LOW&&forward==LOW&&backward==LOW)  // if all variables have low state
   {
       motor_right.run(RELEASE);   // Do not run right pair of motors
       motor_left.run(RELEASE);    // Do not run left pair of motors
   }
   delay(100);   // delay of 100 micro-seconds
   
}
