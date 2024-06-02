#include "player_paddle.h"
#include <raylib.h>

// External constants for screen dimensions
extern const int screen_width;
extern const int screen_height;

// Constructor for the PlayerPaddle class, initializes the player paddle with the specified position, size, speed, and control keys
PlayerPaddle::PlayerPaddle(double x_position, double y_position, double paddle_width, double paddle_height, int movement_speed, int up_key, int down_key) : Paddle() {
    setXPosition(x_position);
    setYPosition(y_position);

    setPaddleWidth(paddle_width);
    setPaddleHeight(paddle_height);

    setMovementSpeed(movement_speed);

    setUpKey(up_key);
    setDownKey(down_key);
}

// Update the player paddle's position based on user input
void PlayerPaddle::UpdatePlayerPaddle() {
    if (IsKeyDown(up_key)) {
        setYPosition(getYPosition() - getMovementSpeed());
    }
    if (IsKeyDown(down_key)) {
        setYPosition(getYPosition() + getMovementSpeed());
    }
    LimitMovement();
}

// Getter for the up key
int PlayerPaddle::getUpKey() const {
    return up_key;
}

// Setter for the up key
void PlayerPaddle::setUpKey(int new_up_key) {
    up_key = new_up_key;
}

// Getter for the down key
int PlayerPaddle::getDownKey() const {
    return down_key;
}

// Setter for the down key
void PlayerPaddle::setDownKey(int new_down_key) {
    down_key = new_down_key;
}
