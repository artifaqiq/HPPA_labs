#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const int MATRIX_SIZE = 5;
const int MATRIX_RAND_MAX = 5.0;

#define M 6
#define N 6
#define MEM_ALIGN 16

float** matrix_alloc();
void randomize_matrix(float** matrix);
void print_matrix(float** matrix);

__attribute__((optimize("no-tree-vectorize")))
int main()
{
    float** a = matrix_alloc(); randomize_matrix(a);
    float** b = matrix_alloc(); randomize_matrix(b);
    float** matrix_result = matrix_alloc();

    for(int k = 0; k < 100000; k++) {

        for(int i = 0; i < M; i++) {
            for(int j = 0; j < N; j++) {

                float sum = 0.0;
                for(int k = 0; k < N; k++) {
                    sum += a[i][k] + b[k][j];
                }

                matrix_result[i][j] = sum;

            }
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
