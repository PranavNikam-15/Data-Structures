#include <stdio.h>

void generatePairs(int arr[], int n) {
    printf("\nPairs of Array:\n");
    // Outer loop picks the first element of the pair
    for (int i = 0; i < n - 1; i++) {
        // Inner loop picks the second element of the pair
        for (int j = i + 1; j < n; j++) {
            printf("(%d, %d)\t", arr[i], arr[j]);
        }
        printf("\n");
    }
}

int main() {
    int n;

    printf("Enter the size of Array: ");
    scanf("%d", &n);
    
    // A valid array must have at least two elements to form a pair
    if (n < 2) {
        printf("At least two elements are required to form pairs.\n");
        return 0; // Exit the program
    }

    int arr[n];

    // Read n elements from the user
    printf("Enter elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Call the function to generate and print pairs
    generatePairs(arr, n);
    
    return 0;
}