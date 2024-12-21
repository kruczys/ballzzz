#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <cmath>
#include "Simulation.hpp"

Simulation simulation = Simulation(60, 10, 800, 600);

void mouse_button_callback(GLFWwindow *window, int button, int action, int mods)
{
    if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS)
    {
        double xpos, ypos;
        glfwGetCursorPos(window, &xpos, &ypos);
        simulation.on_click(xpos, ypos);
    }
}

int main()
{
    glfwInit();
    GLFWwindow *window = glfwCreateWindow(800, 600, "Particlezzz", nullptr, nullptr);
    glfwSetMouseButtonCallback(window, mouse_button_callback);
    glfwMakeContextCurrent(window);
    glViewport(0, 0, 800, 600);

    while (!glfwWindowShouldClose(window))
    {

        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        for (const auto &particle : simulation.particles)
        {
            glBegin(GL_POLYGON);
            glColor3f(1.0f, 1.0f, 1.0f);

            for (int i = 0; i < 30; i++)
            {
                float angle = 2.0f * 3.1415926f * i / 30;
                float x = particle.get_x_pos() + std::cos(angle) * particle.get_size();
                float y = particle.get_y_pos() + std::sin(angle) * particle.get_size();

                float gl_x = (x / 800.0f) * 2.0f - 1.0f;
                float gl_y = (y / 600.0f) * 2.0f - 1.0f;

                glVertex2f(gl_x, gl_y);
            }
            glEnd();
        }
        glfwSwapBuffers(window);
        glfwPollEvents();
        simulation.simulate();
    }

    glfwTerminate();
    return 0;
}
