
#ifndef Wheels_h
#define Wheels_h

#include <Servo.h>

class Wheels
{
private:
    Servo rightServo;
    Servo leftServo;



public:
    //Konstanter gällande robotens dimmentioner och egenskaper. 
    const int servoBaseSpeed = 1500;
    const int servoMaxSpeed = 200;
    const int wheelDistance = 114;
    const int wheelDiameter = 68;
    const int topVelocity = 237;

    Wheels(int rightServoPin, int leftServoPin);
    ~Wheels();
    
    void AccelerateLinear(int currentSpeed, int goalSpeed, int time, int timeSteps = 20);
    void AccelerateLinearOneWheel(int currentSpeed, int goalSpeed, int time, bool rightWheel, int timeSteps = 20);
    
    // Åker en viss sträcka med linjär acceleration, sträckan anges i mm.
    void ManeuverDistance(int distance, bool backwards = false);

    // Åker en viss sträcka med linjär acceleration, sträckan anges i mm.
    void ManeuverAngle(int angle, bool rightWheel, bool backwards = false);
    
    void ManeuverTurn(int turnSpeed, int time, bool rightTurn);
    
    void Maneuver(int speed, int time);
    void Maneuver(int speed);
    void Stop();
};

#endif