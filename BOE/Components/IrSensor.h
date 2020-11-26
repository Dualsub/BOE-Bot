#ifndef IrSensor_h
#define IrSensor_h

#define NUM_INTERATIONS 30

class IrSensor
{
private:

	int rightSensorPin = 0;
	int leftSensorPin = 0;
	int leftReceiverPin = 0;
	int rightReceiverPin = 0;

	int defaultFreq = 38000;

	const float threshold = 0.8f;

	bool IrDectet(int sensorPin, int receiverPin, int freq);

public:

	IrSensor(int rightSensorPin, int leftSensorPin, int leftReceiverPin, int rightReceiverPin);

	bool IsObjectDetected(bool right);
	
};

#endif