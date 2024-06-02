#include "../header-files/paddle.h"
#include "raylib.h"

// External variables for screen dimensions
extern const int screen_width;
extern const int screen_height;

// Draw the paddle on the screen
void Paddle::DrawPaddle() const {
    // Draw a rectangle representing the paddle
    DrawRectangleRec({static_cast<float>(getXPosition()), static_cast<float>(getYPosition()),
                      static_cast<float>(getPaddleWidth()), static_cast<float>(getPaddleHeight())}, DARKBROWN);
}

// Limit the movement of the paddle to stay within the screen bounds
void Paddle::LimitMovement() {
    // If the top of the paddle is above the screen boundary, set it to 0
    if (getYPosition() <= 0) {
        setYPosition(0);
    }

    // If the bottom of the paddle is below the screen boundary, set it to the maximum allowable position
    if (getYPosition() + getPaddleHeight() >= screen_height) {
        setYPosition(screen_height - getPaddleHeight());
    }
}

// Getter function for the X position of the paddle
double Paddle::getXPosition() const {
    return x_position;
}

// Getter function for the Y position of the paddle
double Paddle::getYPosition() const {
    return y_position;
}

// Getter function for the width of the paddle
double Paddle::getPaddleWidth() const {
    return paddle_width;
}

// Getter function for the height of the paddle
double Paddle::getPaddleHeight() const {
    return paddle_height;
}

// Getter function for the movement speed of the paddle
int Paddle::getMovementSpeed() const {
    return movement_speed;
}


// Setter function for the X position of the paddle
void Paddle::setXPosition(double new_x_position) {
    x_position = new_x_position;
}

// Setter function for the Y position of the paddle
void Paddle::setYPosition(double new_y_position) {
    y_position = new_y_position;
}

// Setter function for the width of the paddle
void Paddle::setPaddleWidth(double new_paddle_width) {
    paddle_width = new_paddle_width;
}

// Setter function for the height of the paddle
void Paddle::setPaddleHeight(double new_paddle_height) {
    paddle_height = new_paddle_height;
}

// Setter function for the movement speed of the paddle
void Paddle::setMovementSpeed(int new_movement_speed) {
    movement_speed = new_movement_speed;
}
