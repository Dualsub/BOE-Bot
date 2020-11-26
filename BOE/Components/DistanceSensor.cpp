#include "DistanceSensor.h"

DistanceSensor::DistanceSensor(int sensorPin, int servoPin) 
{
    // Detach om servo redan är attached.
    if(sensorServo.attached()) 
    {
        sensorServo.detach();
    }

    sensorServo.attach(servoPin);
    this->sensorPin = sensorPin;
}

float DistanceSensor::MeasureDistance(int interations = 1)
{
    float sum = 0;
    for(int i = 0; i < interations; i++) 
    {
        pinMode(sensorPin, OUTPUT);
        digitalWrite(sensorPin, LOW);
        delayMicroseconds(2);
        digitalWrite(sensorPin, HIGH);
        delayMicroseconds(5);
        digitalWrite(sensorPin, LOW);
        pinMode(sensorPin, INPUT);
        unsigned long duration = pulseIn(sensorPin, HIGH);
        sum += 2.54f * (duration / 74 / 2);
    }

    return sum / interations;
}

int DistanceSensor::GetAngle(bool degrees) 
{
    return sensorServo.read();
}

void DistanceSensor::SetAngle(int angle)
{
    // Försäring om att vinkeln är mellan 0 och 180 grader.
    angle = constrain(angle, 0, 180);
	sensorServo.write(angle);
}

void DistanceSensor::DetchServo()
{
    if(sensorServo.attached())
        sensorServo.detach();
}

