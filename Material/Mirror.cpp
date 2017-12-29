//
// Created by Daniel Roca on 17.04.17.
//

#include "Mirror.h"

Mirror::Mirror() {}

Color Mirror::step(Ray ray, Ray normal, random_engine &engine, Tracer tracer) {
    Ray reflected = Ray(normal.origin, ray.dir - normal.dir*(normal.dir*ray.dir/(normal.dir*normal.dir))*2);
    return tracer(reflected,engine);
}
