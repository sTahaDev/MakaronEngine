#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include <cstdlib>



class Window
{

public:
    
    GLFWwindow *WindowId;
    Window(char *title, int width, int height);
    bool WindowShouldClose();
    void ClearScreen();
    void Repeat();
    void Terminate();

private:
    GLFWwindow *window;
};

#endif