//
// Created by Daniel Roca on 07.01.19.
//

#include "Absorb.h"
#include "../Math/Color.h"
#include "../Math/Ray.h"
#include "Material.h"


Color Absorb::step(Ray ray, Ray normal, random_engine &engine, Tracer tracer) {
    return Color(0, 0, 0);
}

Absorb::Absorb() {

}
