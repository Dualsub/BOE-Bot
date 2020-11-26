#pragma once

#include "arduino.h"

#define PI 3.141592f

struct Vec2
{
public:
    float x = 0.0f;
    float y = 0.0f;

    Vec2() = default;

    Vec2(float x, float y) {
        this->x = x;
        this->y = y;
    }

    Vec2 Add(const Vec2& other) 
    {
        return Vec2(x + other.x, y + other.y);
    }

    Vec2 Subtract(const Vec2& other) 
    {
        return Vec2(x - other.x, y - other.y);
    }

    float Length() 
    {
        return sqrt((x*x) + (y*y));
    }

    float LengthSquared() 
    {
        return (x*x) + (y*y);
    }

    // Har detta alternativ då en roten-ur operation är kostam.
    float DistanceToSquared(const Vec2& other) 
    {
        float dx = (other.x - x);
        float dy = (other.y - y);
        return dx*dx + dy*dy;
    }
    
    // Kostsamt
    float DistanceTo(const Vec2& other) 
    {
        return sqrt(DistanceToSquared(other));
    }

    // Skalärprodukten mellan denna instans och en annan.
    static float ScalerProduct(const Vec2& pointA, const Vec2& pointB) 
    {
        return (pointA.x * pointB.x) + (pointA.y * pointB.y);
    }

    static Vec2 FromPolar(float angle, float distance, bool degrees = true) 
    {
        if(degrees) 
        {
            angle = (((float)angle) / 360.0f) * (PI * 2.0f);
        }

        return Vec2(distance * cos(angle), distance * sin(angle));
    }

    // Returnerar en vinkel mellan vertorerna baserat på skalärprodukt och längd.
    static float AngleBetween(const Vec2& pointA, const Vec2& pointB, bool degrees = true) 
    {
        float scalarProduct = ScalerProduct(pointA, pointB);
        float lengths = pointA.Length() * pointB.Length();
        
        float angle = acos(scalarProduct / lengths);

        if(degrees) 
        {
            angle = (((float)angle) / (PI * 2.0f)) * 360;
        }

        return angle;
    }

};
