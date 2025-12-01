#include <stdio.h>

int binarySearch(int arr[], int n, int key);

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

    found = binarySearch(arr, n, key);
    if (found < 0) {
        printf("Integer not found in the array\n");
    } else {
        printf("Integer found at index = %d\n", found);
    }

    return 0;
}

int binarySearch(int arr[], int n, int key) {
    int left = 0, right = n - 1;

    while (left < right) {
        int mid = (left + right) / 2;

        if (arr[mid] == key) {
            return mid;
        } else if (arr[mid] > key) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return -1;
}
