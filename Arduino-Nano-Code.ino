
int x_axis = 0;  // This variable will store the movement of x-axis in accelerometer
int y_axis = 0;  // This variable will store the movement of y-axis in accelerometer
int forward = 9; // Digital pin on Arduino to send the forward command signal
int backward = 10; // Digital pin on Arduino to send the backward command signal
int right = 11;   // Digital pin on Arduino to send the right turn command signal
int left = 12;    // Digital pin on Arduino to send the left turn command signal

void setup()   // This code will run once the program is executed
{
 pinMode(A0, INPUT);      // Set A0 pin mode as Input
 pinMode(A3, INPUT);      // Set A3 pin mode as Input
 pinMode(forward, OUTPUT);  // Set this pin mode as Output
 pinMode(backward, OUTPUT); // Set this pin mode as Output
 pinMode(right, OUTPUT);    // Set this pin mode as Output
 pinMode(left, OUTPUT);     // Set this pin mode as Output
 Serial.begin(9600);   // Begin the serial communication at 9600 baud rate.
}

void loop()   // This code will run repeatedly until the program is executed.
{
 x_axis = analogRead(A0);  // Read the A0 pin and store the integer value in x_axis variable
 y_axis = analogRead(A3);  // Read the A3 pin and store the integer value in y_axis variable
 Serial.print(" X = ");    // Print this heading
 Serial.println(x_axis);   // Print the value of X-axis movement
 Serial.print(" Y = ");    // Print this heading
 Serial.println(y_axis);   // Print the value of Y-axis movement
 
 if (y_axis >= 390)     // If movement of y-axis has value greater than or equal to 390
 {
   Serial.println("Forward");   // Print this command heading
   digitalWrite(forward, HIGH);  // Set the forward pin - 9 HIGH
 }
 else    // Otherwise
 {
   if (y_axis <= 310)   // If movement of y-axis has value less than or equal to 310
   {
     Serial.println("BACK");      // Print this command heading
     digitalWrite(backward, HIGH); // Set the backward pin - 10 HIGH
   }
   else    // Otherwise
   {
     if (x_axis >= 380)   // If movement of x-axis has value greater than or equal to 380
     {
       Serial.println("RIGHT");    // Print this command heading
       digitalWrite(right, HIGH);  // Set the right pin - 11 HIGH
     }
     else    // Otherwise
     {
       if (x_axis <= 320)   // If movement of x-axis has value less than or equal to 320
       {
         Serial.println("LEFT");   // Print this command heading
         digitalWrite(left, HIGH);  // Set the left pin - 12 HIGH
       }
       Serial.println(" ");   // Print the space
     }
   }
 }
 delay(200);   // Delay of 200 microseconds
 if (x_axis > 320 && x_axis < 380 && y_axis > 310 && y_axis < 390)  // If this condition satisfies
 {
   digitalWrite(forward, LOW);  // Make forward pin low
   digitalWrite(backward, LOW); // Make backward pin low
   digitalWrite(right, LOW);   // Make right pin low
   digitalWrite(left, LOW);   // Make left pin low
 }
}
