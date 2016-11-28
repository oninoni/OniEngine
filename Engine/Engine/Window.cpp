#include "stdafx.h"

#include "Window.h"

Window::Window(int width, int height, string title) {
    this->width = width;
    this->height = height;

    if (!glfwInit()) {
        cout << "GLFW failed. You suck!" << endl;
        return;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);

    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    window = glfwCreateWindow(width, height, title.c_str(), NULL, NULL);
    glfwMakeContextCurrent(window);

    if (glewInit()) {
        cout << "Glew could not be initilalized. You suck!" << endl;
        return;
    }

    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

    glfwSwapInterval(0); // V-Sync off (on is default, but it glitches if you don't call it)
}

void Window::swapBuffers() {
    glfwSwapBuffers(window);
}

void Window::dispose() {
    glfwDestroyWindow(window);
}

GLFWwindow * Window::getGLFWWindow() {
    return window;
}

void Window::setTitle(string title) {
    glfwSetWindowTitle(window, title.c_str());
}

void Window::bindAsRenderTarget() {
    glBindFramebuffer(GL_DRAW_FRAMEBUFFER, 0);
    glViewport(0, 0, width, height);
}
