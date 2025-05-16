/*

INFIX TO POSTFIX CONVERSION USING STACK

➤ Infix expression: Operators are placed between operands.
   Example: A + B

➤ Postfix expression (Reverse Polish Notation): Operators are placed after operands.
   Example: A B +

➤ Why convert to Postfix?
   - Removes the need for parentheses.
   - Easier to evaluate using stack-based algorithms.

➤ Steps to convert Infix to Postfix:
   1. Initialize an empty stack for operators.
   2. Initialize an empty output string for the postfix expression.
   3. Scan the infix expression from left to right.
   4. For each character:
      - Operand (e.g., A, B, 1, 2...):
        → Add directly to the postfix output.
      - Left Parenthesis `(`:
        → Push to the stack.
      - Right Parenthesis `)`:
        → Pop from stack to output until a left parenthesis is encountered.
        → Pop and discard the left parenthesis.
      - Operator (+, -, *, /):
        → While top of stack has equal or higher precedence:
           → Pop it and add to output.
        → Push current operator onto the stack.
   5. After scanning, pop all remaining operators from the stack to the output.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

struct stack
{
    int top, size;
    char *arr;
};

bool isEmpty(struct stack *s)
{
    return s->top < 0;
}

bool isFull(struct stack *s){
    return s->top == s->size - 1;
}

void push(struct stack *s, char value)
{
    if (isFull(s)){
        printf("Stack Overflow.\n");
    } else {
        s->arr[++s->top] = value;
    }
}

// Pop operation: Removes the top element from the stack
char pop(struct stack *s)
{
    if (isEmpty(s)){
        printf("Stack Underflow.\n");
        return '\0';
    }
    return s->arr[s->top--];
}

// Peek operation: Returns the top element without removing it
char peek(struct stack *s)
{
    if (isEmpty(s)) {
        return '\0';
    }
    return s->arr[s->top];
}

bool isOperator(char op){
    return (op == '+' || op == '-' || op == '*' || op == '/');
}

int getPrecedence(char op){
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}

int main()
{
    struct stack s;
    char infix[100];

    printf("Enter Expression: ");
    scanf("%s", infix);

    s.top = -1;
    s.size = strlen(infix);
    s.arr = (char *)malloc(s.size * sizeof(char));
    char *postfix = (char *)malloc(s.size * sizeof(char));

    if (s.arr == NULL || postfix == NULL)
    {
        printf("Memory Allocation Failed.\n");
        exit(1);
    }

    int j = 0;
    char ch;
    
    for (int i = 0; i < s.size; i++)
    {
        ch = infix[i];

        if (isalnum(ch))
        {
            // Operand → Add to postfix
            postfix[j++] = ch;
        }
        else if (ch == '(')
        {
            // Left parenthesis → Push to stack
            push(&s, ch);
        }
        else if (ch == ')')
        {
            // Right parenthesis → Pop until '('
            while (!isEmpty(&s) && peek(&s) != '(')
            {
                postfix[j++] = pop(&s);
            }
            pop(&s); // Discard '('
        }
        else if (isOperator(ch))
        {
            // Operator → Pop while precedence is higher or equal
            while (!isEmpty(&s) && getPrecedence(peek(&s)) >= getPrecedence(ch))
            {
                postfix[j++] = pop(&s);
            }
            push(&s, ch);
        }
    }

    // Pop remaining operators
    while (!isEmpty(&s))
    {
        postfix[j++] = pop(&s);
    }

    postfix[j] = '\0';
    printf("Postfix Expression: %s\n", postfix);

    free(s.arr);
    free(postfix);
    return 0;
}