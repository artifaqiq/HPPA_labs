#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const int MATRIX_SIZE = 5;
const int MATRIX_RAND_MAX = 5.0;

float** square_matrix_malloc(int size);
void randomize_square_matrix(float** matrix, int size, float rand_max);
void print_square_matrix(float** matrix, int size);
float** multiply_square_matrix(float** matrix_a, float** matrix_b, int size);

int main()
{

    float **matrix_a, **matrix_b, **matrix_c;


    matrix_a = square_matrix_malloc(MATRIX_SIZE);
    matrix_b = square_matrix_malloc(MATRIX_SIZE);

    randomize_square_matrix(matrix_a, MATRIX_SIZE, MATRIX_RAND_MAX);
    printf("A:\n");
    print_square_matrix(matrix_a, MATRIX_SIZE);

    randomize_square_matrix(matrix_b, MATRIX_SIZE, MATRIX_RAND_MAX);
    printf("\nB:\n");
    print_square_matrix(matrix_b, MATRIX_SIZE);

    matrix_c = multiply_square_matrix(matrix_a, matrix_b, MATRIX_SIZE);
    printf("\nC:\n");
    print_square_matrix(matrix_c, MATRIX_SIZE);



    return 0;
}

float** square_matrix_malloc(int size)
{
    float** matrix = (float**)malloc(size * sizeof(float*));

    for(int i = 0; i < size; i++) {
        matrix[i] = (float*)malloc(size * sizeof(float));
    }

    return matrix;
}

void randomize_square_matrix(float** matrix, int size, float rand_max)
{
    srand((unsigned int)time(NULL));

    for(int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            float rand_value = ((float)rand() / (float)(RAND_MAX)) * rand_max;
            matrix[i][j] = rand_value;
        }
    }

}

void print_square_matrix(float** matrix, int size)
{
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            printf("%7.2f", matrix[i][j]);
        }
        printf("\n");
    }
}

float** multiply_square_matrix(float** matrix_a, float** matrix_b, int size)
{
    float** matrix_result = square_matrix_malloc(size);

    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {

            float sum = 0.0;
            for(int k = 0; k < size; k++) {
                sum += matrix_a[i][k] + matrix_b[k][j];
            }

            matrix_result[i][j] = sum;

        }
    }

    return matrix_result;
}