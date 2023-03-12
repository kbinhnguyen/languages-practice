#ifndef TRIANGLE_H
#define TRIANGLE_H

typedef struct {
   double a;
   double b;
   double c;
} triangle_t;

char is_triangle(triangle_t t);

char is_equilateral(triangle_t t);

char is_isosceles(triangle_t t);

char is_scalene(triangle_t t);

#endif