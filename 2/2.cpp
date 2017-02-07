/*
 * GCC Vector built-in functions
 * https://gcc.gnu.org/onlinedocs/gcc-4.9.2/gcc/X86-Built-in-Functions.html
 * */

#include "stdio.h"
#include "stdlib.h"

#define MEM_ALIGN 16
#define M 6
#define N 6


float** matrix2D_alloc();
void randomize_matrix2D(float **matrix);
void print_matrix2D(float **matrix);
float**** matrix4D_alloc();
void randomize_matrix4D(float ****matrix);
void print_matrix4D(float ****matrix);
float** matrix2D_sum(float** a, float** b);
float** matrix2D_mul(float** a, float** b);
float**** matrix4D_mul(float**** a, float **** b, int count);


int main() {
    float**** a = matrix4D_alloc();
    randomize_matrix4D(a);
    float**** b = matrix4D_alloc();
    randomize_matrix4D(b);
//    printf(" === A: \n"); print_matrix4D(a);
//    printf(" === B: \n"); print_matrix4D(b);

    float**** result = matrix4D_mul(a, b, 1000);
//    printf(" === C: \n"); print_matrix4D(result);

    return 0;
}

float** matrix2D_mul(float** a, float** b)
{
    float** c = matrix2D_alloc();
    float* temp = (float*)aligned_alloc(MEM_ALIGN, 4 * sizeof(float));

    for (int i = 0; i < N; i++) {

        asm volatile
        (
        // xmm0-xmm5 == b[6x4]
                "movl (%%edx), %%eax;"
                "movups (%%eax), %%xmm0;"

                "movl 8(%%edx), %%eax;"
                "movups (%%eax), %%xmm1;"

                "movl 16(%%edx), %%eax;"
                "movups (%%eax), %%xmm2;"

                "movl 24(%%edx), %%eax;"
                "movups (%%eax), %%xmm3;"

                "movl 32(%%edx), %%eax;"
                "movups (%%eax), %%xmm4;"

                "movl 40(%%edx), %%eax;"
                "movups (%%eax), %%xmm5;"

                //xmm0 * a[i][0]
                "movl 0(%%ecx), %%eax;"
                "movl %%eax, 0(%1);"
                "movl %%eax, 4(%1);"
                "movl %%eax, 8(%1);"
                "movl %%eax, 12(%1);"

                "movups (%1), %%xmm6;"
                "mulps %%xmm6, %%xmm0;"

                //xmm1 * a[i][1]
                "movl 4(%%ecx), %%eax;"
                "movl %%eax, 0(%1);"
                "movl %%eax, 4(%1);"
                "movl %%eax, 8(%1);"
                "movl %%eax, 12(%1);"

                "movups (%1), %%xmm6;"
                "mulps %%xmm6, %%xmm1;"

                //xmm2 * a[i][2]
                "movl 8(%%ecx), %%eax;"
                "movl %%eax, 0(%1);"
                "movl %%eax, 4(%1);"
                "movl %%eax, 8(%1);"
                "movl %%eax, 12(%1);"

                "movups (%1), %%xmm6;"
                "mulps %%xmm6, %%xmm2;"

                //xmm3 * a[i][3]
                "movl 12(%%ecx), %%eax;"
                "movl %%eax, 0(%1);"
                "movl %%eax, 4(%1);"
                "movl %%eax, 8(%1);"
                "movl %%eax, 12(%1);"

                "movups (%1), %%xmm6;"
                "mulps %%xmm6, %%xmm3;"

                //xmm4 * a[i][4]
                "movl 16(%%ecx), %%eax;"
                "movl %%eax, 0(%1);"
                "movl %%eax, 4(%1);"
                "movl %%eax, 8(%1);"
                "movl %%eax, 12(%1);"

                "movups (%1), %%xmm6;"
                "mulps %%xmm6, %%xmm4;"

                //xmm5 * a[i][5]
                "movl 20(%%ecx), %%eax;"
                "movl %%eax, 0(%1);"
                "movl %%eax, 4(%1);"
                "movl %%eax, 8(%1);"
                "movl %%eax, 12(%1);"

                "movups (%1), %%xmm6;"
                "mulps %%xmm6, %%xmm5;"

                //sum (xmm0 - xmm1) == c[i]
                "addps %%xmm5, %%xmm4;"
                "addps %%xmm4, %%xmm3;"
                "addps %%xmm3, %%xmm2;"
                "addps %%xmm2, %%xmm1;"
                "addps %%xmm1, %%xmm0;"

                "movups %%xmm0, (%0);"
        :
        :
        "r"(c[i]),
        "r"(temp),
        "c"(a[i]),
        "d"(b)
        :
        "%eax",
        "%ebx",
        "%xmm0",
        "%xmm1",
        "%xmm2",
        "%xmm3",
        "%xmm4",
        "%xmm5",
        "%xmm6"

        );
    }

    // c[6x2]
    for (int i = 0; i < M; i++) {

        asm volatile
        (
        // xmm0-xmm5 == b[6x2]
        "movl 0(%%edx), %%eax;"
                "movhps 16(%%eax), %%xmm0;"

                "movl 8(%%edx), %%eax;"
                "movhps 16(%%eax), %%xmm1;"

                "movl 16(%%edx), %%eax;"
                "movhps 16(%%eax), %%xmm2;"

                "movl 24(%%edx), %%eax;"
                "movhps 16(%%eax), %%xmm3;"

                "movl 32(%%edx), %%eax;"
                "movhps 16(%%eax), %%xmm4;"

                "movl 40(%%edx), %%eax;"
                "movhps 16(%%eax), %%xmm5;"

                //xmm0 * a[i][0]
                "movl 0(%%ecx), %%eax;"
                "movl %%eax, 0(%1);"
                "movl %%eax, 4(%1);"
                "movl %%eax, 8(%1);"
                "movl %%eax, 12(%1);"

                "movups (%1), %%xmm6;"
                "mulps %%xmm6, %%xmm0;"

                //xmm1 * a[i][1]
                "movl 4(%%ecx), %%eax;"
                "movl %%eax, 0(%1);"
                "movl %%eax, 4(%1);"
                "movl %%eax, 8(%1);"
                "movl %%eax, 12(%1);"

                "movups (%1), %%xmm6;"
                "mulps %%xmm6, %%xmm1;"

                //xmm2 * a[i][2]
                "movl 8(%%ecx), %%eax;"
                "movl %%eax, 0(%1);"
                "movl %%eax, 4(%1);"
                "movl %%eax, 8(%1);"
                "movl %%eax, 12(%1);"

                "movups (%1), %%xmm6;"
                "mulps %%xmm6, %%xmm2;"

                //xmm3 * a[i][3]
                "movl 12(%%ecx), %%eax;"
                "movl %%eax, 0(%1);"
                "movl %%eax, 4(%1);"
                "movl %%eax, 8(%1);"
                "movl %%eax, 12(%1);"

                "movups (%1), %%xmm6;"
                "mulps %%xmm6, %%xmm3;"

                //xmm4 * a[i][4]
                "movl 16(%%ecx), %%eax;"
                "movl %%eax, 0(%1);"
                "movl %%eax, 4(%1);"
                "movl %%eax, 8(%1);"
                "movl %%eax, 12(%1);"

                "movups (%1), %%xmm6;"
                "mulps %%xmm6, %%xmm4;"

                //xmm5 * a[i][5]
                "movl 20(%%ecx), %%eax;"
                "movl %%eax, 0(%1);"
                "movl %%eax, 4(%1);"
                "movl %%eax, 8(%1);"
                "movl %%eax, 12(%1);"

                "movups (%1), %%xmm6;"
                "mulps %%xmm6, %%xmm5;"

                //sum (xmm0 - xmm1) == c[i]
                "addps %%xmm5, %%xmm4;"
                "addps %%xmm4, %%xmm3;"
                "addps %%xmm3, %%xmm2;"
                "addps %%xmm2, %%xmm1;"
                "addps %%xmm1, %%xmm0;"

                "movhps %%xmm0, (%0);"
        :
        :
        "r"(c[i] + 4),
        "r"(temp),
        "c"(a[i]),
        "d"(b)
        :
        "%eax",
        "%ebx",
        "%xmm0",
        "%xmm1",
        "%xmm2",
        "%xmm3",
        "%xmm4",
        "%xmm5",
        "%xmm6"

        );
    }

    return c;

}

