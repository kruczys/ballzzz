#include "Particle.hpp"
#include <vector>

class Simulation
{
    double fps;
    double gravity_rate;
    int x_window;
    int y_window;
    std::vector<Particle> particles;

public:
    Simulation(double fps, double gravity_rate) : fps(fps), gravity_rate(gravity_rate), particles() {}

    void simulate();
    double count_gravity_acceleration_rate_per_second();
    void on_click(double x_mouse, double y_mouse);
};