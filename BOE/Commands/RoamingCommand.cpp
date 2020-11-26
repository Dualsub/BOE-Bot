#include "RoamingCommand.h"
#include "arduino.h"

#define VOLTS_THRESHOLD 1.0f

#define DEBUG false

RoamingCommand::RoamingCommand(IrSensor* irSensor, LightSensor* lightSensor, Wheels* wheels) 
{
    this->irSensor = irSensor;
    this->wheels = wheels;
    this->lightSensor = lightSensor;
}

RoamingCommand::~RoamingCommand() 
{
    
}

bool RoamingCommand::Excecute() 
{
    wheels->Stop();
    wheels->AccelerateLinear(0,200, 30);

    while(true) 
    {
        if(lightSensor->MeasureLight() >= VOLTS_THRESHOLD) 
        {
            wheels->Stop();
            break;
        }

        bool right = irSensor->IsObjectDetected(true);
        bool left = irSensor->IsObjectDetected(false);

#if DEBUG
        String leftValue = right ? "O" : "_";
        String rightValue = left ? "O" : "_";
        Serial.println(leftValue+"  "+rightValue);
#endif

        if(right && left)
        {
            wheels->AccelerateLinear(200,0, 500);
            wheels->ManeuverAngle(115, true);
            wheels->AccelerateLinear(0,200, 500);
        }
        else if(!right && !left)
        {
            wheels->AccelerateLinear(200,0, 500);
            wheels->ManeuverAngle(140, false);
            wheels->AccelerateLinear(0,200, 500);
        }
    }
    
    return true;
}