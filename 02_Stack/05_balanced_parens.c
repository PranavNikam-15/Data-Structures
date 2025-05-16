/*

APPLICATION OF STACK — CHECK BALANCED PARENTHESES

➤ This program uses a stack to check whether an expression has balanced parentheses:
   (), {}, and [].

➤ It uses dynamic memory allocation to build a stack based on expression size.

➤ Matching logic:
   - Every opening bracket must match with the correct closing one.
   - Uses LIFO stack behavior to validate nested brackets.

➤ Algorithm:
   1. Traverse each character of the expression.
   2. If it’s an opening bracket, push it to the stack.
   3. If it’s a closing bracket, check the top of stack:
      - If top is matching opening, pop it.
      - Else, it's unbalanced.
   4. At the end, if stack is empty → expression is balanced.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack {
    int top, size;
    char *arr;
};

int isEmpty(struct stack *s){
    if(s->top < 0){
        return 1;
    }
    return 0;
}

int isFull(struct stack *s){
    if(s->top == s->size-1){
        return 1;
    }
    return 0;
}


void push(struct stack *s, char value) {
    if (isFull(s)) {
        printf("Stack is Full. Can't insert value.\n");
    } else {
        s->arr[++s->top] = value;
    }
}

char pop(struct stack *s) {
    if (isEmpty(s)) {
        printf("Stack Underflow.\n");
        return '\0';
    }
    return s->arr[s->top--];
}

char peek(struct stack *s) {
    if (isEmpty(s)) {
        return '\0';
    }
    return s->arr[s->top];
}

int matchParens(char ch1, char ch2) {
    return (ch1 == '(' && ch2 == ')') ||
           (ch1 == '[' && ch2 == ']') ||
           (ch1 == '{' && ch2 == '}');
}

int main() {
    struct stack s;
    char exp[100];

    printf("Enter Expression: ");
    scanf("%s", exp);

    s.top = -1;
    s.size = strlen(exp);
    s.arr = (char *)malloc(s.size * sizeof(char));

    if (s.arr == NULL) {
        printf("Memory Allocation Failed.\n");
        exit(1);
    }

    for (int i = 0; exp[i] != '\0'; i++) {
        if (exp[i] == '(' || exp[i] == '[' || exp[i] == '{') {
            push(&s, exp[i]);
        } else if (exp[i] == ')' || exp[i] == ']' || exp[i] == '}') {
            if (isEmpty(&s) || !matchParens(peek(&s), exp[i])) {
                printf("Parentheses are NOT Balanced.\n");
                free(s.arr);
                return 1;
            }
            pop(&s);
        }
    }

    if (isEmpty(&s)) {
        printf("Parentheses are Balanced.\n");
    } else {
        printf("Parentheses are NOT Balanced.\n");
    }

    free(s.arr);
    return 0;
}