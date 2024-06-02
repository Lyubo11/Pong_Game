#ifndef PONG_GAME_PLAYER_PADDLE_H
#define PONG_GAME_PLAYER_PADDLE_H

#include "paddle.h"

// Class definition for the PlayerPaddle which inherits from the Paddle class
class PlayerPaddle : public Paddle {
private:
    int up_key;
    int down_key;
public:
    PlayerPaddle(double x_position, double y_position, double paddle_width, double paddle_height, int movement_speed, int up_key, int down_key);

    void UpdatePlayerPaddle();

    [[nodiscard]] int getUpKey() const;
    [[nodiscard]] int getDownKey() const;

    void setUpKey(int new_up_key);
    void setDownKey(int new_down_key);
};

#endif //PONG_GAME_PLAYER_PADDLE_H
