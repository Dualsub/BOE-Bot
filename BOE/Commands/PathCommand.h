#ifndef PathCommand_h
#define PathCommand_h

#include "Command.h"
#include "Wheels.h"
#include "Speaker.h"
#include "arduino.h"

class PathCommand : public Command
{
private:
    // Pekare till objekt vars funktionalitet krävs för att utföra kommandot.
    Wheels* wheels = nullptr;
    Speaker* speaker = nullptr;
    String* sequence;
    size_t sequenceLength = 0;
public:
    PathCommand(Wheels* wheels, Speaker* speaker, String* sequence, size_t sequenceLength);
    ~PathCommand();

    virtual bool Excecute() override;

};

#endif