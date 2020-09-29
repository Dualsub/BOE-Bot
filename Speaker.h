
#ifndef Speaker_h
#define Speaker_h

class Speaker
{
private:
    int buzzerPin = 0;
public:
    Speaker(int buzzerPin);
    ~Speaker();

    void PlaySong(int notes[], int delays[], int num_notes);
};

#endif
