#ifndef NavigationCommand_h
#define NavigationCommand_h

#include "NavigationCommand.h"
#include "arduino.h"

NavigationCommand::NavigationCommand(Whiskers* whiskers, Wheels* wheels)
{
    this->whiskers = whiskers;
    this->wheels = wheels;
}

NavigationCommand::~NavigationCommand()
{

}

bool NavigationCommand::Excecute() 
{

    if(whiskers == nullptr) // Om vår pekare till spröten är null så returnerar att vi misslyckats med kommandot.
        return false; 

    delay(1000);

    // Nuvarande tid i millisekunder.
    int lastTime = millis();

    int timeSinceTouch = 0;
    
    while(timeSinceTouch < 20000) // Om vi inte vidrört något på 20 sekunderer avbryter vi loopen. 
    {
        // Räknar ut tiden som passerat under senaste loop-varvet.

        int currentTime = millis();
        int dt = currentTime - lastTime;
        lastTime = currentTime;

        bool bIsRightTouching = whiskers->IsWhiskerTouching(R_WHISKER);
        bool bIsLeftTouching = whiskers->IsWhiskerTouching(L_WHISKER);

        if(bIsRightTouching || bIsLeftTouching) // Om något vidrör
        {
            timeSinceTouch = 0;
            
            // Backar.
            wheels->Stop();
            wheels->ManeuverDistance(100, true);
            delay(200);

            if(bIsRightTouching && bIsLeftTouching) // Om båda vidrör.
            {
                wheels->ManeuverAngle(90, true);
            } 
            else if(bIsRightTouching) // Om höger vidrör.
            {
                wheels->ManeuverAngle(90, false);
            } 
            else if(bIsLeftTouching) // Om vänster vidrör.
            {
                wheels->ManeuverAngle(90, true);
            }

        } else
        {
            if(timeSinceTouch == 0) // Vi gör detta då vi endast vi sätta farten om vi inte redan åker.
                wheels->Maneuver(200);

            timeSinceTouch += dt;
        }
        
    }

    wheels->Stop();
    
    return true; // Returnerar att kommandot inte misslyckats.
}

#endif