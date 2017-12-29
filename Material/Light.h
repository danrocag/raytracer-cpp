//
// Created by Daniel Roca on 14.04.17.
//

#ifndef RAYTRACER_LIGHT_H
#define RAYTRACER_LIGHT_H


#include "Material.h"

class Light: public Material {
private:
    Color light;
public:
    Light(Color light);

    virtual Color step(Ray ray, Ray normal, random_engine &engine, Tracer tracer);
};


#endif //RAYTRACER_LIGHT_H
