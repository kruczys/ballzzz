#include "Particle.hpp"

void Particle::accelerate(double x_rate, double y_rate)
{
    this->x_speed += x_rate;
    this->y_speed += y_rate;
}

void Particle::set_x_pos(double x_pos)
{
    this->x_pos = x_pos;
}

void Particle::set_y_pos(double y_pos)
{
    this->y_pos = y_pos;
}

double Particle::get_x_speed()
{
    return this->x_speed;
}

double Particle::get_y_speed()
{
    return this->y_speed;
}

double Particle::get_x_pos()
{
    return this->x_pos;
}

double Particle::get_y_pos()
{
    return this->y_pos;
}