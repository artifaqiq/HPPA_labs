/*
 * GCC Vector built-in functions
 * https://gcc.gnu.org/onlinedocs/gcc-4.9.2/gcc/X86-Built-in-Functions.html
 * */

#include "stdio.h"
#include "stdlib.h"

#define MEM_ALIGN 16
#define M 6
#define N 6



typedef float v4sf __attribute__ ((vector_size (MEM_ALIGN)));

float** matrix_alloc();
void randomize_matrix(float** matrix);
void print_matrix(float** matrix);

#define print_vf(v) printf("%5.1f %5.1f %5.1f %5.1f\n", v[0], v[1], v[2], v[3])
#define memsetf(ptr, v) for(int _i = 0; _i < 4; _i++) {ptr[_i] = v;}

int main() {
    __builtin_cpu_init();

    float** a = matrix_alloc(); randomize_matrix(a);
//    printf("A:\n"); print_matrix(a);
    float** b = matrix_alloc(); randomize_matrix(b);
//    printf("B:\n"); print_matrix(b);
    float** c = matrix_alloc();
    float* temp = (float*)aligned_alloc(MEM_ALIGN, 4 * sizeof(float));

    v4sf raw0, raw1, raw2, raw3, raw4, raw5, cur_a;

    for(int k = 0; k < 100000; k++) {

        for (int i = 0; i < M; i++) {
            raw0 = __builtin_ia32_loadups(b[0]);
            raw1 = __builtin_ia32_loadups(b[1]);
            raw2 = __builtin_ia32_loadups(b[2]);
            raw3 = __builtin_ia32_loadups(b[3]);
            raw4 = __builtin_ia32_loadups(b[4]);
            raw5 = __builtin_ia32_loadups(b[5]);

            memsetf(temp, a[i][0]);
            cur_a = __builtin_ia32_loadups(temp);
            raw0 = __builtin_ia32_mulps(raw0, cur_a);

            memsetf(temp, a[i][1]);
            cur_a = __builtin_ia32_loadups(temp);

            raw1 = __builtin_ia32_mulps(raw1, cur_a);

            memsetf(temp, a[i][2]);
            cur_a = __builtin_ia32_loadups(temp);
            raw2 = __builtin_ia32_mulps(raw2, cur_a);

            memsetf(temp, a[i][3]);
            cur_a = __builtin_ia32_loadups(temp);
            raw3 = __builtin_ia32_mulps(raw3, cur_a);

            memsetf(temp, a[i][4]);
            cur_a = __builtin_ia32_loadups(temp);
            raw4 = __builtin_ia32_mulps(raw4, cur_a);

            memsetf(temp, a[i][5]);
            cur_a = __builtin_ia32_loadups(temp);
            raw5 = __builtin_ia32_mulps(raw5, cur_a);

            raw4 = __builtin_ia32_addps(raw4, raw5);
            raw3 = __builtin_ia32_addps(raw3, raw4);
            raw2 = __builtin_ia32_addps(raw2, raw3);
            raw1 = __builtin_ia32_addps(raw1, raw2);
            raw0 = __builtin_ia32_addps(raw0, raw1);

            __builtin_ia32_storeups(c[i], raw0);

        }
    }















    return 0;
}

float** matrix_alloc()
{
    float** result = (float**)malloc(M * sizeof(float*));
    for(int i = 0; i < M; i++) {
        result[i] = (float*)aligned_alloc(MEM_ALIGN, N * sizeof(float));
    }

    return result;
}

void randomize_matrix(float** matrix)
{
    for(int i = 0; i < M; i++) {
        for(int j = 0; j < N; j++) {
            matrix[i][j] = i * 10 + j;
        }
    }
}

void print_matrix(float** matrix)
{
    for(int i = 0; i < M; i++) {
        for(int j = 0; j < N; j++) {
            printf("%5.1f ", matrix[i][j]);
        }
        printf("\n");
    }
}

