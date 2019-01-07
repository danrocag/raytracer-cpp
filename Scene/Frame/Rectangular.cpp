//
// Created by Daniel Roca on 29.12.17.
//

#include "Rectangular.h"

#include "../../stb_image_write.h"


Rectangular::Rectangular(const Vec3 &origin, const Vec3 &corner, const Vec3 &horizontal, const Vec3 &vertical) : origin(
        origin), corner(corner), horizontal(horizontal), vertical(vertical) {}

int Rectangular::draw(const char *filename, Scene *scene, int w, int h, int aliasing_n, double aliasing_factor) {
    unsigned char* data = (unsigned char *) std::malloc(w * h * sizeof(unsigned char) * 3);
    std::random_device rd;
    random_engine engine(rd());

    Vec3 di = horizontal / (w-1);
    Vec3 dj = vertical / (h-1);
    std::uniform_real_distribution<double> dist(-aliasing_factor,aliasing_factor);
    Color current_color(0,0,0);

    for (int i = 0; i < w; ++i) {
        for (int j = 0; j < h; ++j) {
            current_color = Color(0,0,0);
            for (int k = 0; k < aliasing_n; ++k) {
                current_color = tracePixel(scene, w, h, (i + dist(engine)), (j + dist(engine)), engine).unnormalized_add(current_color);
            }
            current_color = current_color.divide(aliasing_n);
            current_color.write(&data[(j*w + i)*3]);
        }
    }
    int result = stbi_write_png(filename,w,h,3,data,0);
    free(data);
    return result;
}

Color Rectangular::tracePixel(Scene *scene, int w, int h, double x, double y, random_engine &engine) {
    Vec3 di = horizontal / (w-1);
    Vec3 dj = vertical / (h-1);

    return scene->trace({
                                origin,
                                corner +
                                (di * x) +
                                (dj * y) -
                                origin
                        },
                        engine);
}



