#ifndef REALCAMERA_H
#define REALCAMERA_H

#include "../lib/rand48/erand48.h"
#include "vector.h"
#include "ray.h"
#include "camera.h"
#include <stdio.h>
#include <stdlib.h>

class RealCamera : public Camera {

private:
    double m_sensor_width;
    double m_sensor_height;
    double m_focal_length;
    double m_focus_distance;
    double m_f_stop;

    Vec m_temp_x;
    Vec m_temp_y;
    Vec m_temp_start;
public:
    RealCamera(Vec position, Vec target, int width, int height, double widthSensor, double heightSensor, double focalLength, double focusDistance, double fStop);
    Ray get_ray(int x, int y, bool jitter, unsigned short *Xi);

};

#endif //REALCAMERA_H