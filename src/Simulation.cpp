#include "Simulation.hpp"

void Simulation::simulate()
{
    for (auto &particle : this->particles)
    {
        particle.set_x_pos(particle.get_x_pos() + particle.get_x_speed());
        particle.set_y_pos(particle.get_y_pos() + particle.get_y_speed());
        particle.accelerate(this->count_gravity_acceleration_rate(), 0);
    }
}

double Simulation::count_gravity_acceleration_rate()
{
    return this->gravity_rate / this->fps;
}