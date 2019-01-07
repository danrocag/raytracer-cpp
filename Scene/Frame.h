//
// Created by Daniel Roca on 15.04.17.
//

#ifndef RAYTRACER_FRAME_H
#define RAYTRACER_FRAME_H

#include "Scene.h"


class Frame {
public:
    virtual int draw(const char *filename, Scene* scene, int w, int h, int aliasing_n, double aliasing_factor)= 0;


};


#endif //RAYTRACER_FRAME_H
