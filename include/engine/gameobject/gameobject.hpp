#include "SP/shaderprogram.hpp"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <engine/vector/vector.hpp>

class GameObject
{
public:
    Vector2 position;
    GameObject(GLFWwindow *windoww);
    
    void render();
    void create(char *fileName,float x,float y, int widthMesh,int heightMesh);
    GameObject(const GameObject &other);
    

private:
    unsigned int VBO;
    unsigned int VAO;
    float velocityX;
    float velocityY;
    ShaderProgram program;
    GLFWwindow *window;
    int inPositionId;
    
    Vector2 startPosition;
    
};