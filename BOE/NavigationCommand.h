#include "Command.h"
#include "Whiskers.h"
#include "Wheels.h"

class NavigationCommand : public Command
{
private:
    Whiskers* whiskers = nullptr;
    Wheels* wheels = nullptr;
public:
    NavigationCommand(Whiskers* whiskers, Wheels* wheels);
    ~NavigationCommand();

    virtual bool Excecute();
};
