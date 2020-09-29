#ifndef Command_h
#define Command_h

// En class som ska ligga till grunden för ett kommando.
class Command
{
private:

public:

    // Konstruktor och destruktor deklareras s.a. klassen ska bli abstrakt.
    Command() = default;
    ~Command() = default;

    // Funktionen är pure så att child-klasser ska ha
    // krav på att implementera funktionen.
    virtual bool Excecute() = 0;

};

#endif