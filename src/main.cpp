#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

int main()
{
    glfwInit();
    GLFWwindow *window = glfwCreateWindow(800, 600, "Particlezzz", nullptr, nullptr);
    glfwMakeContextCurrent(window);
    glViewport(0, 0, 800, 600);

    while (!glfwWindowShouldClose(window))
    {
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
