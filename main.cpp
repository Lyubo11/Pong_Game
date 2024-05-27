#include <iostream>
#include <raylib.h>
#include <cstdlib>
#include "ball.h"
#include "player_paddle.h"
#include "ai_paddle.h"


extern const int screen_width = 800;
extern const int screen_height = 600;

/*extern const int y_spawn_range = rand() % 41 + (-20);
extern const int x_spawn_range = rand() % 41 + (-20);*/
extern const int y_spawn_range = 20;
extern const int x_spawn_range = 20;

extern const int init_ball_x_speed = rand() % 3 + 1;
extern const int init_ball_y_speed = rand() % 3 + 1;

const int winning_score = 10;

int left_player_score = 0;
int right_player_score = 0;

bool game_mode = false;
// bool selected_button = false;

int main() {
    InitWindow(screen_width, screen_height, "Pong Game");
    SetTargetFPS(60);

    /* Ball ball(screen_width / 2 + x_spawn_range, screen_height / 2 + y_spawn_range, init_ball_x_speed, init_ball_y_speed, 10); */
    Ball ball(rand() % (screen_width / 2 + x_spawn_range) + (screen_width / 2 - x_spawn_range), rand() % (screen_height / 2 + y_spawn_range) + (screen_height / 2 - y_spawn_range), init_ball_x_speed, init_ball_y_speed, 10);


    PlayerPaddle player_paddle(10, screen_height / 2 - 10, 15, 85, 5, KEY_W, KEY_S);
    PlayerPaddle player_paddle1(screen_width - 25, screen_height / 2 - 50, 15, 85, 5, KEY_UP, KEY_DOWN);
    //AIPaddle ai_paddle(screen_width - 25, screen_height / 2 - 50, 15, 85, 5);

    bool game_over = false;
    const char* winner_text = "";

    while (!WindowShouldClose()) {
        if (!game_over)
        ball.UpdateBall();

        ball.DetectPaddleCollision(player_paddle);
        ball.DetectPaddleCollision(player_paddle1);
        //ball.DetectPaddleCollision(ai_paddle);

        player_paddle.UpdatePlayerPaddle();
        player_paddle1.UpdatePlayerPaddle();
        //ai_paddle.UpdateAIPaddle(ball.getYPosition());

        if (ball.getXPosition() + ball.getRadius() >= screen_width) {
            ++left_player_score;
            ball.ResetBall();
        }

        if (ball.getXPosition() - ball.getRadius() <= 0) {
            ++right_player_score;
            ball.ResetBall();
        }

        if (left_player_score >= winning_score) {
            game_over = true;
            winner_text = "Player Wins!";
        }
        if (right_player_score >= winning_score) {
            game_over = true;
            winner_text = "AI Wins!";
        }

        BeginDrawing();
        ClearBackground(BEIGE);

        DrawText("Pong Game", screen_width / 2 - 55, screen_height / 2 - 15, 20, BROWN);
        ball.DrawBall();
        player_paddle.DrawPaddle();
        player_paddle1.DrawPaddle();
        // ai_paddle.DrawPaddle();

        DrawText(TextFormat("%i", left_player_score), screen_width / 4, 20, 36, DARKBROWN);
        DrawText(TextFormat("%i", right_player_score), 3 * screen_width / 4, 20, 36, DARKBROWN);

        if (game_over) {
            DrawText(winner_text, screen_width / 2 - MeasureText(winner_text, 60) / 2, 80, 60, DARKBROWN);
            DrawText("Press [ENTER] to Restart", screen_width / 2 - MeasureText("Press [ENTER] to Restart", 20) / 2, screen_height / 2 + 150, 20, DARKBROWN);
            if (IsKeyPressed(KEY_ENTER)) {
                left_player_score = 0;
                right_player_score = 0;
                ball.ResetBall();
                game_over = false;
            }
        }

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
