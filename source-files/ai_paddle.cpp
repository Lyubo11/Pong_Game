#include "../header-files/ai_paddle.h"

/**
@brief Constructs an AI Paddle object with specified position, size, and speed.

This constructor initializes the AI paddle's position, size, and movement speed.
It also calls the base class Paddle's constructor to ensure proper initialization.

@param x_position The initial x-coordinate of the AI paddle.
@param y_position The initial y-coordinate of the AI paddle.
@param paddle_width The width of the AI paddle.
@param paddle_height The height of the AI paddle.
@param movement_speed The movement speed of the AI paddle.
*/
AIPaddle::AIPaddle(double x_position, double y_position, double paddle_width, double paddle_height, int movement_speed) : Paddle() {
    setXPosition(x_position);
    setYPosition(y_position);

    setPaddleWidth(paddle_width);
    setPaddleHeight(paddle_height);

    setMovementSpeed(movement_speed);
}

/**
@brief Updates the position of the AI paddle based on the ball's y-coordinate.

This function adjusts the AI paddle's y-position to track the ball's y-position.
If the ball is above the center of the paddle, the paddle moves up.
If the ball is below the center of the paddle, the paddle moves down.
The function ensures that the paddle does not move out of the screen bounds by calling LimitMovement().

@param y_position The current y-coordinate of the ball.
*/
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

