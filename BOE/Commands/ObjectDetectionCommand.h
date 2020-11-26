#ifndef ObjectDetectionCommand_h
#define ObjectDetectionCommand_h

#include "arduino.h"
#include "../Components/Wheels.h"
#include "../Components/DistanceSensor.h"
#include "../Util/Vec2.h"
#include "Command.h"


class ObjectDetectionCommand : public Command
{
private:

	Wheels* wheels = nullptr;
	DistanceSensor* distanceSensor = nullptr;

public:

	ObjectDetectionCommand(Wheels* wheels, DistanceSensor* distanceSensor);

	virtual bool Excecute() override;
};

#define MAX_OBJECT_WIDTH 40.0f

class Object 
{
public:

	Object() = default;

	Vec2 startPoint;
	Vec2 endPoint;

	void SetStartPoint(const Vec2& startPoint) 
	{
		this->startPoint = startPoint;
	}

	void SetEndPoint(const Vec2& endPoint) 
	{
		this->endPoint = endPoint;
	}

	// Returerar objektetes bredd.
	float GetSize() 
	{
		return startPoint.DistanceTo(endPoint);
	}

	// Beräknar mittpunkten av objektet.
	float GetDirection() 
	{
		// Vektor från origo till mittpunkt.
		Vec2 middlePoint((startPoint.x + endPoint.x) / 2, (startPoint.y + endPoint.y) / 2);

		float angle = Vec2::AngleBetween(Vec2(0,1), middlePoint);

		return angle;
	}

	// Beräknar mittpunkten av objektet.
	float GetDistance()
	{
		// Då boten befinner sig på positionen 0,0 i koordinatsystemet så är längden på vektorn 
		// distansen till origo.
		return Vec2((startPoint.x + endPoint.x) / 2, (startPoint.y + endPoint.y) / 2).Length();
	}
};

#endif