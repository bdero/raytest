#ifndef RAYTEST_ENTITY_HPP
#define RAYTEST_ENTITY_HPP

#include <raylib.h>
#include <raymath.h>
#include <sol/sol.hpp>
#include <string>
using std::string;

class Entity {
public:
    string type;
    string name;
    
    // Physics
    Vector2 pos, vel;
    Rectangle hitBox;
    
    // Behavior / AI
    sol::state lua;
    
    // Sprite
    Texture2D texture;
    Rectangle frameRec;
    Vector2 origin;
    int frame;
    
    Entity();
    Entity(const string &_type, float x, float y);
    ~Entity();
    
    void Update(float dt);
    void Render();
};

#endif//RAYTEST_ENTITY_HPP
