#include "../header-files/doctest.h"
#include "../header-files/ai_paddle.h"

extern const int screen_width;
extern const int screen_height;

class AIPaddleTest {
public:
    AIPaddle ai_paddle;

    AIPaddleTest() : ai_paddle(100.0, 100.0, 15.0, 85.0, 5) {}
};

TEST_CASE("AI Paddle position validation") {
    AIPaddleTest test_ai_paddle;

    SUBCASE("X position") {
        CHECK_EQ(test_ai_paddle.ai_paddle.getXPosition(), 100.0);
    }

    SUBCASE("Y position") {
        CHECK_EQ(test_ai_paddle.ai_paddle.getYPosition(), 100.0);
    }

    SUBCASE("Set X position") {
        test_ai_paddle.ai_paddle.setXPosition(200.0);
        CHECK_EQ(test_ai_paddle.ai_paddle.getXPosition(), 200.0);
    }

    SUBCASE("Set Y position") {
        test_ai_paddle.ai_paddle.setYPosition(200.0);
        CHECK_EQ(test_ai_paddle.ai_paddle.getYPosition(), 200.0);
    }
}

TEST_CASE("AI Paddle dimensions validation") {
    AIPaddleTest test_ai_paddle;

    SUBCASE("Width") {
        CHECK_EQ(test_ai_paddle.ai_paddle.getPaddleWidth(), 15.0);
    }

    SUBCASE("Height") {
        CHECK_EQ(test_ai_paddle.ai_paddle.getPaddleHeight(), 85.0);
    }

    SUBCASE("Set Width") {
        test_ai_paddle.ai_paddle.setPaddleWidth(20.0);
        CHECK_EQ(test_ai_paddle.ai_paddle.getPaddleWidth(), 20.0);
    }

    SUBCASE("Set Height") {
        test_ai_paddle.ai_paddle.setPaddleHeight(200.0);
        CHECK_EQ(test_ai_paddle.ai_paddle.getPaddleHeight(), 200.0);
    }
}

TEST_CASE("AI Paddle movement speed validation") {
    AIPaddleTest test_ai_paddle;

    SUBCASE("Movement speed") {
        CHECK_EQ(test_ai_paddle.ai_paddle.getMovementSpeed(), 5);
    }

    SUBCASE("Set Movement speed") {
        test_ai_paddle.ai_paddle.setMovementSpeed(10);
        CHECK_EQ(test_ai_paddle.ai_paddle.getMovementSpeed(), 10);
    }
}

TEST_CASE("AI Paddle movement limit validation") {
    AIPaddleTest test_ai_paddle;

    SUBCASE("Limit Y position above screen") {
        test_ai_paddle.ai_paddle.setYPosition(-10.0);
        test_ai_paddle.ai_paddle.LimitMovement();
        CHECK_EQ(test_ai_paddle.ai_paddle.getYPosition(), 0.0);
    }

    SUBCASE("Limit Y position below screen") {
        test_ai_paddle.ai_paddle.setYPosition(screen_height + 10.0);
        test_ai_paddle.ai_paddle.LimitMovement();
        CHECK_EQ(test_ai_paddle.ai_paddle.getYPosition(), screen_height - test_ai_paddle.ai_paddle.getPaddleHeight());
    }
}

TEST_CASE("AI Paddle update position based on ball position") {
    AIPaddleTest test_ai_paddle;

    SUBCASE("Ball is above the paddle center") {
        test_ai_paddle.ai_paddle.UpdateAIPaddle(50.0);
        CHECK_EQ(test_ai_paddle.ai_paddle.getYPosition(), 95.0);
    }

    SUBCASE("Ball is below the paddle center") {
        test_ai_paddle.ai_paddle.UpdateAIPaddle(150.0);
        CHECK_EQ(test_ai_paddle.ai_paddle.getYPosition(), 105.0);
    }
}
