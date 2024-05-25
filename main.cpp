#include <iostream>
#include <raylib.h>
#include <cstdlib>
#include "ball.h"
#include "player_paddle.h"
#include "ai_paddle.h"


extern const int screen_width = 800;
extern const int screen_height = 600;

extern const int y_spawn_range = 20;
extern const int x_spawn_range = 20;

extern const int init_ball_x_speed = rand() % 3 + 1;
extern const int init_ball_y_speed = rand() % 3 + 1;

int player_score = 0;
int ai_score = 0;

int main() {
    InitWindow(screen_width, screen_height, "Pong Game");
    SetTargetFPS(60);

    Ball ball(rand() % (screen_width / 2 + x_spawn_range) + (screen_width / 2 - x_spawn_range), rand() % (screen_height / 2 + y_spawn_range) + (screen_height / 2 - y_spawn_range), init_ball_x_speed, init_ball_y_speed, 10);
    PlayerPaddle player_paddle(10, screen_height / 2 - 10, 15, 85, 5);
    AIPaddle ai_paddle(screen_width - 25, screen_height / 2 - 50, 15, 85, 3);

    while (!WindowShouldClose()) {
        ball.UpdateBall();

        ball.DetectPaddleCollision(player_paddle);
        ball.DetectPaddleCollision(ai_paddle);

        player_paddle.UpdatePlayerPaddle();
        ai_paddle.UpdateAIPaddle(ball.getYPosition());

        if (ball.getXPosition() + ball.getRadius() >= screen_width) {
            ++player_score;
            ball.ResetBall();
        }

        if (ball.getXPosition() - ball.getRadius() <= 0) {
            ++ai_score;
            ball.ResetBall();
        }

        BeginDrawing();
        ClearBackground(BEIGE);

        DrawText("Pong Game", screen_width / 2 - 55, screen_height / 2 - 15, 20, BROWN);
        ball.DrawBall();
        player_paddle.DrawPaddle();
        ai_paddle.DrawPaddle();

        DrawText(TextFormat("%i", player_score), screen_width / 4, 20, 36, DARKBROWN);
        DrawText(TextFormat("%i", ai_score), 3 * screen_width / 4, 20, 36, DARKBROWN);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
