#include <iostream>
#include <raylib.h>
#include "ball.h"
#include "paddle.h"

extern const int screen_width = 800;
extern const int screen_height = 600;

int main() {
    InitWindow(screen_width, screen_height, "Pong Game");
    SetTargetFPS(60);

    Ball ball(screen_width / 2, screen_height / 2, 3, 3, 10);
    Paddle player_1(10, screen_height / 2 - 10, 15, 85, 5);

    while (!WindowShouldClose()) {
        ball.UpdateBall();
        player_1.UpdatePaddle();

        BeginDrawing();
        ClearBackground(BEIGE);

        DrawText("Pong Game", screen_width / 2 - 55, screen_height / 2 - 15, 20, BROWN);
        ball.DrawBall();
        player_1.DrawPaddle();

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
