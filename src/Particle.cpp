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

double Particle::get_x_speed() const
{
    return this->x_speed;
}

double Particle::get_y_speed() const
{
    return this->y_speed;
}

double Particle::get_x_pos() const
{
    return this->x_pos;
}

double Particle::get_y_pos() const
{
    return this->y_pos;
}

double Particle::get_size() const
{
    return this->size;
}

void Particle::set_x_speed(double x)
{
    this->x_speed = x;
}

void Particle::set_y_speed(double y)
{
    this->y_speed = y;
}