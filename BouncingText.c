#include "raylib.h"

int main() {
    const int screenWidth = 800;
    const int screenHeight = 600;
    
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(screenWidth, screenHeight, "Bouncing Text");

    const char *message = "DVD";
    int x = screenWidth / 2;
    int y = screenHeight / 2;
    int speedX = 4;
    int speedY = 4;
    int fontSize = 20;
    Color textColor = DARKBLUE;

    SetTargetFPS(60);
    
    while (!WindowShouldClose()) {
        int currentWidth = GetScreenWidth();
        int currentHeight = GetScreenHeight();

        x += speedX;
        y += speedY;

        if (x + MeasureText(message, fontSize) >= currentWidth || x <= 0) {
            speedX *= -1;
            textColor = (Color){ GetRandomValue(50, 255), GetRandomValue(50, 255), GetRandomValue(50, 255), 255 };
        }
        if (y + fontSize >= currentHeight || y <= 0) {
            speedY *= -1;
            textColor = (Color){ GetRandomValue(50, 255), GetRandomValue(50, 255), GetRandomValue(50, 255), 255 };
        }

        if (IsKeyDown(KEY_UP)) fontSize += 1;
        if (IsKeyDown(KEY_DOWN) && fontSize > 10) fontSize -= 1;

        BeginDrawing();
        ClearBackground(BLACK);
        DrawText(message, x, y, fontSize, textColor);
        EndDrawing();
    }

    CloseWindow();
    
    return 0;
}
