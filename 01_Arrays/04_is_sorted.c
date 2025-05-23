#include <stdio.h>
#include <stdbool.h>

bool isSorted(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        // If the current element is greater than the next one, it's not sorted
        if (arr[i] > arr[i + 1]) {
            return false;
        }
    }
    return true;
}

int main() {
    int arr[] = {1, 3, 5, 7, 9, 12, 15, 22};
    int n = 8;

    if (isSorted(arr, n)) {
        printf("The array is sorted in ascending order.\n");
    } else {
        printf("The array is not sorted.\n");
    }

    return 0;
}