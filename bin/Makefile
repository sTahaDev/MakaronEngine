APP_NAME = makaronengine
BUILD_DIR = ./
CPP_FILES = ../src/*.cpp
GLAD_FILES = ../include/glad/glad.c

APP_DEFINES:=
APP_INCLUDES := -I../include -I../include/glad/glad.h -framework Opengl -framework Cocoa -framework IOKit 
APP_LINKERS := -L../lib -lglfw3

GAMEOBJECT_INCLUDES := ../include/engine/gameobject/gameobject.cpp ../include/engine/gameobject/SP/shaderprogram.cpp
WINDOW_INCLUDES := ../include/engine/window/window.cpp

build: 
	c++ -std=c++11 $(CPP_FILES) $(GLAD_FILES) $(WINDOW_INCLUDES) $(GAMEOBJECT_INCLUDES)  -o $(BUILD_DIR)/$(APP_NAME) $(APP_INCLUDES)  $(APP_LINKERS)
	./$(BUILD_DIR)/$(APP_NAME)
