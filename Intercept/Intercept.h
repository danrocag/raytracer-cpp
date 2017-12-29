//
// Created by Daniel Roca on 14.04.17.
//

#ifndef RAYTRACER_INTERCEPT_H
#define RAYTRACER_INTERCEPT_H


#include "../Math/Ray.h"

class Intercept {
public:
    virtual double intercept(Ray ray) = 0;
    virtual Ray normal(Ray ray, double lambda) = 0;
};


#endif //RAYTRACER_INTERCEPT_H
