#include <stdio.h>
#include <stdlib.h>

int smallestInArray(int *arr, int n);

int main() {
    int *arr;
    int n;

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

    int smallest = smallestInArray(arr, n);
    printf("Smallest element in the arr - [%d]\n", smallest);

    free(arr);

    return 0;
}

int smallestInArray(int *arr, int n) {
    if (n < 1) return 0;

    int smallest = arr[0];
    for (int i = 1; i < n; i++) {
        if (smallest > arr[i]) smallest = arr[i];
    }

    return smallest;
}
