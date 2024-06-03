#include "../header-files/player_paddle.h"
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
@brief Constructor for the PlayerPaddle class.

Initializes the player paddle with the specified position, size, speed, and control keys.

@param x_position Initial x-position of the paddle.
@param y_position Initial y-position of the paddle.
@param paddle_width Width of the paddle.
@param paddle_height Height of the paddle.
@param movement_speed Speed at which the paddle moves.
@param up_key Key for moving the paddle up.
@param down_key Key for moving the paddle down.
*/
PlayerPaddle::PlayerPaddle(double x_position, double y_position, double paddle_width, double paddle_height, int movement_speed, int up_key, int down_key) : Paddle() {
    setXPosition(x_position);
    setYPosition(y_position);

    setPaddleWidth(paddle_width);
    setPaddleHeight(paddle_height);

    setMovementSpeed(movement_speed);

    setUpKey(up_key);
    setDownKey(down_key);
}

/**
@brief Updates the player paddle's position based on user input.

This function checks if the up or down keys are pressed and moves the paddle accordingly.
The paddle's movement is restricted within the screen boundaries.
*/
void PlayerPaddle::UpdatePlayerPaddle() {
    if (IsKeyDown(up_key)) {
        setYPosition(getYPosition() - getMovementSpeed());
    }
    if (IsKeyDown(down_key)) {
        setYPosition(getYPosition() + getMovementSpeed());
    }
    LimitMovement();
}

/**
@brief Getter for the up key.
~~~.cpp
int PlayerPaddle::getUpKey() const {
    return up_key;
}
~~~
@return The key code for moving the paddle up.
*/
int PlayerPaddle::getUpKey() const {
    return up_key;
}

/**
@brief Setter for the up key.
~~~.cpp
void PlayerPaddle::setUpKey(int new_up_key) {
    up_key = new_up_key;
}
~~~
@param new_up_key The new key code for moving the paddle up.
*/
void PlayerPaddle::setUpKey(int new_up_key) {
    up_key = new_up_key;
}

/**
@brief Getter for the down key.
~~~.cpp
int PlayerPaddle::getDownKey() const {
    return down_key;
}
~~~
@return The key code for moving the paddle down.
*/
int PlayerPaddle::getDownKey() const {
    return down_key;
}

/**
@brief Setter for the down key.
~~~.cpp
void PlayerPaddle::setDownKey(int new_down_key) {
    down_key = new_down_key;
}
~~~
@param new_down_key The new key code for moving the paddle down.
*/
void PlayerPaddle::setDownKey(int new_down_key) {
    down_key = new_down_key;
}
