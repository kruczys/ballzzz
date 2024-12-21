#include "Particle.hpp"
#include <vector>

class Simulation
{
    double fps;
    double gravity_rate;
    int x_window;
    int y_window;

public:
    std::vector<Particle> particles;
    Simulation(double fps, double gravity_rate, int x_window, int y_window) : fps(fps), gravity_rate(gravity_rate), x_window(x_window), y_window(y_window), particles() {}

    void simulate();
    double count_gravity_acceleration_rate_per_second() const;
    void on_click(double x_mouse, double y_mouse);
};