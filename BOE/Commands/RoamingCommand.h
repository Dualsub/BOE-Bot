#ifndef RoamingCommand_h
#define RoamingCommand_h

#include "Command.h"
#include "IrSensor.h"
#include "LightSensor.h"
#include "Wheels.h"
#include "arduino.h"

class RoamingCommand : public Command
{
private:
    IrSensor* irSensor = nullptr;
    Wheels* wheels = nullptr;
    LightSensor* lightSensor = nullptr;
    
public:

    virtual bool Excecute() override;

    RoamingCommand(IrSensor* irSensor, LightSensor* lightSensor, Wheels* wheels);
    ~RoamingCommand();
};


#endif