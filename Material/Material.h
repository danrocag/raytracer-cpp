//
// Created by Daniel Roca on 14.04.17.
//

#ifndef RAYTRACER_MATERIAL_H
#define RAYTRACER_MATERIAL_H


#include "../Math/Vec3.h"
#include "../Math/Ray.h"
#include "../Math/Color.h"
#include <random>
#include <functional>

typedef std::default_random_engine random_engine;
typedef std::function<Color(Ray,random_engine&)> Tracer;

class Material {
public:
    virtual Color step(Ray ray, Ray normal, random_engine &engine, Tracer tracer) = 0;
};


#endif //RAYTRACER_MATERIAL_H
