#include "raylib.h"

int main() {
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(800, 600, "Test window");

    Camera camera = {
            {5, 5, 5}, {0, 0, 0}, {0, 1, 0},
            45, CAMERA_PERSPECTIVE};
    Model model = LoadModelFromMesh(GenMeshCube(1, 1, 1));

    while (!WindowShouldClose()) {
        BeginDrawing();

        ClearBackground(WHITE);

        BeginMode3D(camera);
        DrawModel(model, {0, 0, 0}, 1, RED);
        EndMode3D();

        DrawText("Test text", 100, 100, 20, LIGHTGRAY);

        EndDrawing();
    }

    UnloadModel(model);
    CloseWindow();
    return 0;
}
