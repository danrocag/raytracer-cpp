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
#include "Scene/Frame/Rectangular.h"
#include "Material/Mix.h"
#include "Generator/TestGenerator1.h"

int main() {

    Plane plane1 = Plane({Vec3(100,0,0),Vec3(10,0,0)});
    Plane plane2 = Plane({Vec3(-10,0,0), Vec3(10,0,0)});
    Sphere sphere1(Vec3(-7.9,5,6),2);
    Sphere sphere2(Vec3(-5.1,0,13),5);
    Sphere sphere3(Vec3(-8.1,-5,6),2);
    GradientLight sky(Color(0.5,0.7,0.95),Color(0.9,0.9,0.9),0.1);
    Matte ground(Color(0.6,0.8,0.2));
    Matte purplish(Color(0.8,0.2,0.6));
    Matte matte3(Color(0.2,0.6,0.9));

    Mirror mirror;
    Glass glass(1.3);
    Mix semimirror(0.7, &mirror, &purplish);



    Model model1 = Model(&plane1, &sky);
    Model model2 = Model(&plane2, &ground);
    Model model3 = Model(&sphere1,&purplish);
    Model model4 = Model(&sphere2,&semimirror);
    Model model5 = Model(&sphere3,&matte3);

    TestGenerator1 gen;
    Scene scene;
    gen.generate(&scene);
    /**
    scene.add(&model1);
    scene.add(&model2);
    scene.add(&model3);
    scene.add(&model4);
    scene.add(&model5);
     **/


    Rectangular frame = Rectangular(Vec3(2,0,-20),Vec3(4,5,-10),Vec3(0,-10,0),Vec3(-10,0,0));

    frame.draw("test.png", &scene, 1200, 1200, 100);

    return 0;
}