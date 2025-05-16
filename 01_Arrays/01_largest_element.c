#include <stdio.h>

int main() {
    int n, i, largest;

    // Input Size of the array
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];  // Declare array of size n

    // Input Array elements
    printf("Enter %d elements:\n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Assume the first element is the largest
    largest = arr[0];

    // Traverse and update largest if current element is greater
    for(i = 1; i < n; i++) {
        if(arr[i] > largest) {
            largest = arr[i];
        }
    }

    printf("The largest element is: %d\n", largest);    
    return 0;
}