#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <cmath>
#include "Simulation.hpp"

int WINDOW_X = 300;
int WINDOW_Y = 200;

Simulation simulation = Simulation(60, 10, WINDOW_X, WINDOW_Y);

void mouse_button_callback(GLFWwindow *window, int button, int action, int mods)
{
    if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS)
    {
        double xpos, ypos;
        glfwGetCursorPos(window, &xpos, &ypos);
        simulation.on_click(xpos, ypos);
    }
}

void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_SPACE && action == GLFW_PRESS)
    {
        simulation.delete_all_particles();
    }
    else if (key == GLFW_KEY_R && action == GLFW_PRESS)
    {
        simulation.add_thousand_small_particles();
    }
}

void window_pos_callback(GLFWwindow *window, int xpos, int ypos)
{
    static double last_x = xpos;
    static double last_y = ypos;

    double dx = (xpos - last_x) * 0.2;
    double dy = (ypos - last_y) * 0.1;

    for (auto &particle : simulation.particles)
    {
        particle.set_x_speed(particle.get_x_speed() + dx);
        particle.set_y_speed(particle.get_y_speed() + dy);
    }

    last_x = xpos;
    last_y = ypos;
}

int main()
{
    glfwInit();
    GLFWwindow *window = glfwCreateWindow(WINDOW_X, WINDOW_Y, "Balzzz", nullptr, nullptr);
    glfwSetMouseButtonCallback(window, mouse_button_callback);
    glfwSetKeyCallback(window, key_callback);
    glfwSetWindowPosCallback(window, window_pos_callback);
    glfwMakeContextCurrent(window);
    glViewport(0, 0, WINDOW_X, WINDOW_Y);

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

                float gl_x = (x / (float)WINDOW_X) * 2.0f - 1.0f;
                float gl_y = (y / (float)WINDOW_Y) * 2.0f - 1.0f;

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
