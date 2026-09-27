#include <cassert>
#include <cmath>

#include "../include/mat4.h"
#include "../include/vec3.h"
#include "../include/vec4.h"

namespace {
bool approx(double a, double b, double eps = 1e-9) {
    return std::abs(a - b) < eps;
}
}

int main() {
    vec3 a(1.0, 2.0, 3.0);
    vec3 b(4.0, -1.0, 2.0);

    vec3 sum = a + b;
    assert(approx(sum.x(), 5.0));
    assert(approx(sum.y(), 1.0));
    assert(approx(sum.z(), 5.0));

    assert(approx(dot(a, b), 8.0));

    vec3 c = cross(vec3(1, 0, 0), vec3(0, 1, 0));
    assert(approx(c.x(), 0.0));
    assert(approx(c.y(), 0.0));
    assert(approx(c.z(), 1.0));

    mat4 translation = mat4::translate(vec3(3, 4, 5));
    vec4 translated = translation * vec4(vec3(1, 2, 3), 1.0);
    assert(approx(translated.x(), 4.0));
    assert(approx(translated.y(), 6.0));
    assert(approx(translated.z(), 8.0));
    assert(approx(translated.w(), 1.0));

    vec4 direction = translation * vec4(vec3(1, 2, 3), 0.0);
    assert(approx(direction.x(), 1.0));
    assert(approx(direction.y(), 2.0));
    assert(approx(direction.z(), 3.0));
    assert(approx(direction.w(), 0.0));

    mat4 scale = mat4::scale(vec3(2, 3, 4));
    vec4 scaled = scale * vec4(vec3(1, 2, 3), 1.0);
    assert(approx(scaled.x(), 2.0));
    assert(approx(scaled.y(), 6.0));
    assert(approx(scaled.z(), 12.0));

    return 0;
}
