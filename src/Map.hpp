#ifndef RAYTEST_MAP_HPP
#define RAYTEST_MAP_HPP

#include <string>
#include <vector>
using std::string;
using std::vector;

typedef struct {
    string name;
    string tileset;
    string background;
    bool wrapX, wrapY;
} MapInfo;

typedef struct {
    int index, attr;
} MapTile;

typedef struct {
    string type;
    int x, y;
} MapEntity;

class Map {
public:
    // Info / Metadata
    MapInfo info;
    
    // Tilemap
    int width, height;
    vector<MapTile> tiles;
    
    // Entity List
    vector<MapEntity> entities;
    
    Map();
    ~Map();
    
    void New(const string &name, int _width, int _height);
    void Resize(int _width, int _height);
    void Shift(int x, int y);
    
    template<class Archive>
    void serialize(Archive & archive) {
        archive(info, width, height, tiles, entities);
    }
};

#endif//RAYTEST_MAP_HPP
