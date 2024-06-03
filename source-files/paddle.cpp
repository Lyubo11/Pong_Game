#include "../header-files/paddle.h"
#include "raylib.h"

/**
Extern constant variable for screen dimensions (screen width)
~~~.cpp
extern const int screen_width;
~~~
*/
extern const int screen_width;

/**
Extern constant variable for screen dimensions (screen height)
~~~.cpp
extern const int screen_height;
~~~
*/
extern const int screen_height;


/**
@brief Draws the paddle on the screen.

This function draws a rectangle representing the paddle on the screen using its current position, width, and height.
The paddle is drawn in dark brown color.
*/
void Paddle::DrawPaddle() const {
    // Draw a rectangle representing the paddle
    DrawRectangleRec({static_cast<float>(getXPosition()), static_cast<float>(getYPosition()),
                      static_cast<float>(getPaddleWidth()), static_cast<float>(getPaddleHeight())}, DARKBROWN);
}

/**
@brief Limits the movement of the paddle to stay within the screen bounds.

This function ensures that the paddle does not move beyond the top or bottom edges of the screen.
*/
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

/**
@brief Getter function for the X position of the paddle.
~~~.cpp
double Paddle::getXPosition() const {
    return x_position;
}
~~~
@return The current X position of the paddle.
*/
double Paddle::getXPosition() const {
    return x_position;
}

/**
@brief Getter function for the Y position of the paddle.
~~~.cpp
double Paddle::getYPosition() const {
    return y_position;
}
~~~
@return The current Y position of the paddle.
*/
double Paddle::getYPosition() const {
    return y_position;
}

/**
@brief Getter function for the width of the paddle.
~~~.cpp
double Paddle::getPaddleWidth() const {
    return paddle_width;
}
~~~
@return The current width of the paddle.
*/
double Paddle::getPaddleWidth() const {
    return paddle_width;
}

/**
@brief Getter function for the height of the paddle.
~~~.cpp
double Paddle::getPaddleHeight() const {
    return paddle_height;
}
~~~
@return The current height of the paddle.
*/
double Paddle::getPaddleHeight() const {
    return paddle_height;
}

/**
@brief Getter function for the movement speed of the paddle.
~~~.cpp
int Paddle::getMovementSpeed() const {
    return movement_speed;
}
~~~
@return The current movement speed of the paddle.
*/
int Paddle::getMovementSpeed() const {
    return movement_speed;
}


/**
@brief Setter function for the X position of the paddle.
~~~.cpp
void Paddle::setXPosition(double new_x_position) {
    x_position = new_x_position;
}
~~~
@param new_x_position The new X position of the paddle.
*/
void Paddle::setXPosition(double new_x_position) {
    x_position = new_x_position;
}

/**
@brief Setter function for the Y position of the paddle.
~~~.cpp
void Paddle::setYPosition(double new_y_position) {
    y_position = new_y_position;
}
~~~
@param new_y_position The new Y position of the paddle.
*/
void Paddle::setYPosition(double new_y_position) {
    y_position = new_y_position;
}

/**
@brief Setter function for the width of the paddle.
~~~.cpp
void Paddle::setPaddleWidth(double new_paddle_width) {
    paddle_width = new_paddle_width;
}
~~~
@param new_paddle_width The new width of the paddle.
*/
void Paddle::setPaddleWidth(double new_paddle_width) {
    paddle_width = new_paddle_width;
}

/**
@brief Setter function for the height of the paddle.
~~~.cpp
void Paddle::setPaddleHeight(double new_paddle_height) {
    paddle_height = new_paddle_height;
}
~~~
@param new_paddle_height The new height of the paddle.
*/
void Paddle::setPaddleHeight(double new_paddle_height) {
    paddle_height = new_paddle_height;
}

/**
@brief Setter function for the movement speed of the paddle.
~~~.cpp
void Paddle::setMovementSpeed(int new_movement_speed) {
    movement_speed = new_movement_speed;
}
~~~
@param new_movement_speed The new movement speed of the paddle.
*/
void Paddle::setMovementSpeed(int new_movement_speed) {
    movement_speed = new_movement_speed;
}
