#include "Wheels.h"
#include "arduino.h"

#define PI 3.141592f

Wheels::Wheels(int rightServoPin, int leftServoPin)
{
    rightServo.attach(rightServoPin);
    rightServo.writeMicroseconds(servoBaseSpeed);
    
    leftServo.attach(leftServoPin);
    leftServo.writeMicroseconds(servoBaseSpeed);
}

Wheels::~Wheels()
{
}

void Wheels::AccelerateLinearOneWheel(int currentSpeed, int goalSpeed, int time, bool rightWheel, int timeSteps = 20) 
{
    Servo servo = rightWheel ? rightServo : leftServo;

    goalSpeed = constrain(goalSpeed, -servoMaxSpeed, servoMaxSpeed);

    int timePerStep = time / timeSteps;
    int velPerStep = (goalSpeed - currentSpeed) / timeSteps;
    for (size_t i = 0; i < timeSteps; i++)
    {
        currentSpeed += velPerStep;

        // Minskar farten om vi använder vänster hjul. 
        servo.writeMicroseconds(servoBaseSpeed + currentSpeed);
        delay(timePerStep);
    }

}

void Wheels::AccelerateLinear(int currentSpeed, int goalSpeed, int time, int timeSteps = 20) 
{
    int timePerStep = time / timeSteps;
    int velPerStep = (goalSpeed - currentSpeed) / timeSteps;
    for (size_t i = 0; i < timeSteps; i++)
    {
        currentSpeed += velPerStep;
        rightServo.writeMicroseconds(servoBaseSpeed - currentSpeed);
        leftServo.writeMicroseconds(servoBaseSpeed + currentSpeed);
        delay(timePerStep);
    }

}

void Wheels::ManeuverDistance(int distance, bool backwards = false) 
{
    int timePerStage = (int)((((float)distance)/((float)topVelocity)) * 1000.0f); // Konverterar till millisekunder.
    
    // Vi spenderar den dubbla tiden på att köra(2*timePerStage) för att sträckan som hinner åkas i full
    // hastighet är hälften av den som hinns åka om man accelererar linjärt till topp-hastigheten.
    // Inverterar hastigheten om vi ska backåt.
    AccelerateLinear(0,backwards ? -servoMaxSpeed : servoMaxSpeed, timePerStage);
    AccelerateLinear(backwards ? -servoMaxSpeed : servoMaxSpeed, 0, timePerStage);
    Stop();
}

void Wheels::ManeuverAngle(int angle, bool rightWheel, bool backwards = false) 
{
    float distance = PI * wheelDistance * (angle / 360.0f);
    int timePerStage = (int)(((distance)/((float)topVelocity / 2)) * 1000.0f); // Konverterar till millisekunder.
    
    // Vi spenderar den dubbla tiden på att köra(2*timePerStage) för att sträckan som hinner åkas i full
    // hastighet är hälften av den som hinns åka om man accelererar linjärt till topp-hastigheten.
    AccelerateLinearOneWheel(0, rightWheel || backwards ? -servoMaxSpeed / 2 : servoMaxSpeed / 2, timePerStage, rightWheel);
    AccelerateLinearOneWheel(rightWheel || backwards ? -servoMaxSpeed / 2 : servoMaxSpeed / 2, 0, timePerStage, rightWheel);
    Stop();
}

void Wheels::Maneuver(int speed)
{
    speed = constrain(speed, -servoMaxSpeed, servoMaxSpeed);
    rightServo.writeMicroseconds(servoBaseSpeed - speed);
    leftServo.writeMicroseconds(servoBaseSpeed + speed);
}

void Wheels::Maneuver(int speed, int time)
{
    speed = constrain(speed, -servoMaxSpeed, servoMaxSpeed);

    rightServo.writeMicroseconds(servoBaseSpeed - servoMaxSpeed);
    leftServo.writeMicroseconds(servoBaseSpeed + servoMaxSpeed);
    delay(time);
    Stop();
}

void Wheels::ManeuverTurn(int turnSpeed, int time, bool rightTurn) // Svänger under en given tid.
{
    turnSpeed = constrain(turnSpeed, -servoMaxSpeed, servoMaxSpeed);
    // Om sanningsvärdet av rightTurn är sant så svänger vi åt höger, annars åt vänster. 
    AccelerateLinearOneWheel(0,turnSpeed, time/2, !rightTurn);
    AccelerateLinearOneWheel(turnSpeed, 0, time/2, !rightTurn);
    Stop();
}

void Wheels::Stop() 
{
    rightServo.writeMicroseconds(servoBaseSpeed);
    leftServo.writeMicroseconds(servoBaseSpeed);
}
