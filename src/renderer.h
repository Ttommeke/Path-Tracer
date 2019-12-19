#ifndef RENDERER_H
#define RENDERER_H

#include "vector.h"
#include "scene.h"
#include "realcamera.h"

class Renderer {

private:
    Scene *m_scene;
    RealCamera *m_camera;
    Vec *m_pixel_buffer;

public:
    Renderer(Scene *scene, RealCamera *camera);
    void render(int samples=4);
    void save_image(const char * file_path);

};

#endif //RENDERER_H