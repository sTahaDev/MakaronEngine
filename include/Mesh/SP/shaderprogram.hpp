#ifndef SHADERPROGRAM_HPP
#define SHADERPROGRAM_HPP

#include <string>
#include <map>

class ShaderProgram
{
public:
  std::map<std::string, unsigned int> m_UniformVars;
  ShaderProgram();
  ~ShaderProgram();
  void attachShader(const char *fileName, unsigned int shaderType);
  void link();
  void use();
  void addUniform(const std::string &varName);
  int getUniformId(const std::string &varName);
  void setFloat(const std::string &varName, float Value);
  void addTail(ShaderProgram &program, std::string direction, float lenght, float velocityX, float velocityY);

private:
  unsigned int m_programId;

  std::string getShaderFromFile(const char *fileName);
  int orderX;
  int orderY;
  int orderLeft;
  int orderUp;
};

#endif
