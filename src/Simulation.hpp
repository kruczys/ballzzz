#include "Particle.hpp"
#include <vector>

class Simulation
{
    double fps;
    double gravity_rate;
    std::vector<Particle> particles;

public:
    Simulation(double fps, double gravity_rate) : fps(fps), gravity_rate(gravity_rate), particles() {}
    std::vector<Particle> get_particles();

    void simulate();
    void add_particle();
    void delete_particle(Particle &particle);
    double count_gravity_acceleration_rate();
};