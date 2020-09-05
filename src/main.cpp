#include <iostream>
#include "raylib.h"

int main() {
    std::cout << "test output" << std::endl;

    InitWindow(800, 600, "Test window");

    while (!WindowShouldClose()) {
        BeginDrawing();

        ClearBackground(Color {.r = 100, .g = 100, .b = 100});
        DrawText("Test text", 100, 100, 20, LIGHTGRAY);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
