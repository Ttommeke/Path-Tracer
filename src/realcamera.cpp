#include "ray.h"
#include "realcamera.h"

RealCamera::RealCamera(Vec position, 
        Vec target, 
        int width, 
        int height, 
        double widthSensor, 
        double heightSensor,
        double focalLength,
        double focusDistance,
        double fStop) : Camera(position, target, width, height) {
    this->m_sensor_width = widthSensor;
    this->m_sensor_height = heightSensor;
    this->m_focal_length = focalLength;
    this->m_focus_distance = focusDistance;
    this->m_f_stop = fStop;

    this->m_temp_x = m_x_direction*m_sensor_width;
    this->m_temp_y = m_y_direction*m_sensor_height;

    this->m_temp_start = m_position;

    this->m_temp_start = this->m_temp_start - m_direction*m_focal_length;
    this->m_temp_start = this->m_temp_start + m_temp_x/2;
    this->m_temp_start = this->m_temp_start - m_temp_y/2;
}

// Returns ray from RealCamera origin through pixel at x,y
Ray RealCamera::get_ray(int x, int y, bool jitter, unsigned short *Xi) {
    Vec start = m_temp_start;

    start = start - m_temp_x*x/m_width;
    start = start + m_temp_y*y/m_height;

    return Ray(start, (m_position-start).norm());
}