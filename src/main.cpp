#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include <cstdlib>

#include <Mesh/mesh.hpp>

int main(int argc, char **argv)
{
    glfwInit();

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    int windowWidth = 800;
    int windowHeight = 600;

    GLFWwindow *window = glfwCreateWindow(windowWidth, windowHeight, "Simple Window", nullptr, nullptr);

    if (window == nullptr)
    {
        const char *error_str;
        glfwGetError(&error_str);
        std::cout << "Failed to create window, error: " << error_str << '\n';

        return EXIT_FAILURE;
    }

    glfwMakeContextCurrent(window);
    gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);

    Mesh mymesh(window);
    Mesh mesh2(window);

    mymesh.create("../Assets/container.jpg", 0, 0, 300, 300);
    mesh2.create("../Assets/container.jpg",300,300,100,100);

    while (!glfwWindowShouldClose(window))
    {
        glClearColor(0.52f, 0.52f, 0.52f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        mymesh.render();
        mesh2.render();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();

    return EXIT_SUCCESS;
}
