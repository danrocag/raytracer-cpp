//
// Created by Daniel Roca on 15.04.17.
//

#include "Frame.h"

#include "../stb_image_write.h"
#include "../Math/Color.h"


int Frame::draw(const char *filename, int w, int h, int aliasing) {
    unsigned char* data = (unsigned char *) std::malloc(w * h * sizeof(unsigned char) * 3);
    std::random_device rd;
    random_engine engine(rd());

    Vec3 di = horizontal / (w-1);
    Vec3 dj = vertical / (h-1);
    std::uniform_real_distribution<double> dist(-0.5,0.5);
    Color current_color(0,0,0);

    for (int i = 0; i < w; ++i) {
        for (int j = 0; j < h; ++j) {
            current_color = Color(0,0,0);
            for (int k = 0; k < aliasing; ++k) {
                current_color = scene->trace({
                                                            origin,
                                                            corner +
                                                                    (di * (i + dist(engine))) +
                                                                    (dj * (j + dist(engine))) -
                                                                    origin
                                                    },
                                                    engine).unnormalized_add(current_color);
            }
            current_color = current_color.divide(aliasing);
            current_color.write(&data[(j*w + i)*3]);
        }
    }
    int result = stbi_write_png(filename,w,h,3,data,0);
    free(data);
    return result;

}


Frame::Frame(const Vec3 &origin, const Vec3 &corner, const Vec3 &horizontal, const Vec3 &vertical, Scene *scene)
        : origin(origin), corner(corner), horizontal(horizontal), vertical(vertical), scene(scene) {}
