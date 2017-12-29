//
// Created by Daniel Roca on 14.04.17.
//

#include "Plane.h"

double Plane::intercept(Ray ray) {
    double normal_distance = ((def.origin - ray.origin)*def.dir);
    double travel_distance = (ray.dir*def.dir);
    return normal_distance / travel_distance;
}

Plane::Plane(const Ray &def) : def(def) {}

Ray Plane::normal(Ray ray, double lambda) {
    return Ray(ray.origin + ray.dir*lambda,def.dir*(ray.dir*def.dir)*(-1));
}
