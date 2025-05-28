#include <stdio.h>

void subArrays(int arr[], int n) {
    printf("\nSub-Arrays:\n\n");

    // Outer loop defines the starting index of the subarray
    for (int i = 0; i < n; i++) {
        // Middle loop defines the ending index of the subarray
        for (int j = i; j < n; j++) {
            // Inner loop prints elements from start (i) to end (j)
            for (int k = i; k <= j; k++) {
                printf("%d ", arr[k]);
            }
            printf("\n");
        }
        printf("\n");
    }
}

int main() {
    int n;

    printf("Enter the size of Array: ");
    scanf("%d", &n);

    int arr[n]; 

    printf("Enter elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    subArrays(arr, n);
    return 0;
}