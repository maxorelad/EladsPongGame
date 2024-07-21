#pragma once
#include "raylib.h"
class Paddle
{
protected:
	void LimitMovement() {
		if (y < 0) {
			y = 0;
		}
		else if (y > GetScreenHeight() - height) {
			y = GetScreenHeight() - height;
		}
	}
public:
	float x, y;
	int speed;
	float width, height;

	Paddle(float x=10, float y=0, int speed=6, float width=25, float height=120) :x(x), y(y), speed(speed), width(width), height(height) {}

	void Draw() const {
		DrawRectangle(x, y, width, height, WHITE);
	}

	void Update() {
		if (IsKeyDown(KEY_UP))
		{
			y -= speed;
		}
		if (IsKeyDown(KEY_DOWN))
		{
			y += speed;
		}
		LimitMovement();
	}
};

