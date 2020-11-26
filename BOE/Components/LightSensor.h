#ifndef LightSensor_h
#define LightSensor_h

class LightSensor
{
private:
    int sensorPin = 0;

public:
    LightSensor(int sensorPin);
    ~LightSensor();

    float MeasureLight();
};

#endif