//
// Created by Daniel Roca on 07.01.19.
//

#include "Mix.h"

Mix::Mix(double prob, Material *m1, Material *m2) : prob(prob), m1(m1), m2(m2) {}

Color Mix::step(Ray ray, Ray normal, random_engine &engine, Tracer tracer) {
    std::bernoulli_distribution choose(prob);
    return (choose(engine) ? m1 : m2)->step(ray, normal, engine, tracer);
}
