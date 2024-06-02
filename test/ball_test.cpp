#include "../header-files/doctest.h"
#include "../header-files/ball.h"

extern const int screen_width;
extern const int screen_height;

extern const int x_spawn_range;
extern const int y_spawn_range;

extern const int init_ball_x_speed;
extern const int init_ball_y_speed;

class BallTest {
public:
    Ball ball;

    BallTest() : ball(100, 100, 2, 3, 10) {}
};

TEST_CASE("Ball position validation") {
    BallTest ball_test;

    SUBCASE("X position") {
        CHECK_EQ(ball_test.ball.getXPosition(), 100);
    }

    SUBCASE("Y position") {
        CHECK_EQ(ball_test.ball.getYPosition(), 100);
    }

    SUBCASE("Set X position") {
        ball_test.ball.setXPosition(200);
        CHECK_EQ(ball_test.ball.getXPosition(), 200);
    }

    SUBCASE("Set Y position") {
        ball_test.ball.setYPosition(200);
        CHECK_EQ(ball_test.ball.getYPosition(), 200);
    }
}

TEST_CASE("Ball pace validation") {
    BallTest ball_test;

    SUBCASE("X pace") {
        CHECK_EQ(ball_test.ball.getXPace(), 2);
    }

    SUBCASE("Y pace") {
        CHECK_EQ(ball_test.ball.getYPace(), 3);
    }

    SUBCASE("Set X pace") {
        ball_test.ball.setXPace(4);
        CHECK_EQ(ball_test.ball.getXPace(), 4);
    }

    SUBCASE("Set Y pace") {
        ball_test.ball.setYPace(5);
        CHECK_EQ(ball_test.ball.getYPace(), 5);
    }
}

TEST_CASE("Ball radius validation") {
    BallTest ball_test;

    SUBCASE("Radius") {
        CHECK_EQ(ball_test.ball.getRadius(), 10);
    }

    SUBCASE("Set Radius") {
        ball_test.ball.setRadius(15);
        CHECK_EQ(ball_test.ball.getRadius(), 15);
    }
}

TEST_CASE("Ball movement and collision validation") {
    BallTest ball_test;

    SUBCASE("Update Ball position") {
        int initial_x = ball_test.ball.getXPosition();
        int initial_y = ball_test.ball.getYPosition();

        ball_test.ball.UpdateBall();

        CHECK_EQ(ball_test.ball.getXPosition(), initial_x + ball_test.ball.getXPace());
        CHECK_EQ(ball_test.ball.getYPosition(), initial_y + ball_test.ball.getYPace());
    }

    SUBCASE("Limit Y position") {
        ball_test.ball.setYPosition(screen_height + 10);
        ball_test.ball.UpdateBall();
        CHECK_EQ(ball_test.ball.getYPace(), -3);

        ball_test.ball.setYPosition(-10);
        ball_test.ball.UpdateBall();
        CHECK_EQ(ball_test.ball.getYPace(), 3);
    }

    SUBCASE("Reset Ball") {
        ball_test.ball.ResetBall();

        CHECK_EQ(ball_test.ball.getXPace(), init_ball_x_speed);
        CHECK_EQ(ball_test.ball.getYPace(), init_ball_y_speed);
        CHECK_GE(ball_test.ball.getXPosition(), screen_width / 2 - x_spawn_range);
        CHECK_GE(ball_test.ball.getYPosition(), screen_height / 2 - y_spawn_range);
    }

    SUBCASE("Detect Paddle Collision") {
        Paddle paddle_test;
        paddle_test.setXPosition(90);
        paddle_test.setYPosition(90);
        paddle_test.setPaddleWidth(20);
        paddle_test.setPaddleHeight(20);

        ball_test.ball.setXPosition(100);
        ball_test.ball.setYPosition(100);
        ball_test.ball.setXPace(2);
        ball_test.ball.setYPace(2);

        ball_test.ball.DetectPaddleCollision(paddle_test);

        CHECK_EQ(ball_test.ball.getXPace(), -3);
        CHECK_EQ(ball_test.ball.getYPace(), 3);
    }
}