#include "window.h"

namespace cphong { namespace graphics {

    Window::Window(unsigned int width, unsigned int height, const char* title)
        : m_width(width), m_height(height)
    {
        m_title = new char[strlen(title) + 1];
        strcpy(m_title, title);

        init();
    }

    Window::~Window()
    {
        delete[] m_title;
        glfwTerminate();
    }

    void Window::clear() const
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }

    void Window::update() const
    {
        glfwSwapBuffers(m_glfwWindow);
        glfwPollEvents();
    }

    bool Window::close() const
    {
        return glfwWindowShouldClose(m_glfwWindow) == 1;
    }

    void Window::getCursorPos(double* x, double* y)
    {
        glfwGetCursorPos(m_glfwWindow, x, y);
    }

    void Window::init()
    {
        if (!glfwInit())
        {
            fprintf(stderr, "Could not initialize GLFW");
            return;
        }

        glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
        m_glfwWindow = glfwCreateWindow(m_width, m_height, m_title, NULL, NULL);
        if (!m_glfwWindow)
        {
            glfwTerminate();
            fprintf(stderr, "Could not create GLFWwindow");
            return;
        }
        glfwMakeContextCurrent(m_glfwWindow);

        if (glewInit() != GLEW_OK)
        {
            glfwTerminate();
            fprintf(stderr, "Could not initialize GLEW");
            return;
        }
        glEnable(GL_DEPTH_TEST);
    }

} }