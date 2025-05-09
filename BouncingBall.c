#include "raylib.h"

int main() {
    const int screenWidth = 1910;
    const int screenHeight = 1070;
    InitWindow(screenWidth, screenHeight, "raylib is awesome!");

    Vector2 ballPosition = { screenWidth / 2, screenHeight / 2 };
    Vector2 ballSpeed = { 10, 10 };
    int ballRadius = 45;
    Color ballColor = RED;

    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        ballPosition.x += ballSpeed.x;
        ballPosition.y += ballSpeed.y;

        if (ballPosition.x <= ballRadius || ballPosition.x >= screenWidth - ballRadius) {
            ballSpeed.x *= -1;
            ballColor = (Color){ GetRandomValue(0, 255), GetRandomValue(0, 255), GetRandomValue(0, 255), 255 };
        }
        if (ballPosition.y <= ballRadius || ballPosition.y >= screenHeight - ballRadius) {
            ballSpeed.y *= -1;
            ballColor = (Color){ GetRandomValue(0, 255), GetRandomValue(0, 255), GetRandomValue(0, 255), 255 };
        }

        BeginDrawing();
        ClearBackground(BLACK);
        DrawCircleV(ballPosition, ballRadius, ballColor);
        DrawText("Enjoy this bouncing ball!", 10, 10, 20, RED);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
