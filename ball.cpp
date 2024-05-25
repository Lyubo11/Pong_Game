#include "ball.h"
#include <raylib.h>

extern const int screen_width;
extern const int screen_height;

Ball::Ball(int x_position, int y_position, int x_pace, int y_pace, int radius) {
    setXPosition(x_position);
    setYPosition(y_position);

    setXPace(x_pace);
    setYPace(y_pace);

    setRadius(radius);
}

void Ball::DrawBall() const {
    DrawCircle(getXPosition(), getYPosition(), (float)getRadius(), BROWN);
}

void Ball::UpdateBall() {
    setXPosition(getXPosition() + getXPace());
    setYPosition(getYPosition() + getYPace());

    if ((getYPosition() + getRadius() >= screen_height) || (getYPosition() - getRadius() <= 0)){
        setYPace(getYPace() * -1);
    }
}

void Ball::ResetBall() {
    setXPosition(screen_width / 2);
    setYPosition(screen_height / 2);
}

void Ball::DetectPaddleCollision(Paddle &paddle) {
    if (CheckCollisionCircleRec({(float)getXPosition(), (float)getYPosition()}, (float)getRadius(), {(float)paddle.getXPosition(), (float)paddle.getYPosition(), (float)paddle.getPaddleWidth(), (float)paddle.getPaddleHeight()})) {
        setXPace(getXPace() * -1);
    }
}


int Ball::getXPosition() const {
    return x_position;
}

int Ball::getYPosition() const {
    return y_position;
}

int Ball::getXPace() const {
    return x_pace;
}

int Ball::getYPace() const {
    return y_pace;
}

int Ball::getRadius() const {
    return radius;
}


void Ball::setXPosition(int new_x_position) {
    x_position = new_x_position;
}

void Ball::setYPosition(int new_y_position) {
    y_position = new_y_position;
}

void Ball::setXPace(int new_x_pace) {
    x_pace = new_x_pace;
}

void Ball::setYPace(int new_y_pace) {
    y_pace = new_y_pace;
}

void Ball::setRadius(int new_radius) {
    Ball::radius = new_radius;
}

