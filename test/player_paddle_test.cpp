#include "../header-files/doctest.h"
#include "../header-files/player_paddle.h"
#include "raylib.h"

extern const int screen_width;
extern const int screen_height;

class PlayerPaddleTest {
public:
    PlayerPaddle playerPaddle;

    PlayerPaddleTest() : playerPaddle(10.0, 100.0, 15.0, 85.0, 5, KEY_UP, KEY_DOWN) {}
};

TEST_CASE("PlayerPaddle position validation") {
    PlayerPaddleTest player_paddle_test;

    SUBCASE("X position") {
        CHECK_EQ(player_paddle_test.playerPaddle.getXPosition(), 10.0);
    }

    SUBCASE("Y position") {
        CHECK_EQ(player_paddle_test.playerPaddle.getYPosition(), 100.0);
    }

    SUBCASE("Set X position") {
        player_paddle_test.playerPaddle.setXPosition(200.0);
        CHECK_EQ(player_paddle_test.playerPaddle.getXPosition(), 200.0);
    }

    SUBCASE("Set Y position") {
        player_paddle_test.playerPaddle.setYPosition(200.0);
        CHECK_EQ(player_paddle_test.playerPaddle.getYPosition(), 200.0);
    }
}

TEST_CASE("PlayerPaddle dimensions validation") {
    PlayerPaddleTest player_paddle_test;

    SUBCASE("Width") {
        CHECK_EQ(player_paddle_test.playerPaddle.getPaddleWidth(), 15.0);
    }

    SUBCASE("Height") {
        CHECK_EQ(player_paddle_test.playerPaddle.getPaddleHeight(), 85.0);
    }

    SUBCASE("Set Width") {
        player_paddle_test.playerPaddle.setPaddleWidth(20.0);
        CHECK_EQ(player_paddle_test.playerPaddle.getPaddleWidth(), 20.0);
    }

    SUBCASE("Set Height") {
        player_paddle_test.playerPaddle.setPaddleHeight(200.0);
        CHECK_EQ(player_paddle_test.playerPaddle.getPaddleHeight(), 200.0);
    }
}

TEST_CASE("PlayerPaddle movement speed validation") {
    PlayerPaddleTest player_paddle_test;

    SUBCASE("Movement speed") {
        CHECK_EQ(player_paddle_test.playerPaddle.getMovementSpeed(), 5);
    }

    SUBCASE("Set Movement speed") {
        player_paddle_test.playerPaddle.setMovementSpeed(10);
        CHECK_EQ(player_paddle_test.playerPaddle.getMovementSpeed(), 10);
    }
}

TEST_CASE("PlayerPaddle key validation") {
    PlayerPaddleTest player_paddle_test;

    SUBCASE("Up key") {
        CHECK_EQ(player_paddle_test.playerPaddle.getUpKey(), KEY_UP);
    }

    SUBCASE("Set Up key") {
        player_paddle_test.playerPaddle.setUpKey(KEY_W);
        CHECK_EQ(player_paddle_test.playerPaddle.getUpKey(), KEY_W);
    }

    SUBCASE("Down key") {
        CHECK_EQ(player_paddle_test.playerPaddle.getDownKey(), KEY_DOWN);
    }

    SUBCASE("Set Down key") {
        player_paddle_test.playerPaddle.setDownKey(KEY_S);
        CHECK_EQ(player_paddle_test.playerPaddle.getDownKey(), KEY_S);
    }
}

TEST_CASE("PlayerPaddle movement limit validation") {
    PlayerPaddleTest player_paddle_test;

    SUBCASE("Limit Y position above screen") {
        player_paddle_test.playerPaddle.setYPosition(-10.0);
        player_paddle_test.playerPaddle.LimitMovement();
        CHECK_EQ(player_paddle_test.playerPaddle.getYPosition(), 0.0);
    }

    SUBCASE("Limit Y position below screen") {
        player_paddle_test.playerPaddle.setYPosition(screen_height + 10.0);
        player_paddle_test.playerPaddle.LimitMovement();
        CHECK_EQ(player_paddle_test.playerPaddle.getYPosition(), screen_height - player_paddle_test.playerPaddle.getPaddleHeight());
    }
}
