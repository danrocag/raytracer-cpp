//
// Created by Daniel Roca on 14.04.17.
//

#ifndef RAYTRACER_PLANE_H
#define RAYTRACER_PLANE_H


#include "../Math/Ray.h"
#include "Intercept.h"

class Plane : public Intercept {
private:
    Ray def;
public:
    double intercept(Ray ray) override;

    Plane(const Ray &def);

    Ray normal(Ray ray, double lambda) override;
};


#endif //RAYTRACER_PLANE_H
