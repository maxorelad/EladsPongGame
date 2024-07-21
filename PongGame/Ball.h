#pragma once

#include "raylib.h"

class Ball
{
public:
    float x;
    float y;
    int speedX;
    int speedY;
    int radius;

    Ball(float x = static_cast<float>(GetScreenWidth()) / 2,
        float y = static_cast<float>(GetScreenHeight()) / 2,
        int speedX = 7,
        int speedY = 7,
        int radius = 20)
        : x(x), y(y), speedX(speedX), speedY(speedY), radius(radius)
    {
    }

    void Draw() const {
        DrawCircle(x, y, radius, WHITE);
    }

    void Update() {
        x += speedX;
        y += speedY;
        if ((y >= GetScreenHeight() - radius) || (y <= radius)) {
            speedY = -speedY;
        }
    }

    bool isPoint() const {
        return((x >= GetScreenWidth() - radius) || (x <= radius));
    }

    void ResetBall() {
        x = GetScreenWidth() / static_cast<float>(2);
        y = GetScreenHeight() / static_cast<float>(2);
        int directon[]{ 1,-1 };
        speedX = 7*directon[GetRandomValue(0, 1)];
        speedY = 7*directon[GetRandomValue(0, 1)];
    }
    
};
