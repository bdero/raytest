extern "C" {
    #include <lua.h>
}
#include "sol/sol.hpp"
#include "raylib.h"

struct LuaThing {
    float something = 0;
};

void luaTest() {
    sol::state lua;
    lua.open_libraries(sol::lib::base);

    lua.script("print('Test print from the LUA VM.')");

    int important = 0;
    auto doThings = [&important]{
      printf("Important LUA business: %d\n", important);
      important++;
    };
    lua.set_function("do_things", doThings);
    lua.script("do_things()\ndo_things()\ndo_things()");

    lua.new_usertype<LuaThing>("Thing", "something", &LuaThing::something);
    lua.script(
            "thing = Thing.new()\n"
            "thing.something = 420.69");
    auto thing = lua.get<LuaThing>("thing");
    printf("Important values from LUA: %.2f\n", thing.something);
}

int main() {
    luaTest();

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
