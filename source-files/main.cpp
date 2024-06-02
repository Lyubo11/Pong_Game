#include "raylib.h"
#include <cstdlib>
#include "../header-files/ball.h"
#include "../header-files/player_paddle.h"
#include "../header-files/ai_paddle.h"

/**
Extern constant variable for screen dimensions (screen width)
~~~.cpp
extern const int screen_width = 800;
~~~
*/
// Constants for screen dimensions
extern const int screen_width = 800;
extern const int screen_height = 600;

// Constants for ball spawn range
extern const int x_spawn_range = 20;
extern const int y_spawn_range = 20;

// Initial speed for the ball
extern const int init_ball_x_speed = rand() % 3 + 1;
extern const int init_ball_y_speed = rand() % 3 + 1;

// Winning score constant
const int winning_score = 10;

// Player scores
int left_player_score = 0;
int right_player_score = 0;

// Game mode indicators
bool game_mode = false;         // false for PVP, true for Player vs AI
bool mode_selected = false;     // Check if the game mode is selected


// Function to draw a button with text
void DrawButton(const char* text, Rectangle rec, Color color) {
    DrawRectangleRec(rec, color);
    DrawText(text, rec.x + rec.width / 2 - MeasureText(text, 20) / 2, rec.y + rec.height / 2 - 10, 20, WHITE);
}

// Function to check if a button is pressed
bool IsButtonPressed(Rectangle rec) {
    return (CheckCollisionPointRec(GetMousePosition(), rec) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT));
}


int main() {
    // Initializing the window
    InitWindow(screen_width, screen_height, "Pong Game");
    SetTargetFPS(60);

    // Initialize ball object
    Ball ball(rand() % (screen_width / 2 + x_spawn_range) + (screen_width / 2 - x_spawn_range), rand() % (screen_height / 2 + y_spawn_range) + (screen_height / 2 - y_spawn_range), init_ball_x_speed, init_ball_y_speed, 10);

    // Initialize player and AI paddle objects
    PlayerPaddle left_player_paddle(10, screen_height / 2 - 10, 15, 85, 5, KEY_W, KEY_S);
    PlayerPaddle right_player_paddle(screen_width - 25, screen_height / 2 - 50, 15, 85, 5, KEY_UP, KEY_DOWN);
    AIPaddle ai_paddle(screen_width - 25, screen_height / 2 - 50, 15, 85, 5);

    // Game mode indicator and winner text
    bool game_over = false;
    const char* winner_text = "";

    // Define buttons for game mode selection
    Rectangle pvp_button = {screen_width / 2 - 100, screen_height / 2 - 60, 200, 50 };
    Rectangle pvai_button = {screen_width / 2 - 100, screen_height / 2 + 10, 200, 50 };

    // Main game loop
    while (!WindowShouldClose()) {
        if (!mode_selected) {
            // Game mode selection screen
            BeginDrawing();
            ClearBackground(BEIGE);

            DrawText("Select Game Mode", screen_width / 2 - MeasureText("Select Game Mode", 40) / 2, screen_height / 4, 40, BROWN);

            DrawButton("Player vs Player", pvp_button, DARKBROWN);
            DrawButton("Player vs AI", pvai_button, DARKBROWN);

            // Check if buttons are pressed
            if (IsButtonPressed(pvp_button)) {
                mode_selected = true;
                game_mode = false;
            }
            if (IsButtonPressed(pvai_button)) {
                mode_selected = true;
                game_mode = true;
            }

            EndDrawing();
        } else {
            // If the game is not over, update the ball's position
            if (!game_over) {
                ball.UpdateBall();
            }

            // Check for collisions between the ball and the left paddle
            ball.DetectPaddleCollision(left_player_paddle);

            // Check for collisions between the ball and the right paddle, depending on the game mode
            if (game_mode) {
                ball.DetectPaddleCollision(ai_paddle);
            } else {
                ball.DetectPaddleCollision(right_player_paddle);
            }

            // Update the left player paddle's position based on user input
            left_player_paddle.UpdatePlayerPaddle();

            // Depending on the game mode, update the position of the right paddle
            if (game_mode) {
                ai_paddle.UpdateAIPaddle(ball.getYPosition());
            } else {
                right_player_paddle.UpdatePlayerPaddle();
            }

            // Check if the ball has passed the right edge of the screen => left player scores
            if (ball.getXPosition() + ball.getRadius() >= screen_width) {
                ++left_player_score;
                ball.ResetBall();
            }

            // Check if the ball has passed the left edge of the screen => right player scores
            if (ball.getXPosition() - ball.getRadius() <= 0) {
                ++right_player_score;
                ball.ResetBall();
            }

            // Check if the left player has reached the winning score
            if (left_player_score >= winning_score) {
                game_over = true;
                winner_text = "Left Player Wins!";
            }

            // Check if the right player or the AI, depending on the mode, has reached the winning score
            if (right_player_score >= winning_score) {
                game_over = true;
                if (game_mode) {
                    winner_text = "AI Wins!";
                } else {
                    winner_text = "Right Player Wins!";
                }

            }

            // Begin drawing the frame
            BeginDrawing();
            ClearBackground(BEIGE);     // Clear the screen with a beige background

            // Draw the game title
            DrawText("Pong Game", screen_width / 2 - 55, screen_height / 2 - 15, 20, BROWN);

            // Draw the ball and the paddles
            ball.DrawBall();
            left_player_paddle.DrawPaddle();
            if (game_mode) {
                ai_paddle.DrawPaddle();
            } else {
                right_player_paddle.DrawPaddle();
            }

            // Draw the scores
            DrawText(TextFormat("%i", left_player_score), screen_width / 4, 20, 36, DARKBROWN);
            DrawText(TextFormat("%i", right_player_score), 3 * screen_width / 4, 20, 36, DARKBROWN);

            // If the game is over, display the winner and restart instructions
            if (game_over) {
                DrawText(winner_text, screen_width / 2 - MeasureText(winner_text, 60) / 2, 80, 60, DARKBROWN);
                DrawText("Press [ENTER] to Restart", screen_width / 2 - MeasureText("Press [ENTER] to Restart", 20) / 2, screen_height / 2 + 150, 20, DARKBROWN);

                // Reset the game if the enter key is pressed
                if (IsKeyPressed(KEY_ENTER)) {
                    left_player_score = 0;
                    right_player_score = 0;
                    ball.ResetBall();
                    game_over = false;
                }
            }
            // End drawing the frame
            EndDrawing();
        }
    }

    // Close window and clean up
    CloseWindow();
    return 0;
}
