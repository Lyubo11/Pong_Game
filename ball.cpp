#include "ball.h"
#include <raylib.h>

extern const int screen_width;
extern const int screen_height;

Ball::Ball(double x_position, double y_position, int x_pace, int y_pace, int radius) {
    this->x_position = x_position;
    this->y_position = y_position;

    this->x_pace = x_pace;
    this->y_pace = y_pace;

    this->radius = radius;
}

void Ball::DrawBall() {
    DrawCircle(x_position, y_position, radius, BROWN);
}

void Ball::UpdateBall() {
    x_position += x_pace;
    y_position += y_pace;

    if ((y_position + radius >= screen_height) || (y_position - radius <= 0)){
        y_pace *= -1;
    }
}

void Ball::ResetBall() {
    x_position = screen_width / 2;
    y_position = screen_height / 2;
}

double Ball::getYPosition() const {
    return y_position;
}

void Ball::setYPosition(double new_y_position) {
    y_position = new_y_position;
}

