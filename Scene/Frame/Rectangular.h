//
// Created by Daniel Roca on 29.12.17.
//

#ifndef RAYTRACER_RECTANGULAR_H
#define RAYTRACER_RECTANGULAR_H


#include "../Frame.h"
#include "../../Math/Vec3.h"

class Rectangular : public Frame {
private:
    Vec3 origin;
    Vec3 corner; //up-right
    Vec3 horizontal;
    Vec3 vertical;
public:
    Rectangular(const Vec3 &origin, const Vec3 &corner, const Vec3 &horizontal, const Vec3 &vertical);

    virtual int draw(const char *filename, Scene *scene, int w, int h, int aliasing_n, double aliasing_factor = 0.2);
};


#endif //RAYTRACER_RECTANGULAR_H