float** matrix2D_sum(float** a, float** b)
{
    float** result = matrix2D_alloc();

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            result[i][j] = a[i][j] + b[i][j];
        }
    }

    return result;
}

float**** matrix4D_alloc()
{
    float**** result = (float****)aligned_alloc(MEM_ALIGN, M * sizeof(float***));
    for(int i = 0; i < M; i++) {
        result[i] = (float***)aligned_alloc(MEM_ALIGN, M * sizeof(float**));
    }
    for(int i = 0; i < M; i++) {
        for(int j = 0; j < M; j++) {
            result[i][j] = matrix2D_alloc();
        }
    }

    return result;
}

float**** matrix4D_mul(float**** a, float **** b, int count)
{
    float**** result = matrix4D_alloc();

    for(int ct = 0; ct < count / 2; ct++) {

        for(int i = 0; i < M; i++) {
            for(int j = 0; j < M; j++) {

                float** sum = matrix2D_alloc();
                for(int k = 0; k < M; k++) {
                    sum = matrix2D_sum(sum, matrix2D_mul(a[i][k], b[k][j]));
                }

                result[i][j] = sum;
            }
        }
    }

    return result;

}

void randomize_matrix4D(float**** matrix)
{
    for(int i = 0; i < M; i++) {
        for(int j = 0; j < M; j++) {
            randomize_matrix2D(matrix[i][j]);
        }
    }
}

void print_matrix4D(float****matrix)
{
    for(int i = 0; i < M; i++) {
        for(int j = 0; j < M; j++) {
            printf(" ::: [%d][%d]:\n", i, j);
            print_matrix2D(matrix[i][j]);
        }
    }
}

float** matrix2D_alloc()
{
    float** result = (float**)aligned_alloc(MEM_ALIGN, N * sizeof(float*));
    for(int i = 0; i < N; i++) {
        result[i] = (float*)aligned_alloc(MEM_ALIGN, N * sizeof(float));
    }

    return result;
}

void randomize_matrix2D(float **matrix)
{
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            matrix[i][j] = i * 10 + j;
        }
    }
}

void print_matrix2D(float **matrix)
{
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            printf("%7.1f ", matrix[i][j]);
        }
        printf("\n");
    }
}
