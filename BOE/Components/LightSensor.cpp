#include "LightSensor.h"
#include "arduino.h"

LightSensor::LightSensor(int sensorPin)
{
    this->sensorPin = sensorPin;
}

LightSensor::~LightSensor()
{

}

float LightSensor::MeasureLight() 
{
    return float(analogRead(sensorPin)) * 5 / 1024.0f;
}