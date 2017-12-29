//
// Created by Daniel Roca on 19.04.17.
//

#include "Glass.h"

Color Glass::step(Ray ray, Ray normal, random_engine &engine, Tracer tracer) {
    auto prod = normal.dir*ray.dir;
    Vec3 result_ray(0,0,0);
    double lambda;
    if (prod > 0) {
        lambda = coeff;
    } else { // from the inside
        lambda = 1/coeff;
    }
    auto cos = -prod/(normal.dir.norm()*ray.dir.norm());
    auto sin = sqrt(1 - pow(cos,2));
    auto sin2 = lambda*sin;
    if (sin2 > 1) {
        result_ray = ray.dir - normal.dir*cos*2;
    } else {
        auto cos2 = sqrt(1 - pow(sin2,2));
        auto r = normal.dir.norm();
        auto plane = (ray.dir + normal.dir*prod);
        plane = plane.normalized()*r;
        auto alpha = r*cos2;
        auto beta = r*sin2;
        result_ray = normal.dir*alpha + plane*beta;
    }
    Ray ray2(normal.origin,result_ray);
    return tracer(ray2,engine);
}

Glass::Glass(double coeff) : coeff(coeff) {}
