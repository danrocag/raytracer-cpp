//
// Created by Daniel Roca on 16.04.17.
//

#ifndef RAYTRACER_SPHERE_H
#define RAYTRACER_SPHERE_H


#include "Intercept.h"

class Sphere : public Intercept {
private:
    Vec3 center;
    double radius;
public:
    virtual double intercept(Ray ray);

    virtual Ray normal(Ray ray, double lambda);

    Sphere(const Vec3 &center, double radius);
};


#endif //RAYTRACER_SPHERE_H
