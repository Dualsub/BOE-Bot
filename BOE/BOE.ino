#include "Command.h"
#include "PathCommand.h"
#include "NavigationCommand.h"

#include "Wheels.h"
#include "Speaker.h"
#include "Whiskers.h"

#include "Notes.h"

#define BUZZER_PIN 4
#define RSERVO_PIN 12
#define LSERVO_PIN 13
#define RWHISKER_PIN 5
#define LWHISKER_PIN 7
#define BUTTON_PIN 9

void setup() 
{

    Serial.begin(9600);

    // Instantierar de klasser som interagerar med hårdvaran. 
    Wheels* wheels = new Wheels(RSERVO_PIN, LSERVO_PIN);
    Speaker* speaker = new Speaker(BUZZER_PIN);
    Whiskers* whiskers = new Whiskers(RWHISKER_PIN, LWHISKER_PIN);

    // Väntar tills ett känseltrött aktiverats.
    while(!(whiskers->IsWhiskerTouching(R_WHISKER) || whiskers->IsWhiskerTouching(L_WHISKER))) {} // Vänta på knapptryckning från användaren.

    Command* command = nullptr;

    if(whiskers->IsWhiskerTouching(R_WHISKER)) // Väljer vilken typ av kommando vi ska exikvera baserat.
    {
        String seq[] = { "f180", "rf158", "f45", "lf158", "f200", "s", "rf90", "lb90", "f180", "rf158", "f45", "lf158", "f200" };
        Serial.println((sizeof(seq) / sizeof(String)));
        command = new PathCommand(wheels, speaker, seq, (sizeof(seq) / sizeof(String)));
    } 
    else if(whiskers->IsWhiskerTouching(L_WHISKER))
    {
        command = new NavigationCommand(whiskers, wheels);
    }

    // Exikverar kommandot.
    command->Excecute();

    //Spelar toner från speakern för att meddela att kommandot är avslutat.
    int tones[] = { NOTE_C5, NOTE_C5 };
    int durations[] = { 8, 1 };
    speaker->PlaySong(tones, durations, 2);

    // Frigör objekten som pekarna pekar på från minnet.
    delete command;
    delete wheels;
    delete speaker;
    delete whiskers;
}

void loop() {}