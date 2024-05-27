#include "player_paddle.h"
#include <raylib.h>

extern const int screen_width;
extern const int screen_height;

PlayerPaddle::PlayerPaddle(double x_position, double y_position, double paddle_width, double paddle_height, int movement_speed, int up_key, int down_key) : Paddle() {
    setXPosition(x_position);
    setYPosition(y_position);

    setPaddleWidth(paddle_width);
    setPaddleHeight(paddle_height);

    setMovementSpeed(movement_speed);

    setUpKey(up_key);
    setDownKey(down_key);
}

void PlayerPaddle::UpdatePlayerPaddle() {
    if (IsKeyDown(up_key)) {
        setYPosition(getYPosition() - getMovementSpeed());
    }
    if (IsKeyDown(down_key)) {
        setYPosition(getYPosition() + getMovementSpeed());
    }
    LimitMovement();
}

int PlayerPaddle::getUpKey() const {
    return up_key;
}

void PlayerPaddle::setUpKey(int new_up_key) {
    up_key = new_up_key;
}

int PlayerPaddle::getDownKey() const {
    return down_key;
}

void PlayerPaddle::setDownKey(int new_down_key) {
    down_key = new_down_key;
}


