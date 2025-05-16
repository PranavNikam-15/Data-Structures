/*

APPLICATION OF STACK — PALINDROME CHECKING

➤ A palindrome is a string that reads the same backward as forward 
   (e.g., "madam", "racecar", "level").

➤ Steps:
   1. Push all characters into the stack.
   2. Pop characters back to form the reversed string.
   3. Compare original and reversed strings.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack
{
    int top, size;
    char *arr;
};

// Check if the stack is empty
int isEmpty(struct stack *s)
{
    if (s->top < 0)
    {
        return 1;
    }
    return 0;
}

// Check if the stack is full
int isFull(struct stack *s)
{
    if (s->top == s->size - 1)
    {
        return 1;
    }
    return 0;
}

void push(struct stack *s, char ch)
{
    if (isFull(s))
    {
        printf("Stack is Full. Can't insert value.\n");
    }
    else
    {
        s->arr[++s->top] = ch;
    }
}

char pop(struct stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack Underflow.\n");
    }
    else
    {
        return s->arr[s->top--];
    }
}

int main()
{
    struct stack s;
    s.top = -1;
    char str[100];

    printf("Enter a string to reverse: ");
    scanf("%s", &str);

    s.size = strlen(str);
    s.arr = (char *)malloc(s.size * sizeof(char));

    if (s.arr == NULL)
    {
        printf("Memory Allocation Failed.\n");
        exit(1);
    }

    int i = 0;
    while (str[i] != '\0')
    {
        push(&s, str[i]);
        i++;
    }

    char revStr[s.size];
    i = 0;
    while (!isEmpty(&s))
    {
        revStr[i++] = pop(&s);
    }
    revStr[i] = '\0';

    if (strcmp(str, revStr) == 0){
        printf("The string is a Palindrome.\n");
    }else{
        printf("The string is not a Palindrome.\n");
    }
    free(s.arr);

    return 0;
}