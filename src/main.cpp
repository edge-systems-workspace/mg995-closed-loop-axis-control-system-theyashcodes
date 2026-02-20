/**
* @file main.cpp
 * @brief Closed-loop control system for MG995 servo motor
 * @author Yash Gupta
 * @date 2026-02-20
 */

#include <Arduino.h>
#include <Servo.h>

#define SERVO_PIN 9
#define FEEDBACK_PIN A0

Servo servoMotor;

void setup() {
    Serial.begin(9600);
    servoMotor.attach(SERVO_PIN);
}

void loop() {
    int feedbackValue = analogRead(FEEDBACK_PIN);
    int targetAngle = map(feedbackValue, 0, 1023, 0, 180);

    servoMotor.write(targetAngle);

    Serial.print("Feedback: ");
    Serial.print(feedbackValue);
    Serial.print(" | Angle: ");
    Serial.println(targetAngle);

    delay(100);
}