/*

APPLICATION OF STACK — REVERSE A STRING USING STACK

➤ A classic use of stack is to reverse data — such as a string — because
   stack follows the LIFO (Last In, First Out) principle.

➤ Steps to reverse a string using stack:
   1. Push each character of the string into the stack.
   2. Pop each character from the stack and overwrite the original string.

➤ This approach is useful in problems like:
   - Palindrome checking
   - Expression evaluation
   - Backtracking algorithms

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>



struct stack {
    int top, size;
    char *arr;
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

void push(struct stack *s, char ch) {
    if (isFull(s)) {
        printf("Stack is Full. Can't insert value.\n");
    } else {
        s->arr[++s->top] = ch;
    }
}

char pop(struct stack *s) {
    if (isEmpty(s)) {
        printf("Stack Underflow.\n");
    } else {
        return s->arr[s->top--];
    }
}

int main() {
    struct stack s;
    s.top = -1;    
    char str[100];

    printf("Enter a string to reverse: ");
    scanf("%s", &str);
    
    s.size = strlen(str);
    s.arr = (char*)malloc(s.size * sizeof(char));

    if(s.arr == NULL){
        printf("Memory Allocation Failed.\n");
        exit(1);
    }
    
   int i = 0;
   while (str[i] != '\0') {
       push(&s, str[i]);
       i++;
   }

   i = 0;
   while (!isEmpty(&s)) {
       str[i++] = pop(&s);
   }

   str[i] = '\0';
   printf("Reversed String: %s\n", str);
   free(s.arr);

   return 0;
}