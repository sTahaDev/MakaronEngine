#include "./shaderprogram.hpp"
#include <glad/glad.h>
#include <fstream>
#include <iostream>
#include <map>
#include <memory>
#include <string>

ShaderProgram::ShaderProgram()
{
  m_programId = glCreateProgram();
 
}

ShaderProgram::~ShaderProgram()
{
  glDeleteProgram(m_programId);
}

void ShaderProgram::link()
{
  glLinkProgram(m_programId);

  int isLinked;
  char log[512];

  glGetShaderiv(m_programId, GL_LINK_STATUS, &isLinked);
  if (!isLinked)
  {
    glGetProgramInfoLog(m_programId, 512, 0, log);
    std::cout << "Shader Link Error: " << log << std::endl;
  }
}

void ShaderProgram::addUniform(const std::string &varName)
{
  m_UniformVars[varName] = glGetUniformLocation(m_programId, varName.c_str());
  
}

int ShaderProgram::getUniformId(const std::string &varName)
{
  return glGetUniformLocation(m_programId, varName.c_str());
}

void ShaderProgram::setFloat(int varName,int x,int y)
{
  glUniform3f(glGetUniformLocation(m_programId,"positionTranslate"),x,y,0.0f);
}

void ShaderProgram::use()
{
  glUseProgram(m_programId);
  orderX = 0;
  orderY = 0;
  orderLeft = 0;
  orderUp = 0;
}

void ShaderProgram::attachShader(const char *fileName, unsigned int shaderType)
{
  unsigned int shaderId = glCreateShader(shaderType);

  std::string sourceCod = getShaderFromFile(fileName);

  const char *chSourceCode = &sourceCod[0];

  glShaderSource(shaderId, 1, &chSourceCode, 0);

  glCompileShader(shaderId);

  int isCompiled;
  char log[512];

  glGetShaderiv(shaderId, GL_COMPILE_STATUS, &isCompiled);

  if (!isCompiled)
  {
    glGetShaderInfoLog(shaderId, 512, 0, log);
    std::cout << "Shader Type: " << shaderType << std::endl;
    std::cout << log << std::endl;
  }

  glAttachShader(m_programId, shaderId);

  glDeleteShader(shaderId);
}



std::string ShaderProgram::getShaderFromFile(const char *fileName)
{
  std::ifstream file(fileName);
  std::string data;

  if (file.is_open())
  {

    char readChar;

    while ((readChar = file.get()) != EOF)
    {
      data += readChar;
    }

    file.close();
  }

  return data;
}
