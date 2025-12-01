#include <stdio.h>

int linearSearch(int arr[], int n, int key);

int main() {
    int arr[100], n, key, found;

    printf("Enter the number of integers: ");
    scanf("%d", &n);

    printf("Enter integers:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter integer to find: ");
    scanf("%d", &key);

    found = linearSearch(arr, n, key);
    if (found < 0) {
        printf("Integer not found in the array\n");
    } else {
        printf("Integer found at index = %d\n", found);
    }

    return 0;
}

int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) return i;
    }

    return -1;
}
