//
// Created by Daniel Roca on 17.04.17.
//

#ifndef RAYTRACER_MIRROR_H
#define RAYTRACER_MIRROR_H


#include "Material.h"

class Mirror : public Material {
public:
    virtual Color step(Ray ray, Ray normal, random_engine &engine, Tracer tracer);

    Mirror();
};


#endif //RAYTRACER_MIRROR_H
