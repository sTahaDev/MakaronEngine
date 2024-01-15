#include "window.hpp"

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <thread>

#include <iostream>
#include <cstdlib>

bool Input::getKeyDown(GLFWwindow *window, int key)
{

    return glfwGetKey(window, key) == GLFW_PRESS;
}
Input::keyEngine Input::keyCode;
Window::Window(const char *title, int width, int height)
{
    lastTime = glfwGetTime();
    lastTime_getfps = glfwGetTime();
    frameCount = 0;
    isFpsLimit = 0;
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
    glfwSwapInterval(0);
}
void Window::setFps(const int fpsLimit)
{
    isFpsLimit = fpsLimit;
    double currentTime = glfwGetTime();
    deltaTime = currentTime - lastTime;
    lastTime = currentTime;

    if (deltaTime < 1.0 / fpsLimit)
    {
        double sleepTime = (1.0 / fpsLimit) - deltaTime;
        std::this_thread::sleep_for(std::chrono::duration<double>(sleepTime));
    }
}
bool Window::WindowShouldClose()
{
    return glfwWindowShouldClose(window);
}
double Window::getFps()
{
    frameCount++;
    double currentTime = glfwGetTime();
    double fps = 0.0;

    if (currentTime - lastTime_getfps >= 1.0)
    {
        fps = frameCount / (currentTime - lastTime_getfps);

        // Değişkenler sıfırlanır
        frameCount = 0;
        lastTime_getfps = currentTime;
        if(isFpsLimit != 0){
            return isFpsLimit;
        }
        return fps;
    }
    if(isFpsLimit != 0){
        return isFpsLimit;
    }
    return 0;
}

void Window::setVsync(int set){
    glfwSwapInterval(set);
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

void Window::Terminate()
{
    glfwTerminate();
}
