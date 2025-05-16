/*

STACK IMPLEMENTATION USING DYNAMIC MEMORY.

➤ This program implements a basic stack using dynamic memory allocation (malloc).

 ➤ Supported Operations:
       - push(): Insert element on top of the stack
       - pop(): Remove element from top of the stack
       - peek(): View the top element without removing it
       - isEmpty(): Check if the stack is empty
       - isFull(): Check if the stack is full

➤ Dynamic memory allows to define the size of the stack at runtime,
   unlike static stacks which use a fixed-size array.

➤ This implementation uses a structure with:
   - `int *arr`  → Pointer to dynamically allocated memory
   - `int top`   → Tracks the index of the top element
   - `int size`  → Size of the stack (user-defined at runtime)

*/

#include <stdio.h>
#include <stdlib.h>

struct stack {
    int top, size;
    int *arr;
};

// Check if the stack is empty
int isEmpty(struct stack *s){
    if(s->top < 0){
        return 1;
    }
    return 0;
}

// Check if the stack is full
int isFull(struct stack *s){
    if(s->top == s->size-1){
        return 1;
    }
    return 0;
}

// Push operation: Adds an element to the top of the stack
void push(struct stack *s, int value) {
    if (isFull(s)) {
        printf("Stack is Full. Can't insert value.\n");
    } else {
        s->arr[++s->top] = value;  // Increment top and insert value
        printf("Element %d successfully added to stack.\n", value);
    }
}

// Pop operation: Removes the top element from the stack
void pop(struct stack *s) {
    if (isEmpty(s)) {
        printf("Stack Underflow.\n");
    } else {
        printf("%d popped from Stack.\n", s->arr[s->top--]);
    }
}

// Peek operation: Displays the top element without removing it
void peek(struct stack *s) {
    if (isEmpty(s)) {
        printf("Stack is Empty.\n");
    } else {
        printf("Top Element of Stack is: %d\n", s->arr[s->top]);
    }
}

int main() {
    struct stack s;
    s.top = -1;     

    printf("Enter the size of the stack: ");
    scanf("%d", &s.size);

    s.arr = (int*)malloc(s.size * sizeof(int));

    if(s.arr == NULL){
        printf("Memory Allocation Failed.\n");
        exit(1);
    }
    
    int choice, element;

    printf("\n--- Stack Operations ---\n");
    printf("1. Get TOP Element\n");
    printf("2. Insert Element\n");
    printf("3. Delete Element\n");
    printf("4. Is Stack Full?\n");
    printf("5. Is Stack Empty?\n");
    printf("6. Exit\n");

  
    while (1) {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: peek(&s);
                    break;

            case 2: printf("Enter Value: ");
                    scanf("%d", &element);
                    push(&s, element); 
                    break;

            case 3: pop(&s);
                    break;

            case 4: if (isFull(&s)) {
                       printf("Stack is Full.\n");
                    } else {
                       printf("Stack is Not Full.\n");
                    }
                    break;

            case 5:  if (isEmpty(&s)) {
                        printf("Stack is Empty.\n");
                    } else {
                        printf("Stack is Not Empty.\n");
                    }
                    break;

            case 6: free(s.arr);
                    s.arr = NULL;
                    printf("Exiting program.\n");
                    return 0;

            default: printf("Invalid choice. Please enter 1-6.\n");
        }
    }

    return 0;
}