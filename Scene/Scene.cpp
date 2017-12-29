//
// Created by Daniel Roca on 14.04.17.
//

#include "Scene.h"
#include "../Math/Color.h"
#include <limits>

Scene::Scene() {}

void Scene::add(Model* model) {
    models.push_back(model);
}

Color Scene::trace(Ray ray, random_engine &engine) {
    Model *current_model = NULL;
    double current_lambda = std::numeric_limits<double>::max();
    double lambda;

    double min_distance = ray.dir.norm()*1e-2;

    for (auto it = models.begin(); it != models.end(); ++it) {
        lambda = (*it)->intercept->intercept(ray);
        if (min_distance < lambda && lambda < current_lambda) {
            current_lambda = lambda;
            current_model = (*it);
        }
    }
    if (!current_model) {
        return Color(0,0,0);
    }
    return current_model->material->step(
            ray,
            current_model->intercept->normal(ray, current_lambda),
            engine,
            [&](Ray r, random_engine e){ return trace(r,e);});
}
