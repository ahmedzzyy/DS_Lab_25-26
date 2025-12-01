#include <stdio.h>

void bubbleSortAndDisplay(int arr[], int n);
void selectionSortAndDisplay(int arr[], int n);
void insertionSortAndDisplay(int arr[], int n);

int main() {
    int arr[100], n;

    printf("Enter the number of integers: ");
    scanf("%d", &n);

    printf("Enter integers:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    bubbleSortAndDisplay(arr, n);
    selectionSortAndDisplay(arr, n);
    insertionSortAndDisplay(arr, n);

    return 0;
}

void bubbleSortAndDisplay(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int swapper = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = swapper;
            }
        }
    }

    printf("--- Bubble Sort ---\n");
    for (int i = 0; i < n; i++) {
        printf("[%d]", arr[i]);
    }
    printf("\n--- Done ---\n");
}

void selectionSortAndDisplay(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int indexOfMinimum = i;

        for (int j = i + 1; j < n; j++) {
            if (arr[indexOfMinimum] > arr[j]) {
                indexOfMinimum = j;
            }
        }

        int swapper = arr[i];
        arr[i] = arr[indexOfMinimum];
        arr[indexOfMinimum] = swapper;
    }

    printf("--- Selection Sort ---\n");
    for (int i = 0; i < n; i++) {
        printf("[%d]", arr[i]);
    }
    printf("\n--- Done ---\n");
}

void insertionSortAndDisplay(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }

    printf("--- Insertion Sort ---\n");
    for (int i = 0; i < n; i++) {
        printf("[%d]", arr[i]);
    }
    printf("\n--- Done ---\n");
}
