#include <stdio.h>

int main() {

    int arr[15] = {15, 22, 43, 45, 65, 76, 87, 98, 109, 1110};
    int n = 10, i, element, pos;

    // Take input for element and position
    printf("Enter the element to insert: ");
    scanf("%d", &element);
    printf("Enter the position (0-based index): ");
    scanf("%d", &pos);

    // Validate position
    if (pos < 0 || pos > n) {
        printf("Invalid position! Position must be between 0 and %d.\n", n);
        return 1;
    }

    // Shift elements to the right to make space
    for (i = n; i > pos; i--) {
        arr[i] = arr[i - 1];
    }

    // Insert the new element
    arr[pos] = element;
    n++;

    // Print the updated array
    printf("Array after insertion:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}