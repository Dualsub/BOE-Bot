#include "Commands/Command.h"
#include "Commands/ObjectDetectionCommand.h"

#include "Components/Wheels.h"
#include "Components/Speaker.h"
#include "Components/Whiskers.h"
#include "Components/DistanceSensor.h"

#include "Audio/Notes.h"

#define BUZZER_PIN 4
#define RSERVO_PIN 12
#define LSERVO_PIN 13
#define DISTANCESENSOR_SEVO 10
#define DISTANCESENSOR 11

void setup() 
{
    Serial.begin(9600);

    // Instantierar de klasser som interagerar med hårdvaran. 
    Wheels* wheels = new Wheels(RSERVO_PIN, LSERVO_PIN);
    Speaker* speaker = new Speaker(BUZZER_PIN);
    DistanceSensor* distanceSensor = new DistanceSensor(DISTANCESENSOR, DISTANCESENSOR_SEVO);

    // Instantierar kommandot.
    Command* command = new ObjectDetectionCommand(wheels, distanceSensor);

    // Exikverar kommandot.
    command->Excecute();

    wheels->AttachWheels();
    wheels->ManeuverAngle(5, true);
    wheels->ManeuverDistance(500);

    //Spelar toner från speakern för att meddela att kommandot är avslutat.
    int tones[] = { NOTE_C5, NOTE_C5 };
    int durations[] = { 8, 1 };
    speaker->PlaySong(tones, durations, 2);

    // Frigör objekten som pekarna pekar på från minnet.
    delete command;
    delete wheels;
    delete speaker;
    delete distanceSensor;
}

void loop() {}