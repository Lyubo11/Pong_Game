cmake_minimum_required(VERSION 3.28)
project(Pong_Game)

# Dependencies
include(FetchContent)

set(RAYLIB_VERSION 5.0)
FetchContent_Declare(
        raylib
        URL https://github.com/raysan5/raylib/archive/refs/tags/${RAYLIB_VERSION}.tar.gz
        FIND_PACKAGE_ARGS ${RAYLIB_VERSION}
)
set(BUILD_EXAMPLES OFF CACHE INTERNAL "")
FetchContent_MakeAvailable(raylib)

# Our Project
set(SOURCE_FILES source-files/main.cpp
        source-files/ball.cpp
        header-files/ball.h
        source-files/paddle.cpp
        header-files/paddle.h
        source-files/ai_paddle.cpp
        header-files/ai_paddle.h
        source-files/player_paddle.cpp
        header-files/player_paddle.h
        test/paddle_test.cpp
        header-files/doctest.h
        test/player_paddle_test.cpp
        test/ai_paddle_test.cpp
        test/ball_test.cpp
)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})
target_link_libraries(${PROJECT_NAME} raylib)

set(CMAKE_CXX_STANDARD 17)