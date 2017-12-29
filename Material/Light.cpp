//
// Created by Daniel Roca on 14.04.17.
//

#include "Light.h"

Light::Light(Color light) : light(light) {}

Color Light::step(Ray ray, Ray normal, random_engine &engine, Tracer tracer) {
    return light;
}