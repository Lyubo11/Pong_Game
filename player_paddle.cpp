#include "player_paddle.h"
#include <raylib.h>

extern const int screen_width;
extern const int screen_height;

PlayerPaddle::PlayerPaddle(double x_position, double y_position, double paddle_width, double paddle_height, int movement_speed) : Paddle() {
    setXPosition(x_position);
    setYPosition(y_position);

    setPaddleWidth(paddle_width);
    setPaddleHeight(paddle_height);

    setMovementSpeed(movement_speed);
}

void PlayerPaddle::UpdatePlayerPaddle() {
    if (IsKeyDown(KEY_W)) {
        setYPosition(getYPosition() - getMovementSpeed());
    }
    if (IsKeyDown(KEY_S)) {
        setYPosition(getYPosition() + getMovementSpeed());
    }
    LimitMovement();
}


