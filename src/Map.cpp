#include "Map.hpp"

#include <cstring>

#define min(a,b) ((a)>(b)?(b):(a))
#define max(a,b) ((a)<(b)?(b):(a))

Map::Map() {
    New("Untitled", 40, 30);
}

Map::~Map() = default;

void Map::New(const string &name, int _width, int _height) {
    info.name = name;
    info.wrapX = false;
    info.wrapY = false;
    width = _width;
    height = _height;
    tiles = vector<MapTile>(width * height);
}

void Map::Resize(int _width, int _height) {
    vector<MapTile> temp(_width * _height);
    for(int y = 0; y < min(height, _height); y++) {
        memcpy(&temp[y * width], &tiles[y * _width], sizeof(MapTile) * min(width, _width));
    }
    tiles = temp;
    width = _width;
    height = _height;
}

void Map::Shift(int x, int y) {
    vector<MapTile> temp(width * height);
    for(int yy = 0; yy < height; yy++) {
        if(yy < y || yy >= height + y) {
            memset(&temp[yy * width], 0, sizeof(MapTile) * width);
        } else {
            int xst = max(x, 0);
            int xln = min(width + x, width);
            memcpy(&temp[yy * width], &tiles[(y+yy) * width + xst], sizeof(MapTile) * xln);
        }
    }
    tiles = temp;
}
