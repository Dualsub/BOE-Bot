#include "Whiskers.h"
#include "arduino.h"

Whiskers::Whiskers(int rightWhiskerPin, int leftWhiskerPin)
{
    this->rightWhiskerPin = rightWhiskerPin;
    this->leftWhiskerPin = leftWhiskerPin;

    pinMode(rightWhiskerPin, INPUT);
    pinMode(leftWhiskerPin, INPUT);

}

Whiskers::~Whiskers()
{

}

bool Whiskers::IsWhiskerTouching(bool right) 
{
    // Om vi vill ha värdet från höger sprött(right == true) så returnerar vi om den vidrör eller inte,
    // om right == true så returnerar vi om vänster vidrör något.
    return right ? digitalRead(rightWhiskerPin) == 0 :  digitalRead(leftWhiskerPin) == 0;
}


