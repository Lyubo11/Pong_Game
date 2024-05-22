#include <iostream>
#include <raylib.h>
#include "ball.h"

extern const int screen_width = 800;
extern const int screen_height = 600;

int main() {
    InitWindow(screen_width, screen_height, "Pong Game");
    SetTargetFPS(60);

    Ball ball(screen_width / 2, screen_height / 2, 3, 3, 10);

    while (!WindowShouldClose()) {
        ball.UpdateBall();

        BeginDrawing();
        ClearBackground(BEIGE);

        DrawText("Pong Game", screen_width / 2 - 55, screen_height / 2 - 15, 20, BROWN);
        ball.DrawBall();

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
