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
    printf("A:\n"); print_matrix(a);
    float** b = matrix_alloc(); randomize_matrix(b);
    printf("B:\n"); print_matrix(b);
    float** c = matrix_alloc();
    float* temp = (float*)aligned_alloc(MEM_ALIGN, 4 * sizeof(float));

    // c[6x4]
    for(int i = 0; i < M; i++) {

    	printf("temp = %p\n a = %p\n b = %p\n c = %p\n\n", temp, a[i], b, c[i]);
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
        printf("temp = %p\n a = %p\n b = %p\n c = %p\n\n", temp, a[i], b, c[i]);
    }

    // c[6x2]
    for(int i = 0; i < M; i++) {

    	printf("temp = %p\n a = %p\n b = %p\n c = %p\n\n", temp, a[i], b, c[i]);
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
        printf("temp = %p\n a = %p\n b = %p\n c = %p\n\n", temp, a[i], b, c[i]);
    }


    printf("C:\n");
    print_matrix(c);









    return 0;
}

float** matrix_alloc()
{
    float** result = (float**)aligned_alloc(MEM_ALIGN, M * sizeof(float*));
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

