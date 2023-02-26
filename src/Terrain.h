#include <raylib.h>
#include "SimplexNoise.h"

const unsigned int renderSize = 75;

class Terrain {
    SimplexNoise noise;
    Texture2D atlas;

    Vector2 position;

public:
    explicit Terrain();
    void move(Vector2 position);
    void update();
	void render();
    unsigned int getTile(Vector2 position);
    void drawTile(Rectangle screenPosition, Vector2 mapPosition);
};

