#pragma once

#include <stdio.h>
#include <string.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

namespace cphong { namespace graphics {

    class Window
    {
    private:
        unsigned int m_width, m_height;
        char* m_title;

        GLFWwindow* m_glfwWindow;
    public:
        Window(unsigned int width, unsigned int height, const char* title);
        ~Window();

        void clear() const;
        void update() const;
        bool close() const;

        void getCursorPos(double* x, double* y);
    private:
        inline void init();
    };

} }