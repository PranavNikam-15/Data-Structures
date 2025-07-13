#include <stdio.h>

void displayArray(int arr[], int n){
    for(int i = 0; i < n; i++){
        printf("%d\t", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {1, 0, 0, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(int);
    int count = 0;

    printf("Array Before:\n");
    displayArray(arr, n);

    for(int i = 0; i < n-count; i++) {
        if(arr[i] == 0) {
            for(int j = i; j < n - 1; j++) {
                arr[j] = arr[j + 1];
            }
            arr[n - 1] = 0;
            count++;
            i--; // Check the new value at current index again
        }
    }

    printf("\nArray After:\n");
    displayArray(arr, n);

    return 0;
}