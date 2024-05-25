#ifndef PONG_GAME_BALL_H
#define PONG_GAME_BALL_H

#include "paddle.h"

class Ball {
private:
    int x_position;
    int y_position;

    int x_pace;
    int y_pace;

    int radius;

public:
    Ball(int x_position, int y_position, int x_pace, int y_pace, int radius);
    void DrawBall() const;
    void UpdateBall();
    void ResetBall();
    void DetectPaddleCollision(Paddle& paddle);

    [[nodiscard]] int getXPosition() const;
    [[nodiscard]] int getYPosition() const;
    [[nodiscard]] int getXPace() const;
    [[nodiscard]] int getYPace() const;
    [[nodiscard]] int getRadius() const;

    void setXPosition(int new_x_position);
    void setYPosition(int new_y_position);
    void setXPace(int new_x_pace);
    void setYPace(int new_y_pace);
    void setRadius(int new_radius);
};


#endif //PONG_GAME_BALL_H
