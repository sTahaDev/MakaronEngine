#include "SP/shaderprogram.hpp"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <engine/vector/vector.hpp>

static std::string internalPath = "../Assets/";

class GameObject
{
public:
    
    Vector2 position;
    GameObject(GLFWwindow *windoww);
    
    void render();
    void create(std::string fileName,float x,float y, int widthMesh,int heightMesh);
    GameObject(const GameObject &other);
    

private:
    unsigned int VBO;
    unsigned int VAO;
    ShaderProgram program;
    GLFWwindow *window;
    Vector2 startPosition;
    
};