APP_NAME = makaronengine
BUILD_DIR = ./
CPP_FILES = ../src/*.cpp
C_FILES = ../src/*.c

APP_DEFINES:=
APP_INCLUDES := -I../include -I../include/glad/glad.h -framework Opengl -framework Cocoa -framework IOKit
APP_LINKERS := -L../lib -lglfw3

MESH_INCLUDES := ../include/Mesh/mesh.cpp ../include/Mesh/SP/shaderprogram.cpp

build: 
	c++ $(CPP_FILES) $(C_FILES) $(MESH_INCLUDES)  -o $(BUILD_DIR)/$(APP_NAME) $(APP_INCLUDES)  $(APP_LINKERS)
	./$(BUILD_DIR)/$(APP_NAME)
