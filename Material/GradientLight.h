//
// Created by Daniel Roca on 17.04.17.
//

#ifndef RAYTRACER_GRADIENTLIGHT_H
#define RAYTRACER_GRADIENTLIGHT_H


#include "Material.h"

class GradientLight : public Material {
private:
    Color light;
    Color dark;
    double order = 1;
public:
    virtual Color step(Ray ray, Ray normal, random_engine &engine, Tracer tracer);

    GradientLight(Color light, Color dark);

    GradientLight(Color light, Color dark, double order);
};


#endif //RAYTRACER_GRADIENTLIGHT_H
