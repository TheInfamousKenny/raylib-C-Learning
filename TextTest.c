#include "raylib.h"
int main(void)
{
    
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Screen test!");

    Rectangle scissorArea = { 0, 0, 200, 200 };
    bool scissorMode = true;

    SetTargetFPS(60); 
  
    while (!WindowShouldClose())   
    {
 
        if (IsKeyPressed(KEY_S)) scissorMode = !scissorMode;


        scissorArea.x = GetMouseX() - scissorArea.width/2;
        scissorArea.y = GetMouseY() - scissorArea.height/2;
 
        BeginDrawing();

            ClearBackground(BLACK);

            if (scissorMode) BeginScissorMode((int)scissorArea.x, (int)scissorArea.y, (int)scissorArea.width, (int)scissorArea.height);


            DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), BLACK);
            DrawText("Hello,", 190, 200, 20, GREEN);
            DrawText("everything is working correctly!", 190, 215, 20, GREEN);
            DrawText("Congratulations!", 190, 230, 20, GREEN);

            if (scissorMode) EndScissorMode();

            DrawRectangleLinesEx(scissorArea, 1, BLACK);
            DrawText("Press S to toggle scissor mode", 10, 10, 20, BLACK);

        EndDrawing();

    }

    CloseWindow();

    return 0;
}
