#include "Window.h"

void glfwErrorCallback(int error, const char* description) {
    brayjl::Logger::error("GLFW Error (" + std::to_string(error) + "): " + description);
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

    std::uint32_t Window::getWidth() const {
        return m_width;
    }

    std::uint32_t Window::getHeight() const {
        return m_height;
    }

    GLFWwindow* Window::getWindow() const {
        return m_window;
    }

    float Window::getDeltaTime() const {
        return m_deltaTime;
    }

    void Window::update() {
        updateFPS();
        updateDeltaTime();

        glfwPollEvents();
        glfwSwapBuffers(m_window);

        glClearColor(0.01f, 0.01f, 0.01f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }

    void Window::createGlfwWindow() {
        if (Utilities::getEnableDebugMessages()) {
            glfwSetErrorCallback(glfwErrorCallback);
        }

        if (!glfwInit()) {
            Logger::error("Failed to initialize GLFW.");
            return;
        }

        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);

        m_window = glfwCreateWindow(m_width, m_height, m_name.c_str(), nullptr, nullptr);
        if (m_window == nullptr) {
            Logger::error("Failed to create a GLFW window.");
            return;
        }

        GLFWmonitor* monitor = glfwGetPrimaryMonitor();
        const GLFWvidmode* mode = glfwGetVideoMode(monitor);
        glfwSetWindowPos(m_window, mode->width / 2 - m_width / 2, mode->height / 2 - m_height / 2);

        glfwMakeContextCurrent(m_window);

        glfwSwapInterval(0);

        glfwSetWindowUserPointer(m_window, this);
        glfwSetFramebufferSizeCallback(m_window, framebufferResizeCallback);
    }

    void Window::initializeGlad() {
        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
            Logger::error("Failed to initialize GLAD.");
            return;
        }
    }

    void Window::enableGLFeatures() {
        glViewport(0, 0, m_width, m_height);
        glEnable(GL_DEPTH_TEST);

        glEnable(GL_CULL_FACE);
        glCullFace(GL_BACK);
    }

    void Window::updateFPS() {
        double currentFrameTime = glfwGetTime();

        m_frameCount++;

        if (currentFrameTime - m_prevFPSUpdateTime >= 1.0) {
            m_fps = m_frameCount / (currentFrameTime - m_prevFPSUpdateTime);
            std::string newName = m_name + " | fps: " + std::to_string(m_fps);
            glfwSetWindowTitle(m_window, newName.c_str());

            m_frameCount = 0;
            m_prevFPSUpdateTime = currentFrameTime;
        }
    }

    void Window::updateDeltaTime() {
        float currentFrameTime = glfwGetTime();
        m_deltaTime = currentFrameTime - m_prevFrameTime;
        m_prevFrameTime = currentFrameTime;
    }

    void Window::framebufferResizeCallback(GLFWwindow* window, int width, int height) {
        Window* p_window = reinterpret_cast<Window*>(glfwGetWindowUserPointer(window));
        p_window->m_width = (width > 0) ? width : 1;
        p_window->m_height = (height > 0) ? height : 1;

        glViewport(0, 0, p_window->m_width, p_window->m_height);
    }
}