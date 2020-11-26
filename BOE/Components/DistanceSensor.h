#ifndef DistanceSensor_h
#define DistanceSensor_h

#include "arduino.h"
#include <Servo.h>

class DistanceSensor
{
private:

	Servo sensorServo;
	int servoPin = 0;
	int sensorPin = 0;

public:
	DistanceSensor(int sensorPin, int servoPin);

	void SetAngle(int angle);
	int GetAngle(bool degrees = false);

	float MeasureDistance(int interations = 1);

	void DetchServo();

};

#endif