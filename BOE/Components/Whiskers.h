#ifndef Whiskers_h
#define Whiskers_h


#define R_WHISKER true
#define L_WHISKER false

class Whiskers
{
private:
    int leftWhiskerPin = 0;
    int rightWhiskerPin = 0;
public:
    Whiskers(int rightWhiskerPin, int leftWhiskerPin);
    ~Whiskers();

    bool IsWhiskerTouching(bool right);
};

#endif