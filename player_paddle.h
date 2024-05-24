#ifndef PONG_GAME_PLAYER_PADDLE_H
#define PONG_GAME_PLAYER_PADDLE_H

#include "paddle.h"

class PlayerPaddle : public Paddle {
public:
    PlayerPaddle(double x_position, double y_position, double paddle_width, double paddle_height, int movement_speed);

    void UpdatePlayerPaddle();
};

#endif //PONG_GAME_PLAYER_PADDLE_H
