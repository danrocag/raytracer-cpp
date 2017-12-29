//
// Created by Daniel Roca on 16.04.17.
//

#include "Sphere.h"

#include <cmath>

double Sphere::intercept(Ray ray) {
    double b = (center-ray.origin)*ray.dir*2;
    double a = ray.dir*ray.dir;
    double c = (center-ray.origin)*(center-ray.origin) - radius*radius;

    double discriminant = b*b - 4*a*c;

    double limit = ray.dir.norm_inf()*1e-10;

    if (fabs(discriminant) < limit) {
        return -b / (2*a);
    } else if (0 < discriminant) {
        double l1 = (b + sqrt(discriminant))/(2*a);
        double l2 = (b - sqrt(discriminant))/(2*a);
        if (l1 > 0) {
            if (l2 > 0) {
                if (l1 > l2) {
                    return l2;
                } else {
                    return l1;
                }
            } else {
                return l1;
            }
        } else {
            return l2;
        }
    } else {
        return -1;
    }
}

Ray Sphere::normal(Ray ray, double lambda) {
    return {ray.origin + ray.dir*lambda, ray.origin + ray.dir*lambda - center};
}

Sphere::Sphere(const Vec3 &center, double radius) : center(center), radius(radius) {}
