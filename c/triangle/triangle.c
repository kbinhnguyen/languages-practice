#include "triangle.h"

char is_triangle(triangle_t t) {
    return t.a > 0 && t.b > 0 && t.c > 0 && (t.a + t.b) >= t.c && (t.a + t.c) >= t.b && (t.b + t.c) >= t.a;
}

char is_equilateral(triangle_t t) {
    return is_triangle(t) && (t.a == t.b && t.a == t.c);
}

char is_isosceles(triangle_t t) {
    return (is_equilateral(t) || (is_triangle(t) && (t.a == t.b || t.b == t.c || t.a == t.c)));
}

char is_scalene(triangle_t t) {
    return is_triangle(t) && t.a != t.b && t.b != t.c && t.a != t.c;
}