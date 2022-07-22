#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "complex.h"

int main()
{
    char s[20];
    int num;
    scanf("%s %d",s,&num);

    if(strcmp(s,"ADD") == 0)
    {
        complex a;
        complex b;
        a.n = num;
        b.n = num;

        float af[num];
        float bf[num];
        for(int i=0;i<num;i++)
        {
            scanf("%f",&af[i]);
        }
        for(int i=0;i<num;i++)
        {
            scanf("%f",&bf[i]);
        }
        a.a = af;
        b.a = bf;

        complex result = add(a,b);

        for(int i=0;i<num;i++)
        {
            printf("%f ", result.a[i]);
        }
        printf("\n");
    }

    else if(strcmp(s,"SUB") == 0)
    {
        complex a;
        complex b;
        a.n = num;
        b.n = num;

        float af[num];
        float bf[num];
        for(int i=0;i<num;i++)
        {
            scanf("%f",&af[i]);
        }
        for(int i=0;i<num;i++)
        {
            scanf("%f",&bf[i]);
        }
        a.a = af;
        b.a = bf;

        complex result = sub(a,b);

        for(int i=0;i<num;i++)
        {
            printf("%f ", result.a[i]);
        }
        printf("\n");
    }

    else if(strcmp(s,"MOD") == 0)
    {
        complex a;
        a.n = num;

        float af[num];
        for(int i=0;i<num;i++)
        {
            scanf("%f",&af[i]);
        }
        a.a = af;

        float result = mod(a);
        printf("%f\n", result);
    }

    else if(strcmp(s,"DOT") == 0)
    {
        complex a;
        complex b;
        a.n = num;
        b.n = num;

        float af[num];
        float bf[num];
        for(int i=0;i<num;i++)
        {
            scanf("%f",&af[i]);
        }
        for(int i=0;i<num;i++)
        {
            scanf("%f",&bf[i]);
        }

        a.a = af;
        b.a = bf;

        float result = dot(a,b);
        printf("%f\n", result);
    }

    else if(strcmp(s,"COS") == 0)
    {
        complex a;
        complex b;
        a.n = num;
        b.n = num;

        float af[num];
        float bf[num];
        for(int i=0;i<num;i++)
        {
            scanf("%f",&af[i]);
        }
        for(int i=0;i<num;i++)
        {
            scanf("%f",&bf[i]);
        }

        a.a = af;
        b.a = bf;

        float result = COS(a,b);
        printf("%f\n", result);
    }
}