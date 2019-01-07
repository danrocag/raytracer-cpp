//
// Created by Daniel Roca on 07.01.19.
//

#include "TestGenerator1.h"
#include "../Material/Matte.h"
#include "../Intercept/Sphere.h"
#include "../Intercept/Plane.h"
#include "../Material/GradientLight.h"
#include "../Material/Mirror.h"

void TestGenerator1::generate(Scene *scene) {

    Plane* plane1 = new Plane({Vec3(100,0,0),Vec3(10,0,0)});
    Plane* plane2 = new Plane({Vec3(-10,0,0), Vec3(10,0,0)});
    GradientLight* sky = new GradientLight(Color(0.5,0.7,0.95),Color(0.9,0.9,0.9),0.1);
    // Matte* ground = new Matte(Color(0.6,0.8,0.2));
    Mirror* mirror = new Mirror();
    Model* model1 = new Model(plane1, sky);
    Model* model2 = new Model(plane2, mirror);
    scene->add(model1);
    scene->add(model2);

    std::random_device rd;
    random_engine engine(rd());

    std::uniform_real_distribution<> radius(0.5,1.5);
    std::uniform_int_distribution<> pos(-8,8);
    std::uniform_real_distribution<> shade(0,1);

    for (int i = 0; i < 100; ++i) {
        Material* matte = new Matte(Color(shade(engine), shade(engine), shade(engine)));
        double r = radius(engine);
        Intercept* sphere = new Sphere(Vec3(r-10, (pos(engine))*2, (pos(engine)+2)*2),r);
        Model* model = new Model(sphere, matte);
        scene->add(model);
    }
}
