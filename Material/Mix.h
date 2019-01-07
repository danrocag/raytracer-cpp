//
// Created by Daniel Roca on 07.01.19.
//

#ifndef RAYTRACER_MIX_H
#define RAYTRACER_MIX_H


#include "Material.h"

class Mix : public Material{
private:
    double prob;
    Material *m1;
    Material *m2;
public:
    Mix(double prob, Material *m1, Material *m2);

    virtual Color step(Ray ray, Ray normal, random_engine &engine, Tracer tracer);
};


#endif //RAYTRACER_MIX_H
