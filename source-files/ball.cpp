#include "../header-files/ball.h"
#include "raylib.h"
#include <cstdlib>

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
Extern constant variable for ball spawn range (x)
~~~.cpp
extern const int x_spawn_range;
~~~
*/
extern const int x_spawn_range;

/**
Extern constant variable for ball spawn range (y)
~~~.cpp
extern const int y_spawn_range;
~~~
*/
extern const int y_spawn_range;

/**
Extern constant variable for initial speed for the ball (x speed)
~~~.cpp
extern const int init_ball_x_speed;
~~~
*/
extern const int init_ball_x_speed;

/**
Extern constant variable for initial speed for the ball (y speed)
~~~.cpp
extern const int init_ball_y_speed;
~~~
*/
extern const int init_ball_y_speed;

/**
@brief Constructs an Ball object with specified position, size, and speed.

This constructor initializes the Ball's position, velocity, and radius.

@param x_position Initial x position of the ball.
@param y_position Initial y position of the ball.
@param x_pace Initial x pace (horizontal velocity) of the ball.
@param y_pace Initial y pace (vertical velocity) of the ball.
@param radius Radius of the ball.
*/
Ball::Ball(int x_position, int y_position, int x_pace, int y_pace, int radius) {
    setXPosition(x_position);
    setYPosition(y_position);

    setXPace(x_pace);
    setYPace(y_pace);

    setRadius(radius);
}

/**
@brief Draws the ball on the screen.

This function renders the ball as a circle on the screen using its current position and radius.
The ball is drawn in brown color.
*/
void Ball::DrawBall() const {
    DrawCircle(getXPosition(), getYPosition(), (float) getRadius(), BROWN);
}

/**
@brief Updates the ball's position based on its current pace.

This function updates the position of the ball by adding its pace values to its current position.
It also checks for collisions with the top and bottom edges of the screen. If the ball collides
with either edge, its vertical pace is reversed to simulate a bounce.
*/
void Ball::UpdateBall() {
    setXPosition(getXPosition() + getXPace());
    setYPosition(getYPosition() + getYPace());

    // Check if the ball hits the top or bottom of the screen, and reverse its vertical direction if so
    if ((getYPosition() + getRadius() >= screen_height) || (getYPosition() - getRadius() <= 0)) {
        setYPace(getYPace() * -1);
    }
}


/**
@brief Resets the ball's position and pace to the initial values.

This function resets the ball to a random position near the center of the screen within the specified
spawn range. It also resets the ball's pace to the initial random values defined at the start of the game.
*/
void Ball::ResetBall() {
    /*setXPosition(screen_width / 2 + x_spawn_range);
    setYPosition(screen_height / 2 + y_spawn_range);*/
    setXPosition(rand() % (screen_width / 2 + x_spawn_range) + (screen_width / 2 - x_spawn_range));
    setYPosition(rand() % (screen_height / 2 + y_spawn_range) + (screen_height / 2 - y_spawn_range));

    setXPace(init_ball_x_speed);
    setYPace(init_ball_y_speed);
}

/**
@brief Detects collision between the ball and a paddle.

@param paddle The paddle to check collision against.

This function checks if the ball has collided with the specified paddle. If a collision is detected,
the ball's horizontal direction is reversed, and its pace is increased. The pace is increased
gradually to make the game progressively harder as it continues.
*/
void Ball::DetectPaddleCollision(Paddle &paddle) {
    // Check if the ball collides with the paddle's rectangle
    if (CheckCollisionCircleRec({(float) getXPosition(), (float) getYPosition()}, (float) getRadius(),
                                {(float) paddle.getXPosition(), (float) paddle.getYPosition(),
                                 (float) paddle.getPaddleWidth(), (float) paddle.getPaddleHeight()})) {
        setXPace(getXPace() * -1);      // Reverse the ball's horizontal direction

        // Adjust the ball's pace based on its direction after collision
        if (getXPace() < 0) {
            setXPace(getXPace() - 1);
        } else {
            setXPace(getXPace() + 1);
        }
        if (getYPace() < 0) {
            setYPace(getYPace() - 1);
        } else {
            setYPace(getYPace() + 1);
        }
    }
}


/**
@breif Getter function for the X position of the ball.
~~~.cpp
int Ball::getXPosition() const {
    return x_position;
}
~~~
@return The X position of the ball.
*/
int Ball::getXPosition() const {
    return x_position;
}

/**
@breif Getter function for the Y position of the ball.
~~~.cpp
int Ball::getYPosition() const {
    return y_position;
}
~~~
@return The Y position of the ball.
*/
int Ball::getYPosition() const {
    return y_position;
}

/**
@breif Getter function for the X pace of the ball.
~~~.cpp
int Ball::getXPace() const {
    return x_pace;
}
~~~
@return The X pace of the ball.
*/
int Ball::getXPace() const {
    return x_pace;
}

/**
@breif Getter function for the Y pace (vertical velocity) of the ball
~~~.cpp
int Ball::getYPace() const {
    return y_pace;
}
~~~
@return The Y pace of the ball.
*/
int Ball::getYPace() const {
    return y_pace;
}

/**
@breif Getter function for the radius of the ball.
~~~.cpp
int Ball::getRadius() const {
    return radius;
}
~~~
@return The radius of the ball.
*/
int Ball::getRadius() const {
    return radius;
}

/**
@breif Setter function for the X position of the ball.
~~~.cpp
void Ball::setXPosition(int new_x_position) {
    x_position = new_x_position;
}
~~~
@param new_x_position The new X position of the ball.
*/
void Ball::setXPosition(int new_x_position) {
    x_position = new_x_position;
}

/**
@breif Setter function for the Y position of the ball.
~~~.cpp
void Ball::setYPosition(int new_y_position) {
    y_position = new_y_position;
}
~~~
@param new_y_position The new Y position of the ball.
*/
void Ball::setYPosition(int new_y_position) {
    y_position = new_y_position;
}

/**
@breif Setter function for the X pace of the ball.
~~~.cpp
void Ball::setXPace(int new_x_pace) {
    x_pace = new_x_pace;
}
~~~
@param new_x_pace The new X pace of the ball.
*/
void Ball::setXPace(int new_x_pace) {
    x_pace = new_x_pace;
}

/**
@breif Setter function for the Y pace of the ball.
~~~.cpp
void Ball::setYPace(int new_y_pace) {
    y_pace = new_y_pace;
}
~~~
@param new_y_pace The new Y pace of the ball.
*/
void Ball::setYPace(int new_y_pace) {
    y_pace = new_y_pace;
}

/**
@breif Setter function for the radius of the ball.
~~~.cpp
void Ball::setRadius(int new_radius) {
    radius = new_radius;
}
~~~
@param new_radius The new radius of the ball.
*/
void Ball::setRadius(int new_radius) {
    radius = new_radius;
}

