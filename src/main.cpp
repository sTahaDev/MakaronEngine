#include <iostream>
#include <cstdlib>

#include <engine/gameobject/gameobject.hpp>
#include <engine/window/window.hpp>

int main(int argc, char **argv)
{
    int windowWidth = 800;
    int windowHeight = 600;

    Window window("Makaron Engine",windowWidth,windowHeight);
    
    GameObject box(window.WindowId);
    box.create(internalPath+"container.jpg",100,100,200,200);
    
    while (!window.WindowShouldClose())
    {
        window.ClearScreen();
        
        box.render();
        box.position.x += 1;
        
        window.Repeat();
    }

    window.Terminate();
    return 0;
}
