#include "ai_paddle.h"

AIPaddle::AIPaddle(double x_position, double y_position, double paddle_width, double paddle_height, int movement_speed)
        : x_position(getXPosition()), y_position(getYPosition()), paddle_width(getPaddleWidth()),
          paddle_height(getPaddleHeight()), movement_speed(getMovementSpeed()) {}

void AIPaddle::UpdateAIPaddle(double y_position) {
    if (getYPosition() + getPaddleHeight() / 2 > y_position) {
        setYPosition(getYPosition() - getMovementSpeed());
    }
    if (getYPosition() + getPaddleHeight() / 2 < y_position) {
        setYPosition(getYPosition() + getMovementSpeed());
    }
    LimitMovement();
}

