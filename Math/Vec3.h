//
// Created by Daniel Roca on 14.04.17.
//

#ifndef RAYTRACER_VEC3_H
#define RAYTRACER_VEC3_H

#include <random>

typedef std::default_random_engine random_engine;

#include <ostream>

class Vec3 {
protected:
    double x,y,z;
public:
    Vec3(double x, double y, double z);

    Vec3 operator+(Vec3 b);
    Vec3 operator-(Vec3 b);
    double operator*(Vec3 b); // Dot product
    Vec3 operator%(Vec3 b); // Vector product
    Vec3 operator*(double x); // Scalar product
    Vec3 operator/(double x); //
    Vec3& operator=(Vec3 &v);
    Vec3& operator=(Vec3 v);

    double norm();
    double norm_inf();
    double norm_1();

    Vec3 normalized();

    static Vec3 random_uniform(random_engine& engine, double scale);

    friend std::ostream &operator<<(std::ostream &os, const Vec3 &vec3);
};


#endif //RAYTRACER_VEC3_H
