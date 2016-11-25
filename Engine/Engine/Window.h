#pragma once

class Window {
private:
    GLFWwindow* window;
public:
    Window(int width, int height, string title);

    void render();

    bool isCloseRequested() {
        return glfwWindowShouldClose(window) == 1;
    }
    void getSize(int & w, int & h) {
        glfwGetWindowSize(window, &w, &h);
    }

    void dispose();

    GLFWwindow* getGLFWWindow();

    void setTitle(string title);
};