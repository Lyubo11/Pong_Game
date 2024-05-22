#ifndef PONG_GAME_BALL_H
#define PONG_GAME_BALL_H


class Ball {
private:
    double x_position;
    double y_position;

    int x_pace;
    int y_pace;

    int radius;

public:
    Ball(double x_position, double y_position, int x_pace, int y_pace, int radius);
    void DrawBall();
    void UpdateBall();
    void ResetBall();
};


#endif //PONG_GAME_BALL_H
