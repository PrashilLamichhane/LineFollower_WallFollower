/* 
Author: Sumiran Subedi & Prashil Lamichhane
Date: 2025-07-05
Competition: Battle For Speed 2025 by Robotics Club WRC
*/

// Define pins for IR sensors
#include <NewPing.h>
#define ir1 A1
#define ir2 A5
#define ir3 A0

// Define pins for motor control
#define leftmotor1 6 
#define leftmotor2 7   
#define rightmotor1 8 
#define rightmotor2 9 

// // Define pins for ultrasonic sensor
#define MAX_DISTANCE 200 // Maximum distance to ping (in cm)
#define TRIGGER_PIN_F 12 // Front sensor trigger pin    
#define ECHO_PIN_F 11    // Front sensor echo pin
#define TRIGGER_PIN_L 4  // Left sensor trigger pin
#define ECHO_PIN_L 3    // Left sensor echo pin
#define TRIGGER_PIN_R 2  // Right sensor trigger pin
#define ECHO_PIN_R 13    // Right sensor echo pin

NewPing uleft(TRIGGER_PIN_L, ECHO_PIN_L, MAX_DISTANCE); // NewPing setup of pins and maximum distance.
NewPing ufront(TRIGGER_PIN_F, ECHO_PIN_F, MAX_DISTANCE);
NewPing uright(TRIGGER_PIN_R, ECHO_PIN_R, MAX_DISTANCE);

// Define pins for PWM control
#define pwm1 5 
#define pwm2 10 

int lms = 175  ; // Motor speed kef
int rms = 255; 

void setup() {
    // Set IR sensor pins as inputs
    pinMode(ir1, INPUT); 
    pinMode(ir2, INPUT); 
    pinMode(ir3, INPUT); 
    
    // Set motor control pins as outputs
    pinMode(leftmotor1, OUTPUT); 
    pinMode(leftmotor2, OUTPUT); 
    pinMode(rightmotor1, OUTPUT); 
    pinMode(rightmotor2, OUTPUT);

    // Initialize serial communication for debugging
    Serial.begin(9600); 
}

void loop() {
    unsigned int left = uleft.ping() /US_ROUNDTRIP_CM;
    if (left == 0) left = MAX_DISTANCE;
    unsigned int front = ufront.ping() / US_ROUNDTRIP_CM;
    if (front == 0) left = MAX_DISTANCE;
    unsigned int right = uright.ping() / US_ROUNDTRIP_CM;
    if (right == 0) left = MAX_DISTANCE;

    // Read the states of the IR sensors
    int l = !digitalRead(ir1); 
    int m = !digitalRead(ir2); 
    int r = !digitalRead(ir3); 

    // If the distance is greater than 20 cm, navigate using the IR sensor
    // Decision-making based on IR sensor readings 
    if ((l == 0) && (m =a= 0) && (r == 0) && left < 20 && right < 20) while (1) US();
    else if ((l == 0) && (m == 1) && (r == 0)) forward();
    else if ((l == 0) && (m == 0) && (r == 1)) SturnRight(); 
    else if ((l == 1) && (m == 0) && (r == 0)) SturnLeft();
    else if ((l == 0) && (m == 1) && (r == 1)) turnRight();
    else if ((l == 1) && (m == 1) && (r == 0)) turnLeft(); 
    else if ((l == 0) && (m == 0) && (r == 0)) Back();
}

void US() {
    int wall = 11;
    int error = 2;
    unsigned int left = uleft.ping() / US_ROUNDTRIP_CM;
    if (left == 0) left = MAX_DISTANCE;
    unsigned int front = ufront.ping() / US_ROUNDTRIP_CM;
    if (front == 0) front = MAX_DISTANCE;
    unsigned int right = uright.ping() / US_ROUNDTRIP_CM;
    if (right == 0) right = MAX_DISTANCE;
 
    
    if (front < 9)
    {
        Back();
    }
    else if (left < 5)
    {
        SturnRight();
    }
    else if (right < 5)
    {
        SturnLeft();
    }
    else if ((left > wall - error || left < wall + error) && front > 15 && (right > wall - error || right < wall + error)) //010
    {
        forward();
    } else if (left < 9 && front > 15) // 100
    {
        SturnRight();
        delay(100);
    } else if (front > 15 && right < 9) //001
    {
        SturnLeft();
        delay(100);
    } else if (left > 25 && front < 15) //110
    {
        turnLeft();
        delay(250);
    } else if (right > 25 && front < 15) //011
    {
        turnRight();
        delay(250);
    }

    delay(50);
}


// Function to move the robot forward
void forward() { 
    analogWrite(pwm1, lms); // Set speed for left motor
    analogWrite(pwm2, rms); // Set speed for right motor
    digitalWrite(leftmotor1, HIGH);  
    digitalWrite(leftmotor2, LOW); 
    digitalWrite(rightmotor1, HIGH); 
    digitalWrite(rightmotor2, LOW);  
} 

// Function to slightly turn the robot left
void SturnLeft() { 
    analogWrite(pwm1, 70); // Set speed for left motor
    analogWrite(pwm2, rms); // Set speed for right motor
    digitalWrite(leftmotor1, HIGH); 
    digitalWrite(leftmotor2, LOW); 
    digitalWrite(rightmotor1, HIGH); 
    digitalWrite(rightmotor2, LOW); 
} 

// Function to turn the robot left
void turnLeft() {  
    analogWrite(pwm1, lms); // Set speed for left motor
    analogWrite(pwm2, rms); // Set speed for right motor
    digitalWrite(leftmotor1, LOW);  
    digitalWrite(leftmotor2, LOW); 
    digitalWrite(rightmotor1, HIGH); 
    digitalWrite(rightmotor2, LOW); 
} 

// Function to slightly turn the robot right
void SturnRight() {
    analogWrite(pwm1, lms); // Set speed for left motor
    analogWrite(pwm2, 120); // Set speed for right motor
    digitalWrite(leftmotor1, HIGH); 
    digitalWrite(leftmotor2, LOW); 
    digitalWrite(rightmotor1, HIGH); 
    digitalWrite(rightmotor2, LOW); 
} 

// Function to turn the robot right
void turnRight() { 
    analogWrite(pwm1, lms); // Set speed for left motor
    analogWrite(pwm2, rms); // Set speed for right motor
    digitalWrite(leftmotor1, HIGH); 
    digitalWrite(leftmotor2, LOW); 
    digitalWrite(rightmotor1, LOW); 
    digitalWrite(rightmotor2, LOW); 
}  

// Function to move the robot backward
void Back() {   
    analogWrite(pwm1, lms-30); // Set speed for left motor
    analogWrite(pwm2, rms-50); // Set speed for right motor
    digitalWrite(leftmotor1, LOW); 
    digitalWrite(leftmotor2, HIGH); 
    digitalWrite(rightmotor1, LOW); 
    digitalWrite(rightmotor2, HIGH); 
}