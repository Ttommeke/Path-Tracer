#ifndef CAMERA_H
#define CAMERA_H

#include "../lib/rand48/erand48.h"
#include "vector.h"
#include "ray.h"

class Camera {

private:
    double m_width_recp;
    double m_height_recp;
    double m_ratio;
    double m_x_spacing;
    double m_x_spacing_half;
    double m_y_spacing;
    double m_y_spacing_half;
protected:
    Vec m_position;
    Vec m_direction;
    Vec m_x_direction;
    Vec m_y_direction;
    int m_width;
    int m_height;

public:
    Camera(Vec position, Vec target, int width, int height);
    int get_width();
    int get_height();
    Ray get_ray(int x, int y, bool jitter, unsigned short *Xi);

};

#endif //CAMERA_H