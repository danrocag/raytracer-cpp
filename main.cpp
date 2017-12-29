#include <iostream>
#include <math.h>

#include "Math/Vec3.h"

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"
#include "Intercept/Plane.h"
#include "Material/Light.h"
#include "Scene/Scene.h"
#include "Scene/Frame.h"
#include "Intercept/Sphere.h"
#include "Material/Matte.h"
#include "Material/GradientLight.h"
#include "Material/Mirror.h"
#include "Material/Glass.h"

int main() {

    Plane plane1 = Plane({Vec3(10,0,0),Vec3(1,0,0)});
    Plane plane2 = Plane({Vec3(-1,0,0), Vec3(1,0,0)});
    Sphere sphere1(Vec3(0,0.5,0.2),0.2);
    Sphere sphere2(Vec3(0.1,0,2),0.8);
    Sphere sphere3(Vec3(0,-0.5,0.2),0.2);
    GradientLight sky(Color(0.5,0.7,1),Color(1,1,1),0.1);
    Matte matte1(Color(0.5,0.5,0.5));
    Matte matte2(Color(0.5,1,1));
    Mirror mirror;
    Glass glass(1.3);



    Model model1 = Model(&plane1, &sky);
    Model model2 = Model(&plane2, &matte1);
    Model model3 = Model(&sphere1,&matte2);
    Model model4 = Model(&sphere2,&glass);
    Model model5 = Model(&sphere3,&matte2);

    Scene scene;
    scene.add(&model1);
    scene.add(&model2);
    scene.add(&model3);
    scene.add(&model4);
    scene.add(&model5);

    Frame frame = Frame(Vec3(0,0,-0.6),Vec3(0.2,0.2,-0.4),Vec3(0,-0.4,0),Vec3(-0.4,0,0),&scene);
    frame.draw("test.png", 400, 400, 40);

    return 0;
}