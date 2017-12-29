//
// Created by Daniel Roca on 15.04.17.
//

#include "Matte.h"

Color Matte::step(Ray ray, Ray normal, random_engine &engine, Tracer tracer) {
    Vec3 new_dir(0,0,0);
    do {
        new_dir = Vec3::random_uniform(engine,1);
    } while (new_dir.norm() > 1);

    return tracer({normal.origin, (normal.dir/normal.dir.norm() + new_dir)},engine)*color;
}

Matte::Matte(Color color) : color(color) {}
