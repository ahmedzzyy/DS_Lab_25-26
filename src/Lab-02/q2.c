#include <stdio.h>
#include <stdlib.h>

void selectionSortRecursive(int *arr, int n, int currentIndex);

int main() {
    int *arr, n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    arr = (int *)malloc(n * sizeof(int));

    if (arr == NULL) {
        printf("Memory not allocated\n");
        printf("Exiting...\n");
        return 1;
    }

    printf("Enter integers:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    selectionSortRecursive(arr, n, 0);

    printf("--- Selection Sort (Recursive) ---\n");
    for (int i = 0; i < n; i++) {
        printf("[%d]", arr[i]);
    }
    printf("\n--- Done ---\n");

    return 0;
}

void selectionSortRecursive(int *arr, int n, int currentIndex) {
    if (currentIndex == n - 1) return;
    int indexOfMinimum = currentIndex;

    for (int j = currentIndex + 1; j < n; j++) {
        if (*(arr + indexOfMinimum) > *(arr + j)) {
            indexOfMinimum = j;
        }
    }

    int swapper = *(arr + currentIndex);
    *(arr + currentIndex) = *(arr + indexOfMinimum);
    *(arr + indexOfMinimum) = swapper;

    selectionSortRecursive(arr, n, currentIndex + 1);
}
