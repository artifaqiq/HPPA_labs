#include <stdio.h>
#include <stdlib.h>

#define M 6
#define N 6
#define MEM_ALIGN 16

float** matrix2D_alloc();
void randomize_matrix2D(float **matrix);
void print_matrix2D(float **matrix);
float**** matrix4D_alloc();
void randomize_matrix4D(float ****matrix);
void print_matrix4D(float ****matrix);
float** matrix2D_sum(float** a, float** b);
float** matrix2D_mul(float** a, float** b);
float**** matrix4D_mul(float**** a, float **** b, int count);

int main()
{
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

float**** matrix4D_mul(float**** a, float **** b, int count)
{
    float**** result = matrix4D_alloc();

    for(int ct = 0; ct < count; ct++) {

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

float** matrix2D_mul(float** a, float** b)
{
    float** result = matrix2D_alloc();
    float sum;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {

            sum =
                    a[i][0] * b[0][j]
                    + a[i][1] * b[1][j]
                    + a[i][2] * b[2][j]
                    + a[i][3] * b[3][j]
                    + a[i][4] * b[4][j]
                    + a[i][5] * b[5][j];

            result[i][j] = sum;
        }
    }

    return result;

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
