//
// Created by Daniel Roca on 15.04.17.
//

#ifndef RAYTRACER_MATTE_H
#define RAYTRACER_MATTE_H


#include "Material.h"

class Matte : public Material {
private:
    Color color;
public:
    Matte(Color color);

    virtual Color step(Ray ray, Ray normal, random_engine &engine, Tracer tracer);
};


#endif //RAYTRACER_MATTE_H
