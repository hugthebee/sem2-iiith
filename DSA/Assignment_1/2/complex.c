#include "complex.h"

#include <math.h>
#include <string.h>

complex add(complex a, complex b)
{
    int size = a.n;
    complex result;
    float *r = malloc(sizeof(float) * size);
    result.a = r;
    result.n = size;

    for(int i=0;i<size;i++)
    {
       r[i] = a.a[i] + b.a[i];
    }

    return result;
}

complex sub(complex a, complex b)
{
    int size = a.n;
    complex result;
    float *r = malloc(sizeof(float) * size);
    result.a = r;
    result.n = size;

    for(int i=0;i<size;i++)
    {
        r[i] = (a.a[i]) - (b.a[i]);
    }

    return result;
}

float mod(complex a)
{
    float result;
    int size = a.n;

    float sum = 0;
    float sq;
    for(int i=0;i<size;i++)
    {
       sq = (a.a[i]) * (a.a[i]);
       sum += sq;
    }

    result = sqrtf(sum);
    return result;
}

float dot(complex a, complex b)
{
    float result=0;
    int size = a.n;
    float product;

    for(int i=0;i<size;i++)
    {
       product = a.a[i] * b.a[i];
       result += product;
    }

    return result;
}

float COS(complex a, complex b)
{
    float result;
    result = dot(a,b);
    result = result/(mod(a) * mod(b));

    return result;
}