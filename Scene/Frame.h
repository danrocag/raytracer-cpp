//
// Created by Daniel Roca on 15.04.17.
//

#ifndef RAYTRACER_FRAME_H
#define RAYTRACER_FRAME_H


#include "../Math/Vec3.h"
#include "Scene.h"


class Frame {
private:
    Vec3 origin;
    Vec3 corner; //up-right
    Vec3 horizontal;
    Vec3 vertical;
    Scene* scene;
public:
    Frame(const Vec3 &origin, const Vec3 &corner, const Vec3 &horizontal, const Vec3 &vertical, Scene *scene);

    int draw(const char *filename, int w, int h, int aliasing);


};


#endif //RAYTRACER_FRAME_H
