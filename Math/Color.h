//
// Created by Daniel Roca on 19.04.17.
//

#ifndef RAYTRACER_COLOR_H
#define RAYTRACER_COLOR_H


class Color {
private:
    double r;
    double g;
    double b;
public:
    void write(unsigned char* data);

    Color operator*(double filter);
    Color operator*(Color color);
    Color unnormalized_add(Color color);
    Color divide(double d);



    Color(double r, double g, double b);

};


#endif //RAYTRACER_COLOR_H
