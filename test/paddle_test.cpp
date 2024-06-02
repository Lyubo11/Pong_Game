#define DOCTEST_CONFIG_IMPLEMENT//_WITH_MAIN
#include "../header-files/doctest.h"
#include "../header-files/paddle.h"

extern const int screen_width;
extern const int screen_height;

extern const int x_spawn_range;
extern const int y_spawn_range;

extern const int init_ball_x_speed;
extern const int init_ball_y_speed;

class PaddleTest {
public:
    Paddle paddle;

    PaddleTest() {
        // Initialize the paddle with default values
        paddle.setXPosition(10.0);
        paddle.setYPosition(100.0);
        paddle.setPaddleWidth(15.0);
        paddle.setPaddleHeight(85.0);
        paddle.setMovementSpeed(5);
    }
};

TEST_CASE("Paddle position validation") {
    PaddleTest paddle_test;

    SUBCASE("X position") {
        CHECK_EQ(paddle_test.paddle.getXPosition(), 10.0);
    }

    SUBCASE("Y position") {
        CHECK_EQ(paddle_test.paddle.getYPosition(), 100.0);
    }

    SUBCASE("Set X position") {
        paddle_test.paddle.setXPosition(200.0);
        CHECK_EQ(paddle_test.paddle.getXPosition(), 200.0);
    }

    SUBCASE("Set Y position") {
        paddle_test.paddle.setYPosition(200.0);
        CHECK_EQ(paddle_test.paddle.getYPosition(), 200.0);
    }
}

TEST_CASE("Paddle dimensions validation") {
    PaddleTest paddle_test;

    SUBCASE("Width") {
        CHECK_EQ(paddle_test.paddle.getPaddleWidth(), 15.0);
    }

    SUBCASE("Height") {
        CHECK_EQ(paddle_test.paddle.getPaddleHeight(), 85.0);
    }

    SUBCASE("Set Width") {
        paddle_test.paddle.setPaddleWidth(20.0);
        CHECK_EQ(paddle_test.paddle.getPaddleWidth(), 20.0);
    }

    SUBCASE("Set Height") {
        paddle_test.paddle.setPaddleHeight(200.0);
        CHECK_EQ(paddle_test.paddle.getPaddleHeight(), 200.0);
    }
}

TEST_CASE("Paddle movement speed validation") {
    PaddleTest paddle_test;

    SUBCASE("Movement speed") {
        CHECK_EQ(paddle_test.paddle.getMovementSpeed(), 5);
    }

    SUBCASE("Set Movement speed") {
        paddle_test.paddle.setMovementSpeed(10);
        CHECK_EQ(paddle_test.paddle.getMovementSpeed(), 10);
    }
}

TEST_CASE("Paddle movement limit validation") {
    PaddleTest paddle_test;

    SUBCASE("Limit Y position above screen") {
        paddle_test.paddle.setYPosition(-10.0);
        paddle_test.paddle.LimitMovement();
        CHECK_EQ(paddle_test.paddle.getYPosition(), 0.0);
    }

    SUBCASE("Limit Y position below screen") {
        paddle_test.paddle.setYPosition(screen_height + 10.0);
        paddle_test.paddle.LimitMovement();
        CHECK_EQ(paddle_test.paddle.getYPosition(), screen_height - paddle_test.paddle.getPaddleHeight());
    }
}
