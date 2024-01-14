// window.hpp
#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include <cstdlib>

class Window;

class Input
{
public:
    static struct keyEngine
    {
        int A = GLFW_KEY_A;
        int B = GLFW_KEY_B;
        int C = GLFW_KEY_C;
        int D = GLFW_KEY_D;
        int E = GLFW_KEY_E;
        int F = GLFW_KEY_F;
        int G = GLFW_KEY_G;
        int H = GLFW_KEY_H;
        int I = GLFW_KEY_I;
        int J = GLFW_KEY_J;
        int K = GLFW_KEY_K;
        int L = GLFW_KEY_L;
        int M = GLFW_KEY_M;
        int N = GLFW_KEY_N;
        int O = GLFW_KEY_O;
        int P = GLFW_KEY_P;
        int Q = GLFW_KEY_Q;
        int R = GLFW_KEY_R;
        int S = GLFW_KEY_S;
        int T = GLFW_KEY_T;
        int U = GLFW_KEY_U;
        int V = GLFW_KEY_V;
        int W = GLFW_KEY_W;
        int X = GLFW_KEY_X;
        int Y = GLFW_KEY_Y;
        int Z = GLFW_KEY_Z;
        int RIGHT = GLFW_KEY_RIGHT;
        int LEFT = GLFW_KEY_LEFT;
        int UP = GLFW_KEY_UP;
        int DOWN = GLFW_KEY_DOWN;
    } keyCode;

    static bool getKeyDown(GLFWwindow *windoww, int key);
};

class Window
{
public:
    GLFWwindow *WindowId;

    Window(const char *title, int width, int height);
    bool WindowShouldClose();
    void ClearScreen();
    void Repeat();
    void Terminate();

private:
    GLFWwindow *window;
};

#endif
