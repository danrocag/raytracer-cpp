//
// Created by Daniel Roca on 14.04.17.
//

#ifndef RAYTRACER_RAY_H
#define RAYTRACER_RAY_H


#include "Vec3.h"

struct Ray {
    Vec3 origin;
    Vec3 dir;

    Ray(const Vec3 &origin, const Vec3 &dir);
};


#endif //RAYTRACER_RAY_H
