//
// Created by Daniel Roca on 07.01.19.
//

#ifndef RAYTRACER_ABSORB_H
#define RAYTRACER_ABSORB_H

#include "Material.h"

class Absorb: public Material {
public:
    Absorb();

    virtual Color step(Ray ray, Ray normal, random_engine &engine, Tracer tracer);
};

#endif //RAYTRACER_ABSORB_H