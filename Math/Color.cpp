//
// Created by Daniel Roca on 19.04.17.
//

#include <cmath>
#include "Color.h"
#define GAMMA 0.5

Color::Color(double r, double g, double b) : r(r), g(g), b(b) {}

void Color::write(unsigned char *data) {
    data[0] = pow(r,GAMMA)*255;
    data[1] = pow(g,GAMMA)*255;
    data[2] = pow(b,GAMMA)*255;
}

Color Color::operator*(double filter) {
    return Color(filter*r, filter*g, filter*b);
}

Color Color::operator*(Color color) {
    return Color(color.r*r, color.g*g, color.b*b);
}

Color Color::unnormalized_add(Color color) {
    return Color(color.r+r, color.g+g, color.b+b);
}

Color Color::divide(double d) {
    return Color(r/d, g/d, b/d);
}
