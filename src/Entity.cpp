#include "Entity.hpp"

Entity::Entity() {
    lua.open_libraries(sol::lib::base);
    onFrame = lua.load(R"(
        local dt = ...
        print('dt = ' + dt)
    )");
}

Entity::Entity(const string &_type, float x, float y) {
    type = _type;
    pos.x = x;
    pos.y = y;
    Entity();
}

Entity::~Entity() {

}

void Entity::Update(float dt) {
    onFrame(dt);
}

void Entity::Render() {

}
