#include "Terrain.hpp"
#include <iostream>

int main(int argc, const char* argv[]) 
{
    Terrain terrain = Terrain();
    for(int i = 0; i < 20; i++) {
        for(int j = 0; j < 100; j++) {
            std::cout << terrain.get_tile({(float)i/10, (float)j/20});
        }
        std::cout << std::endl;
    }

    return 0;
}
