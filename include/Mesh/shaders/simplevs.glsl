#version 330 core
layout (location = 0) in vec3 inPosition;
layout(location = 1) in vec2 aTexCoord; // Texture koordinatları için yeni özellik
out vec2 TexCoord; // Fragment shader'a geçirmek için çıkış özelliği

uniform mat4 projectionMatrix;

void main()
{
    gl_Position = projectionMatrix * vec4(inPosition, 1.0);
    TexCoord = aTexCoord; // Texture koordinatlarını fragment shader'a geçir
}
