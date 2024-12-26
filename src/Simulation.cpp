#include <algorithm>
#include <ctime>
#include <cmath>
#include "Simulation.hpp"
#include "lib.hpp"

void Simulation::simulate()
{
    double gravity_rate_ps = this->count_gravity_acceleration_rate_per_second();
    for (auto &particle : this->particles)
    {
        double x_speed = particle.get_x_speed();
        double y_speed = particle.get_y_speed();
        double x_pos = particle.get_x_pos();
        double y_pos = particle.get_y_pos();
        double size = particle.get_size();

        // Movement
        particle.set_x_pos(x_pos + x_speed);
        particle.set_y_pos(y_pos + y_speed);

        // Air resistance
        particle.set_x_speed(x_speed * 0.999);

        // collision with other particles
        for (auto &other_particle : this->particles)
        {
            double x_pos_other = other_particle.get_x_pos();
            double y_pos_other = other_particle.get_y_pos();
            double x_speed_other = other_particle.get_x_speed();
            double y_speed_other = other_particle.get_y_speed();
            double size_other = other_particle.get_size();

            if (particle != other_particle)
            {
                if (distance(x_pos, y_pos, x_pos_other, y_pos_other) < (size + size_other) / 2)
                {
                    double dx = x_pos_other - x_pos;
                    double dy = y_pos_other - y_pos;

                    double dist = std::sqrt(dx * dx + dy * dy);
                    dx /= dist;
                    dy /= dist;

                    double v1 = x_speed * dx + y_speed_other * dy;
                    double v2 = x_speed_other * dx + y_speed * dy;

                    particle.set_x_speed(x_speed + (v2 - v1) * dx);
                    particle.set_y_speed(y_speed + (v2 - v1) * dy);
                    other_particle.set_x_speed(x_speed_other + (v1 - v2) * dx);
                    other_particle.set_y_speed(y_speed_other + (v1 - v2) * dy);
                }
            }
        }

        // collision with walls
        if (y_pos > this->y_window - size + 2)
        {
            particle.set_y_pos(this->y_window - size + 2);
            particle.set_y_speed(-y_speed * 0.9);
        }
        if (y_pos < size + 2)
        {
            particle.set_y_pos(size + 2);
            particle.set_y_speed(-y_speed * 0.9);
        }
        if (x_pos > this->x_window - size + 2)
        {
            particle.set_x_pos(this->x_window - size + 2);
            particle.set_x_speed(-x_speed * 0.9);
        }
        if (x_pos < size + 2)
        {
            particle.set_x_pos(size + 2);
            particle.set_x_speed(-x_speed * 0.9);
        }

        // gravity pull
        particle.accelerate(0, -gravity_rate_ps);
    }
}

double Simulation::count_gravity_acceleration_rate_per_second() const
{
    return this->gravity_rate / this->fps;
}

void Simulation::on_click(double x_mouse, double y_mouse)
{
    y_mouse = this->y_window - y_mouse;
    for (size_t i = 0; i < particles.size(); i++)
    {
        Particle particle = particles[i];
        if (distance(x_mouse, y_mouse, particle.get_x_pos(), particle.get_y_pos()) < particle.get_size())
        {
            particles.erase(particles.begin() + i);
            return;
        }
    }
    srand(std::time(0));
    double randomized = 3 * ((double)rand() / RAND_MAX) * 2.0 - 1.0;
    particles.push_back(Particle(0, randomized, 10, x_mouse, y_mouse));
}

void Simulation::delete_all_particles()
{
    particles.clear();
}

void Simulation::add_thousand_small_particles()
{
    for (size_t i = 0; i < 100; i++)
    {
        for (size_t j = 0; j < 10; j++)
        {
            particles.push_back(Particle(0, 0, 2, 3 * i, 3 * j));
        }
    }
}