#include "Window.h"

void glfwErrorCallback(int error, const char* description) {
    spdlog::warn("GLFW Error (" + std::to_string(error) + "): " + description);
}

namespace brayjl {
    Window::Window(const std::uint32_t& width, const std::uint32_t& height, const std::string& name)
        : m_width(width), m_height(height), m_name(name) {
        createGlfwWindow();
        initializeGlad();
        enableGLFeatures();
    }

    Window::~Window() {
        glfwDestroyWindow(m_window);
        glfwTerminate();
    }

    bool Window::shouldClose() const {
        return glfwWindowShouldClose(m_window);
    }

    void Window::update() {
        glfwPollEvents();
        glfwSwapBuffers(m_window);

        glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }

    void Window::createGlfwWindow() {
        if (Utilities::getEnableDebugMessages()) {
            glfwSetErrorCallback(glfwErrorCallback);
        }

        if (!glfwInit()) {
            spdlog::error("Failed to initialize GLFW.");
            return;
        }

        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);

        m_window = glfwCreateWindow(m_width, m_height, m_name.c_str(), nullptr, nullptr);
        if (m_window == nullptr) {
            spdlog::error("Failed to create a GLFW window.");
            return;
        }

        GLFWmonitor* monitor = glfwGetPrimaryMonitor();
        const GLFWvidmode* mode = glfwGetVideoMode(monitor);
        glfwSetWindowPos(m_window, mode->width / 2 - m_width / 2, mode->height / 2 - m_height / 2);

        glfwMakeContextCurrent(m_window);

        glfwSetWindowUserPointer(m_window, this);
        glfwSetFramebufferSizeCallback(m_window, framebufferResizeCallback);
    }

    void Window::initializeGlad() {
        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
            spdlog::error("Failed to initialize GLAD.");
            return;
        }
    }

    void Window::enableGLFeatures() {
        glViewport(0, 0, m_width, m_height);
        glEnable(GL_DEPTH_TEST);

        glEnable(GL_CULL_FACE);
        glCullFace(GL_BACK);
    }

    void Window::framebufferResizeCallback(GLFWwindow* window, int width, int height) {
        Window* p_window = reinterpret_cast<Window*>(glfwGetWindowUserPointer(window));
        p_window->m_width = (width > 0) ? width : 1;
        p_window->m_height = (height > 0) ? height : 1;

        glViewport(0, 0, p_window->m_width, p_window->m_height);
    }
}