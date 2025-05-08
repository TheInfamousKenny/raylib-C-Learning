#include "raylib.h"
#include <stdlib.h>

#define MAX_PARTICLES 40000

typedef struct {
    Vector2 position;
    Vector2 velocity;
    Color color;
    float lifetime;
    bool active;
} Particle;

int main() {
    const int screenWidth = 1910;
    const int screenHeight = 1070;
    InitWindow(screenWidth, screenHeight, "Particle Fountain!");

    Particle particles[MAX_PARTICLES] = { 0 };
    
    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        // Update particles
        for (int i = 0; i < MAX_PARTICLES; i++) {
            if (particles[i].active) {
                particles[i].position.x += particles[i].velocity.x;
                particles[i].position.y += particles[i].velocity.y;
                particles[i].velocity.y += 0.01f; // Simulate gravity
                particles[i].lifetime -= 0.002f;

                if (particles[i].lifetime <= 0) particles[i].active = false;
            }
        }

        // Create new particles
        for (int i = 0; i < MAX_PARTICLES; i++) {
            if (!particles[i].active) {
                particles[i] = (Particle){
                    .position = { screenWidth / 2, screenHeight - 30 },
                    .velocity = { GetRandomValue(-3, 3), GetRandomValue(-8, -5) },
                    .color = (Color){ GetRandomValue(100, 255), GetRandomValue(100, 255), GetRandomValue(100, 255), 255 },
                    .lifetime = 1.0f,
                    .active = true
                };
                break;
            }
        }

        // Draw everything
        BeginDrawing();
        ClearBackground(BLACK);

        for (int i = 0; i < MAX_PARTICLES; i++) {
            if (particles[i].active) {
                DrawCircleV(particles[i].position, 5, Fade(particles[i].color, particles[i].lifetime));
            }
        }

        DrawText("You found the secret text!", 10, 10, 20, BLACK);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
