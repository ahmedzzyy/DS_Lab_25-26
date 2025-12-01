#include <stdio.h>
#include <stdlib.h>

void multiplyMatricesAndDisplay(int **a, int **b, int rowA, int rowB, int colA, int colB);

/*
[02 0] * [10 1 0 05] - [20 2 0 10]
[-1 1] * [02 1 1 -1] - [-8 0 1 -6]
[00 2]               - [04 2 2 -2]
*/

int main() {
    int **a, **b;
    int rowA, rowB, colA, colB;

    printf("\n--- MATRIX A ---\n");
    printf("Enter number of rows: ");
    scanf("%d", &rowA);
    printf("Enter number of columns: ");
    scanf("%d", &colA);

    a = (int **)malloc(rowA * sizeof(int*));

    if (a == NULL) {
        printf("Failed to allocate memory for rows\n");
        printf("Exiting...\n");
        return 1;
    }

    for (int i = 0; i < rowA; i++) {
        a[i] = (int *)malloc(colA * sizeof(int));

        if (a[i] == NULL) {
            printf("Failed to allocate memory for a row\n");
            printf("Exiting...\n");

            for (int j = 0; j < i; j++) {
                free(a[j]);
            }
            free(a);

            return 1;
        }

        for (int j = 0; j < colA; j++) {
            scanf("%d", (*(a + i) + j));
        }
    }

    printf("\n--- END ---\n");

    printf("\n--- MATRIX B ---\n");
    printf("Enter number of rows: ");
    scanf("%d", &rowB);
    printf("Enter number of columns: ");
    scanf("%d", &colB);

    b = (int **)malloc(rowB * sizeof(int*));

    if (b == NULL) {
        printf("Failed to allocate memory for rows\n");
        printf("Exiting...\n");
        return 1;
    }

    for (int i = 0; i < rowB; i++) {
        b[i] = (int *)malloc(colB * sizeof(int));

        if (b[i] == NULL) {
            printf("Failed to allocate memory for a row\n");
            printf("Exiting...\n");

            for (int j = 0; j < i; j++) {
                free(b[j]);
            }
            free(b);

            return 1;
        }

        for (int j = 0; j < colB; j++) {
            scanf("%d", (*(b + i) + j));
        }
    }

    printf("\n--- END ---\n");

    multiplyMatricesAndDisplay(a, b, rowA, rowB, colA, colB);

    return 0;
}

void multiplyMatricesAndDisplay(int **a, int **b, int rowA, int rowB, int colA, int colB) {
    if (colA != rowB) {
        printf("Dimensions are not suitable for matrix multiplication.\n");
    }

    int **c = (int **)malloc(rowA * sizeof(int*));

    for (int i = 0; i < rowA; i++) {
        c[i] = (int *)malloc(colB * sizeof(int));

        if (c[i] == NULL) {
            printf("Failed to allocate memory for a row\n");
            printf("Exiting...\n");

            for (int j = 0; j < i; j++) {
                free(c[j]);
            }
            free(c);

            return;
        }

        for (int j = 0; j < colB; j++) {
            int sum = 0;

            for (int k = 0; k < rowB; k++) {
                sum += *(*(a + i) + k) * *(*(b + k) + j);
            }

            *(*(c + i) + j) = sum;
        }
    }

    printf("\n---Resultant Matrix ---\n");
    for (int i = 0; i < rowA; i++) {
        for (int j = 0; j < colB; j++) {
            printf("[%d]", *(*(c + i) + j));
        }
        printf("\n");
        free(*(c + i));
    }
    printf("\n--- END ---\n");
    free(c);
}
