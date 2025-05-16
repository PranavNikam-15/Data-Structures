/*

INFIX TO PREFIX CONVERSION USING STACK:

➤ Infix expressions (e.g., A + B) are easy for humans but not for computers.
  Converting them to Prefix (e.g., + A B) makes evaluation easier.

➤ This algorithm uses stack and includes reversing tricks to transform infix into prefix.

➤ Steps to convert Infix to Prefix:
   1. Reverse the infix expression.
   2. Swap '(' with ')' and vice versa.
   3. Use similar logic as Infix to Postfix:
      - If operand, add to result.
      - If '(', push to stack.
      - If ')', pop until '('.
      - If operator, pop from stack while precedence is higher or equal, then push.
   4. Reverse the final output to get Prefix.

➤ This is useful in:
   - Expression evaluation by compilers
   - Creating Abstract Syntax Trees
   - Parsing complex expressions

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

// Stack structure definition
struct stack
{
   int top, size;
   char *arr;
};

bool isEmpty(struct stack *s){
   return s->top < 0;
}

bool isFull(struct stack *s){
   return s->top == s->size - 1;
}

void push(struct stack *s, char value)
{
   if (isFull(s)){
      printf("Stack Overflow.\n");
   }
   else {
      s->arr[++s->top] = value;
   }
}

char pop(struct stack *s)
{
   if (isEmpty(s)){
      printf("Stack Underflow.\n");
      return '\0';
   }
   return s->arr[s->top--];
}

char peek(struct stack *s)
{
   if (isEmpty(s)){
      return '\0';
   }
   return s->arr[s->top];
}

bool isOperator(char op)
{
   return (op == '+' || op == '-' || op == '*' || op == '/');
}

// Get precedence of operator
int getPrecedence(char op)
{
   if (op == '+' || op == '-')
      return 1;
   if (op == '*' || op == '/')
      return 2;
   return 0;
}

// Reverse a character array (string)
void reverseExp(char *exp)
{
   int length = strlen(exp);
   char ch;

   for (int i = 0; i < length / 2; i++) {
      ch = exp[i];
      exp[i] = exp[length - i - 1];
      exp[length - i - 1] = ch;
   }
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
   char *prefix = (char *)malloc(s.size * sizeof(char));

   if (s.arr == NULL || prefix == NULL) {
      printf("Memory Allocation Failed.\n");
      exit(1);
   }

   // Step 1: Reverse the infix expression
   reverseExp(infix);

   // Step 2: Swap parentheses
   for (int i = 0; i < s.size; i++)
   {
      if (infix[i] == '('){
         infix[i] = ')';
      }
      else if (infix[i] == ')'){
         infix[i] = '(';
      }
   }

   int j = 0;

   // Step 3: Apply modified infix to postfix logic
   for (int i = 0; i < s.size; i++)
   {
      char ch = infix[i];

      if (isalnum(ch)) {
         // Operand → Add to result
         prefix[j++] = ch;
      }
      else if (ch == '(') {
         // Left parenthesis → Push to stack
         push(&s, ch);
      }
      else if (ch == ')')
      {
         // Right parenthesis → Pop until '('
         while (!isEmpty(&s) && peek(&s) != '(') {
            prefix[j++] = pop(&s);
         }
         pop(&s); // Remove '('
      }
      else if (isOperator(ch))
      {
         // Operator → Pop from stack while precedence is higher or equal
         while (!isEmpty(&s) && getPrecedence(peek(&s)) >= getPrecedence(ch)) {
            prefix[j++] = pop(&s);
         }
         push(&s, ch);
      }
   }

   // Step 4: Pop any remaining operators
   while (!isEmpty(&s)) {
      prefix[j++] = pop(&s);
   }

   prefix[j] = '\0';
   reverseExp(prefix);

   printf("Prefix Expression: %s\n", prefix);
   free(s.arr);
   free(prefix);

   return 0;
}