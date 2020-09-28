#include "Entity.hpp"

Entity::Entity() {
    lua.open_libraries(sol::lib::base);
    lua.script(R"(
    function onFrame(dt)
        print("Hello! " .. dt)
    end
    )");
}

Entity::Entity(const string &_type, float x, float y) : Entity() {
    type = _type;
    pos.x = x;
    pos.y = y;
}

Entity::~Entity() {

}

void Entity::Update(float dt) {
    lua["onFrame"](dt);
}

void Entity::Render() {

}
