#include "IrSensor.h"
#include "arduino.h"

IrSensor::IrSensor(int rightSensorPin, int leftSensorPin, int rightReceiverPin, int leftReceiverPin) 
{
    this->rightSensorPin = rightSensorPin;
    this->leftSensorPin = leftSensorPin;
    this->rightReceiverPin = rightReceiverPin;
    this->leftReceiverPin = leftReceiverPin;

    pinMode(rightSensorPin, OUTPUT);
    pinMode(leftSensorPin, OUTPUT);
    pinMode(rightReceiverPin, INPUT);
    pinMode(leftReceiverPin, INPUT);
}

bool IrSensor::IrDectet(int sensorPin, int receiverPin, int freq) 
{
    tone(sensorPin, freq, 8);
    delay(1);
    int ir = digitalRead(receiverPin);
    delay(1);
    return ir;
}

bool IrSensor::IsObjectDetected(bool right) 
{
    int sensorPin = right ? rightSensorPin : leftSensorPin;
    int receiverPin = right ? rightReceiverPin : leftReceiverPin;
    
    float sum = 0.0;
    for (size_t i = 0; i < NUM_INTERATIONS; i++)
    {
        sum += float(IrDectet(sensorPin, receiverPin, defaultFreq));
    }
    
    return (sum / NUM_INTERATIONS) < threshold;
}

