class Particle
{
    double y_speed;
    double x_speed;
    double size;
    double x_pos;
    double y_pos;

public:
    Particle(double yspeed, double xspeed, int size, double x_pos, double y_pos) : y_speed(yspeed), x_speed(xspeed), size(size), x_pos(x_pos), y_pos(y_pos) {}

    bool operator==(const Particle &other) const;
    bool operator!=(const Particle &other) const;

    void accelerate(double y_rate, double x_rate);
    void set_x_pos(double x);
    void set_y_pos(double y);
    void set_x_speed(double x);
    void set_y_speed(double y);
    double get_x_pos() const;
    double get_y_pos() const;
    double get_x_speed() const;
    double get_y_speed() const;
    double get_size() const;
};