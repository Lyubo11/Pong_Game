#include "../header-files/ai_paddle.h"

// Constructor for the AI Paddle, initializes the AI paddle with the specified position, size and speed
AIPaddle::AIPaddle(double x_position, double y_position, double paddle_width, double paddle_height, int movement_speed) : Paddle() {
    setXPosition(x_position);
    setYPosition(y_position);

    setPaddleWidth(paddle_width);
    setPaddleHeight(paddle_height);

    setMovementSpeed(movement_speed);
}

// Function to update the position of the AI paddle based on the ball's position
void AIPaddle::UpdateAIPaddle(double y_position) {
    // If the ball is above the center of the paddle, move the paddle up
    if (getYPosition() + getPaddleHeight() / 2 > y_position) {
        setYPosition(getYPosition() - getMovementSpeed());
    }

    // If the ball is below the center of the paddle, move the paddle down
    if (getYPosition() + getPaddleHeight() / 2 < y_position) {
        setYPosition(getYPosition() + getMovementSpeed());
    }

    // Ensure that the paddle stays within the screen bounds
    LimitMovement();
}

