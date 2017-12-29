//
// Created by Daniel Roca on 19.04.17.
//

#ifndef RAYTRACER_GLASS_H
#define RAYTRACER_GLASS_H


#include "Material.h"

class Glass : public Material{
private:
    double coeff;

public:
    virtual Color step(Ray ray, Ray normal, random_engine &engine, Tracer tracer);

    Glass(double coeff);
};


#endif //RAYTRACER_GLASS_H
