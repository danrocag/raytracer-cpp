//
// Created by Daniel Roca on 14.04.17.
//

#ifndef RAYTRACER_MODEL_H
#define RAYTRACER_MODEL_H


#include "../Intercept/Intercept.h"
#include "../Material/Material.h"

struct Model {
public:
    Intercept *intercept;
    Material *material;

    Model(Intercept *intercept, Material *material);
};


#endif //RAYTRACER_MODEL_H
