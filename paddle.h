#ifndef PONG_GAME_PADDLE_H
#define PONG_GAME_PADDLE_H

// Paddle class declaration
class Paddle {
private:
    double x_position;
    double y_position;

    double paddle_width;
    double paddle_height;

    int movement_speed;

public:
    void DrawPaddle() const;
    void LimitMovement();

    // [[nodiscard]] so that getter function return values do not get discarded
    [[nodiscard]] double getXPosition() const;
    [[nodiscard]] double getYPosition() const;
    [[nodiscard]] double getPaddleWidth() const;
    [[nodiscard]] double getPaddleHeight() const;
    [[nodiscard]] int getMovementSpeed() const;

    void setXPosition(double new_x_position);
    void setYPosition(double new_y_position);
    void setPaddleWidth(double new_paddle_width);
    void setPaddleHeight(double new_paddle_height);
    void setMovementSpeed(int new_movement_speed);
};


#endif //PONG_GAME_PADDLE_H
