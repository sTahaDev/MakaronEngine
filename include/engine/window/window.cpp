#include "window.hpp"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include <cstdlib>

bool Input::getKeyDown(GLFWwindow *window,int key) {
    
    return glfwGetKey(window, key) == GLFW_PRESS;
}
Input::keyEngine Input::keyCode;
Window::Window(const char *title, int width, int height)
{   
    
    glfwInit();

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    window = glfwCreateWindow(width, height, title, nullptr, nullptr);
    WindowId = window;
    
    if (window == nullptr)
    {
        const char *error_str;
        glfwGetError(&error_str);
        std::cout << "Failed to create window, error: " << error_str << '\n';
    }
    
    glfwMakeContextCurrent(window);
    gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
}

bool Window::WindowShouldClose()
{
    return glfwWindowShouldClose(window);
}

void Window::ClearScreen()
{
    glClearColor(0.52f, 0.52f, 0.52f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    
}

void Window::Repeat()
{
    glfwSwapBuffers(window);
    glfwPollEvents();
}

void Window::Terminate(){
    glfwTerminate();
}

