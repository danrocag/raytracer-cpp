//
// Created by Daniel Roca on 17.04.17.
//

#include "GradientLight.h"

Color GradientLight::step(Ray ray, Ray normal, random_engine &engine, Tracer tracer) {
    double t = fmin(pow(fabs(ray.dir*normal.dir),order),1);
    return (light*t).unnormalized_add(dark*(1-t));
}

GradientLight::GradientLight(Color light, Color dark) : light(light), dark(dark) {}

GradientLight::GradientLight(Color light, Color dark, double order) : light(light), dark(dark), order(order) {}
