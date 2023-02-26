#include <raylib.h>
#include "SimplexNoise.h"

class Terrain {
    SimplexNoise noise;
    Texture2D atlas;

public:
    Terrain();
    void move(Vector2 position);
    void update();
    unsigned int getTile(Vector2 position);
    void drawTile(Rectangle screenPosition, Vector2 mapPosition);
};

