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
  
  int getUniformId(const std::string &varName);
  void setFloat(int varName,int x,int y);

private:
  unsigned int m_programId;

  std::string getShaderFromFile(const char *fileName);
  int orderX;
  int orderY;
  int orderLeft;
  int orderUp;
  
};

#endif
