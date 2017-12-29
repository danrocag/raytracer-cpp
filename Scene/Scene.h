//
// Created by Daniel Roca on 14.04.17.
//


#ifndef RAYTRACER_SCENE_H
#define RAYTRACER_SCENE_H

#include <vector>
#include "Model.h"
#include "../Math/Color.h"

class Scene {
private:
    std::vector<Model*> models;
public:
    Scene();

    void add(Model* model);
    Color trace(Ray ray, random_engine &engine);
};


#endif //RAYTRACER_SCENE_H
