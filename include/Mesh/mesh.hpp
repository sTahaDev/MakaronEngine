#include "SP/shaderprogram.hpp"
#include <glad/glad.h>
#include <GLFW/glfw3.h>

class Mesh
{
public:

    Mesh(GLFWwindow *windoww);
    void render();
    void create(char *fileName,float x,float y, int widthMesh,int heightMesh);

private:
    unsigned int VBO;
    unsigned int VAO;
    float velocityX;
    float velocityY;
    ShaderProgram program;
    GLFWwindow *window;
    
};