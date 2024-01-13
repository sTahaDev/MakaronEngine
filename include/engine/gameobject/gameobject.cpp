#include "gameobject.hpp"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#define STB_IMAGE_IMPLEMENTATION
#include "./stb/stb_image.h"
#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <engine/vector/vector.hpp>

GameObject::GameObject(GLFWwindow *windoww)
{
    window = windoww;
}

void GameObject::create(char *fileName, float x, float y, int widthMesh, int heightMesh)
{
    position.x = x;
    position.y = y;
    startPosition.x = x;
    startPosition.y = y;

    stbi_set_flip_vertically_on_load(true);
    int windowWidth, windowHeight;
    glfwGetFramebufferSize(window, &windowWidth, &windowHeight);
    windowWidth = windowWidth / 2;
    windowHeight = windowHeight / 2;

    float vertices[] = {
        x, y + heightMesh, 0.0f,
        x, y, 0.0f,
        x + widthMesh, y, 0.0f,
        x + widthMesh, y + heightMesh, 0.0f};

    float texCoords[] = {
        0.0f, 1.0f, // sol üst köşe noktası
        0.0f, 0.0f, // sol alt köşe noktası
        1.0f, 0.0f, // sağ alt köşe noktası
        1.0f, 1.0f  // sağ üst köşe noktası

    };

    program.attachShader("../include/engine/gameobject/shaders/simplevs.glsl", GL_VERTEX_SHADER);
    program.attachShader("../include/engine/gameobject/shaders/simplefs.glsl", GL_FRAGMENT_SHADER);
    program.link();

    program.addUniform("projectionMatrix");
    unsigned int projectionMatrixLoc = program.getUniformId("projectionMatrix");

    if (projectionMatrixLoc == -1)
    {
        std::cerr << "Uniform 'projectionMatrix' bulunamadı!" << std::endl;
        // Hata yönetimi eklenebilir.
    }

    glm::mat4 projectionMatrix = glm::ortho(0.0f, (float)windowWidth, 0.0f, (float)windowHeight, -1.0f, 1.0f);
    program.use();
    glUniformMatrix4fv(projectionMatrixLoc, 1, GL_FALSE, glm::value_ptr(projectionMatrix));

    glGenBuffers(1, &VBO);      // Oluştur
    glGenVertexArrays(1, &VAO); // Oluştur

    glBindVertexArray(VAO);             // Vertex Array'ı aktif etme
    glBindBuffer(GL_ARRAY_BUFFER, VBO); // Buffer'ı Aktif Etme

    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices) + sizeof(texCoords), NULL, GL_STATIC_DRAW); // Buffer boyutunu ayarla
    glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(vertices), vertices);                           // Vertex verilerini kopyala
    glBufferSubData(GL_ARRAY_BUFFER, sizeof(vertices), sizeof(texCoords), texCoords);          // Texture koordinatlarını kopyala

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *)0);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void *)(sizeof(vertices)));
    glEnableVertexAttribArray(1);

    unsigned int texture;
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);

    // Texture parametreleri ayarlama
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    // Texture yükleme
    int width, height, nrChannels;
    unsigned char *data = stbi_load(fileName, &width, &height, &nrChannels, 0);
    if (data)
    {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    }
    else
    {
        std::cout << "Failed to load texture" << std::endl;
    }
    stbi_image_free(data);
}

void GameObject::render()
{

    program.use();

    glBindVertexArray(VAO);
    program.setFloat(0, position.x - startPosition.x, position.y - startPosition.y);

    glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
}

// Copy constructor eklenmiş hali
GameObject::GameObject(const GameObject &other): window(other.window), position(other.position), startPosition(other.startPosition)
{
    window = other.window;
    position = other.position;
    startPosition = other.startPosition;
}

