#ifndef PONG_GAME_AI_PADDLE_H
#define PONG_GAME_AI_PADDLE_H

#include "paddle.h"

// Class declaration for the AI Paddle, which inherits from the Paddle class
class AIPaddle : public Paddle {
public:
    AIPaddle(double x_position, double y_position, double paddle_width, double paddle_height, int movement_speed);

    void UpdateAIPaddle(double y_position);
};


#endif //PONG_GAME_AI_PADDLE_H
