#ifndef PONG_GAME_PADDLE_H
#define PONG_GAME_PADDLE_H


class Paddle {
private:
    double x_position;
    double y_position;

    double paddle_width;
    double paddle_height;

    int movement_speed;

public:
    Paddle(double x_position, double y_position, double paddle_width, double paddle_height, int movement_speed);
    void DrawPaddle();
    void UpdatePaddle();
    void LimitMovement();

    double getXPosition() const;
    double getYPosition() const;
    double getPaddleWidth() const;
    double getPaddleHeight() const;
    int getMovementSpeed() const;

    void setXPosition(double new_x_position);
    void setYPosition(double new_y_position);
    void setPaddleWidth(double new_paddle_width);
    void setPaddleHeight(double new_paddle_height);
    void setMovementSpeed(int new_movement_speed);
};


#endif //PONG_GAME_PADDLE_H
