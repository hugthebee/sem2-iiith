#ifndef COMPLEX_H
#define COMPLEX_H

#include <stdio.h>
#include <stdlib.h>

typedef struct comp{
    float* a; //pointers to array
    int n;
}complex;

complex add(complex a, complex b);
complex sub(complex a, complex b);
float mod(complex a);
float dot(complex a, complex b);
float COS(complex a, complex b);

#endif
