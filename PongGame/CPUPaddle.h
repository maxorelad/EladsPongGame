#pragma once

#include "Paddle.h"
#include "Ball.h"

class CPUPaddle : public Paddle
{
public:
    void Update(const Ball& ball) {
        // Move the paddle towards the ball
        if (y + height / 2 < ball.y) {
            y += speed;
        }
        else if (y + height / 2 > ball.y) {
            y -= speed;
        }

        // Ensure the paddle stays within screen bounds
        LimitMovement();
    }
};
