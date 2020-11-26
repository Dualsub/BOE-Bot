#include "ObjectDetectionCommand.h"

#define INCREMENT 90
#define MAX_DISTANCE 100.0f
#define MIN_DISTANCE 40.0f
#define FIELD_OF_VIEW 120.0f

ObjectDetectionCommand::ObjectDetectionCommand(Wheels* wheels, DistanceSensor* distanceSensor)
{
	this->wheels = wheels;
    this->distanceSensor = distanceSensor;
}

bool ObjectDetectionCommand::Excecute()
{
    if(wheels == nullptr || distanceSensor == nullptr)
        return false;


    wheels->DetachWheels();

    int maxAngle = 90 + (FIELD_OF_VIEW / 2);
    int minAngle = 90 - (FIELD_OF_VIEW / 2);

    int angle = minAngle;
    //Kontrollerar om vinkeln inkrementeras eller dekrementeras.
    int sign = 1;

    // Sätter vinkeln till 0 då servon kan vara i en annan vinkel vid start.
    distanceSensor->SetAngle(angle);
    delay(1000);

    Serial.println(String(0) + "," +  String(0));
    Serial.println(String(0) + "," +  String(MAX_DISTANCE));
    Serial.println(String(MAX_DISTANCE / 2) + "," +  String(0));
    Serial.println(String(-MAX_DISTANCE / 2) + "," +  String(0));
    
    Object objectBuffer[32];
    int currentIndex = 0;
    Vec2 lastPoint;
    bool nextStart = false;
    // Scan

    for(int i = 0; i < (3 * INCREMENT); i++) 
    {
        angle += (sign * FIELD_OF_VIEW / INCREMENT);
        sign *= (angle >= maxAngle || angle <= minAngle ? -1 : 1); 
        angle = constrain(angle, minAngle, maxAngle);
        distanceSensor->SetAngle(angle);

        delay((FIELD_OF_VIEW / INCREMENT) * 10);
        
        float distance = distanceSensor->MeasureDistance();
        if(distance < MAX_DISTANCE && distance > MIN_DISTANCE)
        {
            Vec2 point = Vec2::FromPolar(angle, distance);
            Serial.println(String(point.x) + "," +  String(point.y));

            // Om objektet är det första vi ser sker ingen utvärdering.
            if(currentIndex <= 0 || nextStart) 
            {
                objectBuffer[currentIndex].SetStartPoint(point);
                lastPoint = point;
                nextStart = false;
            }

            // Kvadraten jämförs p.g.a kostamhet av roten-ur-operationer.
            if(lastPoint.DistanceToSquared(point) > (MAX_OBJECT_WIDTH * MAX_OBJECT_WIDTH)) 
            {
                objectBuffer[currentIndex].SetEndPoint(point);
                currentIndex++;
                nextStart = true;
            }
        }
    }

    distanceSensor->DetchServo();

    // Beräknar det största objektet.

    float largestWidth = 0.0;
    int largestIndex = -1;

    for(size_t i = 0; i < currentIndex + 1; i++) 
    {
        float width = objectBuffer[i].GetSize();
        if(width > largestWidth) 
        {
            largestIndex = i;
        }
    }

    // Vinkeln mellan y-axeln (framåtriktning) och objektets mittpunkt.
    float direction = objectBuffer[largestIndex].GetDirection();
    // Konverterar även från centimeter till millimeter.
    float distance = objectBuffer[largestIndex].GetDistance() / 10;
    wheels->AttachWheels();
    wheels->ManeuverAngle(direction, true);
    wheels->ManeuverDistance(distance);

    Serial.println(":exit:");
    return true;

}

