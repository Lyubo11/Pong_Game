#include "../header-files/ball.h"
#include "raylib.h"
#include <cstdlib>

// Extern constants for screen dimensions
extern const int screen_width;
extern const int screen_height;

// Extern constants for ball spawn range
extern const int x_spawn_range;
extern const int y_spawn_range;

// Extern constants for ball speed
extern const int init_ball_x_speed;
extern const int init_ball_y_speed;

// Constructor for Ball class, initializes the ball with specified position, pace and radius
Ball::Ball(int x_position, int y_position, int x_pace, int y_pace, int radius) {
    setXPosition(x_position);
    setYPosition(y_position);

    setXPace(x_pace);
    setYPace(y_pace);

    setRadius(radius);
}

// Draw the ball on the screen
void Ball::DrawBall() const {
    DrawCircle(getXPosition(), getYPosition(), (float)getRadius(), BROWN);
}

// Update the ball's position based on its pace
void Ball::UpdateBall() {
    setXPosition(getXPosition() + getXPace());
    setYPosition(getYPosition() + getYPace());

    // Check if the ball hits the top or bottom of the screen, and reverse its vertical direction if so
    if ((getYPosition() + getRadius() >= screen_height) || (getYPosition() - getRadius() <= 0)){
        setYPace(getYPace() * -1);
    }
}

// Reset the ball's position and pace to the initial values
void Ball::ResetBall() {
    /*setXPosition(screen_width / 2 + x_spawn_range);
    setYPosition(screen_height / 2 + y_spawn_range);*/
    setXPosition(rand() % (screen_width / 2 + x_spawn_range) + (screen_width / 2 - x_spawn_range));
    setYPosition(rand() % (screen_height / 2 + y_spawn_range) + (screen_height / 2 - y_spawn_range));

    setXPace(init_ball_x_speed);
    setYPace(init_ball_y_speed);
}

// Detect collision between the ball and a paddle
void Ball::DetectPaddleCollision(Paddle &paddle) {
    // Check if the ball collides with the paddle's rectangle
    if (CheckCollisionCircleRec({(float)getXPosition(), (float)getYPosition()}, (float)getRadius(), {(float)paddle.getXPosition(), (float)paddle.getYPosition(), (float)paddle.getPaddleWidth(), (float)paddle.getPaddleHeight()})) {
        setXPace(getXPace() * -1);      // Reverse the ball's horizontal direction

        // Adjust the ball's pace based on its direction after collision
        if (getXPace() < 0) {
            setXPace(getXPace() - 1);
        }
        else {
            setXPace(getXPace() + 1);
        }
        if (getYPace() < 0) {
            setYPace(getYPace() - 1);
        }
        else {
            setYPace(getYPace() + 1);
        }
    }
}


// Getter function for the X position of the ball
int Ball::getXPosition() const {
    return x_position;
}

// Getter function for the Y position of the ball
int Ball::getYPosition() const {
    return y_position;
}

// Getter function for the X pace of the ball
int Ball::getXPace() const {
    return x_pace;
}

// Getter function for the Y pace (vertical velocity) of the ball
int Ball::getYPace() const {
    return y_pace;
}

// Getter function for the radius of the ball
int Ball::getRadius() const {
    return radius;
}


// Setter function for the X position of the ball
void Ball::setXPosition(int new_x_position) {
    x_position = new_x_position;
}

// Setter function for the Y position of the ball
void Ball::setYPosition(int new_y_position) {
    y_position = new_y_position;
}

// Setter function for the X pace of the ball
void Ball::setXPace(int new_x_pace) {
    x_pace = new_x_pace;
}

// Setter function for the Y pace of the ball
void Ball::setYPace(int new_y_pace) {
    y_pace = new_y_pace;
}

// Setter function for the radius of the ball
void Ball::setRadius(int new_radius) {
    radius = new_radius;
}

