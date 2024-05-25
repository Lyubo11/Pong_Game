#include "ai_paddle.h"

AIPaddle::AIPaddle(double x_position, double y_position, double paddle_width, double paddle_height, int movement_speed) : Paddle() {
    setXPosition(x_position);
    setYPosition(y_position);

    setPaddleWidth(paddle_width);
    setPaddleHeight(paddle_height);

    setMovementSpeed(movement_speed);
}

void AIPaddle::UpdateAIPaddle(double y_position) {
    if (getYPosition() + getPaddleHeight() / 2 > y_position) {
        setYPosition(getYPosition() - getMovementSpeed());
    }
    if (getYPosition() + getPaddleHeight() / 2 < y_position) {
        setYPosition(getYPosition() + getMovementSpeed());
    }
    LimitMovement();
}

