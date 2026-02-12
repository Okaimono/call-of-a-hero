#pragma once

#include "glad/glad.h"
#include "GLFW/glfw3.h"

class Window {
public:
    Window(int width, int height, const char* title);
    ~Window();
    
    bool shouldClose() const;
    void pollEvents();
    void swapBuffers();  
 
    GLFWwindow* getHandle() { return window; }
    int getWidth() const { return width; }
    int getHeight() const { return height; }

private:
    GLFWwindow* window;
    int width, height;
}; 