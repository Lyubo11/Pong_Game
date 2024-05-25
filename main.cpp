#include <iostream>
#include <raylib.h>
#include "ball.h"
#include "player_paddle.h"
#include "ai_paddle.h"

extern const int screen_width = 800;
extern const int screen_height = 600;

int main() {
    InitWindow(screen_width, screen_height, "Pong Game");
    SetTargetFPS(60);

    Ball ball(screen_width / 2, screen_height / 2, 3, 3, 10);
    PlayerPaddle player_paddle(10, screen_height / 2 - 10, 15, 85, 5);
    AIPaddle ai_paddle(screen_width - 25, screen_height / 2 - 50, 15, 85, 3);

    while (!WindowShouldClose()) {
        ball.UpdateBall();

        ball.DetectPaddleCollision(player_paddle);
        ball.DetectPaddleCollision(ai_paddle);

        player_paddle.UpdatePlayerPaddle();
        ai_paddle.UpdateAIPaddle(ball.getYPosition());

        BeginDrawing();
        ClearBackground(BEIGE);

        DrawText("Pong Game", screen_width / 2 - 55, screen_height / 2 - 15, 20, BROWN);
        ball.DrawBall();
        player_paddle.DrawPaddle();
        ai_paddle.DrawPaddle();

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
