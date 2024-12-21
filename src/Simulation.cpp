#include <algorithm>
#include "Simulation.hpp"
#include "lib.hpp"

void Simulation::simulate()
{
    for (auto &particle : this->particles)
    {
        particle.set_x_pos(particle.get_x_pos() + particle.get_x_speed());
        particle.set_y_pos(particle.get_y_pos() + particle.get_y_speed());

        if (particle.get_y_pos() > this->y_window)
        {
            particle.set_y_speed(-particle.get_y_speed());
        }
        if (particle.get_x_pos() > this->x_window)
        {
            particle.set_x_speed(-particle.get_x_speed());
        }

        particle.accelerate(this->count_gravity_acceleration_rate_per_second(), 0);
    }
}

double Simulation::count_gravity_acceleration_rate_per_second()
{
    return this->gravity_rate / this->fps;
}

void Simulation::on_click(double x_mouse, double y_mouse)
{
    for (size_t i = 0; i < particles.size(); i++)
    {
        Particle particle = particles[i];
        if (distance(x_mouse, y_mouse, particle.get_x_pos(), particle.get_y_pos()) < particle.get_size())
        {
            particles.erase(particles.begin() + i);
            return;
        }
    }

    particles.push_back(Particle(0, 0, 10, x_mouse, y_mouse));
}