class Particle
{
    double y_speed;
    double x_speed;
    double x_pos;
    double y_pos;
    int size;

public:
    Particle(double yspeed, double xspeed, int size, double x_pos, double y_pos) : y_speed(yspeed), x_speed(xspeed), size(size), x_pos(x_pos), y_pos(y_pos) {}

    void accelerate(double y_rate, double x_rate);
    void set_x_pos(double x);
    void set_y_pos(double y);
    double get_x_pos();
    double get_y_pos();
    double get_x_speed();
    double get_y_speed();
};