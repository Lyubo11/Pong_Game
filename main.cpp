#include <iostream>
#include <raylib.h>

const int screen_width = 800;
const int screen_height = 600;

int main() {
    InitWindow(screen_width, screen_height, "Pong Game");
    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BEIGE);

        DrawText("Pong Game", screen_width / 2 - 55, screen_height / 2 - 15, 20, BROWN);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
