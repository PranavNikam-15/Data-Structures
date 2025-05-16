/*
1. Implement a Stack using Static Memory (Array)

   ➤ Stack is a linear data structure that follows the LIFO (Last In First Out) principle.
   ➤ The last element inserted is the first one to be removed.
   ➤ This program uses an array (static memory) to implement a stack of fixed size.
   ➤ Supported Operations:
       - push(): Insert element on top of the stack
       - pop(): Remove element from top of the stack
       - peek(): View the top element without removing it
       - isEmpty(): Check if the stack is empty
       - isFull(): Check if the stack is full
*/

#include <stdio.h>

#define MAX 10  // Maximum size of the stack

// Stack structure using array
struct stack {
    int top, size;
    int arr[MAX];
};

// Check if the stack is empty
int isEmpty(struct stack s){
    if(s.top < 0){
        return 1;
    }
    return 0;
}

// Check if the stack is full
int isFull(struct stack s){
    if(s.top == s.size-1){
        return 1;
    }
    return 0;
}

// Push operation: Adds an element to the top of the stack
struct stack push(struct stack s, int value) {
    if (isFull(s)) {
        printf("Stack is Full. Can't insert value.\n");
    } else {
        s.arr[++s.top] = value;  // Increment top and insert value
        printf("Element %d successfully added to stack.\n", value);
    }
    return s;  // Return the updated stack
}

// Pop operation: Removes the top element from the stack
struct stack pop(struct stack s) {
    if (isEmpty(s)) {
        printf("Stack Underflow.\n");
    } else {
        printf("%d popped from Stack.\n", s.arr[s.top--]);  // Display and remove top element
    }
    return s;  // Return the updated stack
}

// Peek operation: Displays the top element without removing it
void peek(struct stack s) {
    if (isEmpty(s)) {
        printf("Stack is Empty.\n");
    } else {
        printf("Top Element of Stack is: %d\n", s.arr[s.top]);
    }
}

int main() {
    struct stack s;
    s.top = -1;     
    s.size = MAX;
    
    int choice, element;

    printf("\n--- Stack Operations ---\n");
    printf("1. Get TOP Element\n");
    printf("2. Insert Element\n");
    printf("3. Delete Element\n");
    printf("4. Is Stack Full?\n");
    printf("5. Is Stack Empty?\n");
    printf("6. Exit\n");

    // Menu-driven program to perform stack operations
    while (1) {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                peek(s);
                break;

            case 2:
                printf("Enter Value: ");
                scanf("%d", &element);
                s = push(s, element);  // Push value and update stack
                break;

            case 3:
                s = pop(s);  // Pop element and update stack
                break;

            case 4:
                if (isFull(s)) {
                    printf("Stack is Full.\n");
                } else {
                    printf("Stack is Not Full.\n");
                }
                break;

            case 5:
                if (isEmpty(s)) {
                    printf("Stack is Empty.\n");
                } else {
                    printf("Stack is Not Empty.\n");
                }
                break;

            case 6:
                printf("Exiting program.\n");
                return 0;

            default:
                printf("Invalid choice. Please enter 1-6.\n");
        }
    }

    return 0;
}