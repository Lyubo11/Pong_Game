#include "paddle.h"
#include <raylib.h>

extern const int screen_width;
extern const int screen_height;

Paddle::Paddle(double x_position, double y_position, double paddle_width, double paddle_height, int movement_speed) {
    setXPosition(x_position);
    setYPosition(y_position);

    setPaddleWidth(paddle_width);
    setPaddleHeight(paddle_height);

    setMovementSpeed(movement_speed);
}

void Paddle::DrawPaddle() {
    DrawRectangleRec({static_cast<float>(getXPosition()), static_cast<float>(getYPosition()),
                      static_cast<float>(getPaddleWidth()), static_cast<float>(getPaddleHeight())}, DARKBROWN);
}

void Paddle::UpdatePaddle() {
    if (IsKeyDown(KEY_W)) {
        setYPosition(getYPosition() - getMovementSpeed());
    }
    if (IsKeyDown(KEY_S)) {
        setYPosition(getYPosition() + getMovementSpeed());
    }
    LimitMovement();
}

void Paddle::LimitMovement() {
    if (getYPosition() <= 0) {
        setYPosition(0);
    }
    if (getYPosition() + getPaddleHeight() >= screen_height) {
        setYPosition(screen_height - getPaddleHeight());
    }
}


double Paddle::getXPosition() const {
    return x_position;
}

double Paddle::getYPosition() const {
    return y_position;
}

double Paddle::getPaddleWidth() const {
    return paddle_width;
}

double Paddle::getPaddleHeight() const {
    return paddle_height;
}

int Paddle::getMovementSpeed() const {
    return movement_speed;
}


void Paddle::setXPosition(double new_x_position) {
    x_position = new_x_position;
}

void Paddle::setYPosition(double new_y_position) {
    y_position = new_y_position;
}

void Paddle::setPaddleWidth(double new_paddle_width) {
    paddle_width = new_paddle_width;
}

void Paddle::setPaddleHeight(double new_paddle_height) {
    paddle_height = new_paddle_height;
}

void Paddle::setMovementSpeed(int new_movement_speed) {
    movement_speed = new_movement_speed;
}

