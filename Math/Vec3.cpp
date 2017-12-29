//
// Created by Daniel Roca on 14.04.17.
//

#include <cmath>
#include "Vec3.h"
#include <random>

Vec3::Vec3(double xVal, double yVal, double zVal){
    x = xVal;
    y = yVal;
    z = zVal;
}

Vec3 Vec3::operator+(Vec3 b) {
    return Vec3(
            x + b.x,
            y + b.y,
            z + b.z
    );
}

Vec3 Vec3::operator-(Vec3 b) {
    return Vec3(
            x - b.x,
            y - b.y,
            z - b.z
    );
}

double Vec3::operator*(Vec3 b) {
    return x*b.x + y*b.y + z*b.z;
}

Vec3 Vec3::operator%(Vec3 b) {
    // Vector product
    Vec3 result = Vec3(0, 0, 0);
    result.x = y*b.z - z*b.y;
    result.y = z*b.x - x*b.z;
    result.z = x*b.y - y*b.x;
    return result;
}

std::ostream &operator<<(std::ostream &os, const Vec3 &vec3) {
    os << "data: " << vec3.x << "; " << vec3.y << "; " << vec3.z;
    return os;
}

Vec3 Vec3::operator*(double k) {
    return Vec3(k*x,k*y,k*z);
}

double Vec3::norm() {
    return sqrt(x*x + y*y + z*z);
}

double Vec3::norm_inf(){
    return std::max(fabs(x),std::max(fabs(y),fabs(z)));
}

double Vec3::norm_1() {
    return fabs(x)+fabs(y)+fabs(z);
}

Vec3 Vec3::random_uniform(random_engine &engine, double scale) {
    std::uniform_real_distribution<double> dist(-scale,scale);
    return Vec3(dist(engine), dist(engine), dist(engine));
}

Vec3 Vec3::operator/(double k) {
    return Vec3(x/k, y/k, z/k);
}

Vec3& Vec3::operator=(Vec3 &v) {
    x = v.x;
    y = v.y;
    z = v.z;
    return *this;
}

Vec3 &Vec3::operator=(Vec3 v) {
    x = v.x;
    y = v.y;
    z = v.z;
    return *this;
}

Vec3 Vec3::normalized() {
    return Vec3(x, y, z)/this->norm();
}


