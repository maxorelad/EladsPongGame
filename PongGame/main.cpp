#include <iostream>
#include "raylib.h"
#include "Ball.h"
#include "Paddle.h"
#include "CPUPaddle.h"
#include <chrono>

void CheckCollision(Ball& ball, const Paddle& pad);

int main() {
    std::cout << "Starting the game" << std::endl;

    const int screenWidth{ 1280 };
    const int screenHeight{ 800 };

    InitWindow(screenWidth, screenHeight, "Elad's Pong Game");
    SetTargetFPS(60);

    Ball ball;
    CPUPaddle cpu;
    cpu.x = screenWidth - 10 - cpu.width;
    cpu.y = static_cast<float>(screenHeight) / 2 - cpu.height / 2;

    Paddle player0;
    player0.x = 10;
    player0.y = static_cast<float>(screenHeight) / 2 - player0.height / 2;

    int playerScore{};
    int cpuScore{};

    Color DarkGreen = Color{ 20, 160, 133, 255 };
    // Get the current time before the operation
    auto startTime = std::chrono::high_resolution_clock::now();
    auto currentTime = std::chrono::high_resolution_clock::now();
    double elapsedTime{};
    std::chrono::duration<double> frameTime{};
    while (!WindowShouldClose()) {
        // Updating
        ball.Update();
        player0.Update();
        cpu.Update(ball);
        CheckCollision(ball, cpu);
        CheckCollision(ball, player0);
        currentTime = std::chrono::high_resolution_clock::now();
        frameTime = currentTime - startTime;
        elapsedTime = frameTime.count();
        if (ball.isPoint()) {
            if ((ball.x >= GetScreenWidth() - ball.radius)) ++playerScore;
            else ++cpuScore;
            ball.ResetBall();
            startTime = std::chrono::high_resolution_clock::now();
        }
        if (elapsedTime >= 8.0) {
            ball.speedX += (ball.speedX > 0) ? 1 : -1;
            ball.speedY += (ball.speedY > 0) ? 1 : -1;
            startTime = std::chrono::high_resolution_clock::now();
        }
       
        // Drawing
        BeginDrawing();
        ClearBackground(DarkGreen);

        ball.Draw();
        player0.Draw();
        cpu.Draw();
        DrawText(TextFormat("%i", playerScore), screenWidth / 4 - 20, 20, 80, WHITE);
        DrawText(TextFormat("%i", cpuScore), 3 * screenWidth / 4 - 20, 20, 80, WHITE);
        DrawLine(screenWidth / 2, 0, screenWidth / 2, screenHeight, WHITE);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}

void CheckCollision(Ball& ball, const Paddle& pad) {
    if (CheckCollisionCircleRec(Vector2{ ball.x, ball.y }, ball.radius, Rectangle{ pad.x, pad.y, pad.width, pad.height })) {
        ball.speedX *= -1;
    }
}
