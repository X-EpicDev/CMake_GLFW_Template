#include "glad/glad.h"
#include "GLFW/glfw3.h"

int main() {
    // Initialize GLFW
    if (!glfwInit()) {
        return -1; // Initialization failed
    }

    // Create a windowed mode window and its OpenGL context
    GLFWwindow* window = glfwCreateWindow(800, 600, "Template Window", nullptr, nullptr);
    if (!window) {
        glfwTerminate();
        return -1; // Window creation failed
    }

    // Make the OpenGL context current
    glfwMakeContextCurrent(window);
    // Initialize GLAD to load OpenGL functions
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        return -1; // GLAD initialization failed
    }

    // Loop until the user closes the window
    while (!glfwWindowShouldClose(window)) {
        // Render here (you can add OpenGL rendering code later)

        // Clear the screen with a color (optional)
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // black
        glClear(GL_COLOR_BUFFER_BIT);

        // Swap buffers
        glfwSwapBuffers(window);

        // Poll for and process events
        glfwPollEvents();
    }

    // Clean up and terminate GLFW
    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}
