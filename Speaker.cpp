#include "Speaker.h"
#include "arduino.h"

Speaker::Speaker(int buzzerPin)
{
    this->buzzerPin = buzzerPin;
}

Speaker::~Speaker()
{
}

void Speaker::PlaySong(int notes[], int delays[], int num_notes)
{
    for (size_t i = 0; i < num_notes; i++)
    {
        int duration = 1000/delays[i];
        tone(buzzerPin, notes[i], duration);
        delay(duration*1.30);
        noTone(buzzerPin);
    }

    noTone(buzzerPin);
    digitalWrite(buzzerPin,LOW);
    
}