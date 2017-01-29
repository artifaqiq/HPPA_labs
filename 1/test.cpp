#include "stdio.h"
#include "stdlib.h"

int main()
{
    float* a = (float*)aligned_alloc(16, 4 * sizeof(float));
    a[0] = 1.1; a[1] = 2.2; a[2] = 3.3; a[3] = 4.4;

    float* b = (float*)aligned_alloc(16, 4 * sizeof(float));
    b[0] = 9.9; b[1] = 8.8; b[2] = 7.7; b[3] = 6.6;

    float* c = (float*)aligned_alloc(16, 4 * sizeof(float));

    float k = 15;

    float mask[4] = {0, 0, 0, 0};

    int sum = 0, x = 1, y = 2;

    asm
    (
        "movaps %%xmm7, (%4)"
        "movaps (%1), %%xmm0;"
        "movaps (%2), %%xmm1;"
        "addps %%xmm1, %%xmm0;"
        "movaps %%xmm0, (%0);"
        :"=r"(c)
        :"r"(a), "r"(b), "r"(k), "r"(mask)
        :

    );


    printf("%f %f %f %f\n", a[0], a[1], a[2], a[3]);
    printf("%f %f %f %f\n", b[0], b[1], b[2], b[3]);
    printf("%f %f %f %f\n", c[0], c[1], c[2], c[3]);

}
