#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#define MAX_SIZE 100

// Function to push an element onto the stack
void push(char stack[], int* top, char item) {
    if (*top == MAX_SIZE - 1) {
        printf("Stack Overflow\n");
        exit(EXIT_FAILURE);
    }
    stack[++(*top)] = item;
}

// Function to pop an element from the stack
char pop(char stack[], int* top) {
    if (*top == -1) {
        printf("Stack Underflow\n");
        exit(EXIT_FAILURE);
    }
    return stack[(*top)--];
}

// Function to convert infix expression to postfix expression
void infixToPostfix(char infix[]) {
    char stack[MAX_SIZE];
    int top = -1;

    int i;
    char ch;

    for (i = 0; infix[i] != '\0'; ++i) {
        ch = infix[i];

        if (isalnum(ch)) {
            printf("%c", ch);  // Operand, directly print
        } else if (ch == '(') {
            push(stack, &top, ch);  // Opening parenthesis, push onto stack
        } else if (ch == ')') {
            while (top != -1 && stack[top] != '(') {
                printf("%c", pop(stack, &top));  // Print operators until '(' is encountered
            }
            if (top != -1 && stack[top] == '(') {
                pop(stack, &top);  // Pop '(' from the stack
            }
        } else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            while (top != -1 && (stack[top] == '+' || stack[top] == '-' || stack[top] == '*' || stack[top] == '/')) {
                printf("%c", pop(stack, &top));  // Print operators with higher or equal precedence
            }
            push(stack, &top, ch);  // Push the current operator onto the stack
        }
    }

    // Pop remaining operators from the stack and print
    while (top != -1) {
        printf("%c", pop(stack, &top));
    }

    printf("\n");
}

int main() {
    char infix[MAX_SIZE];

    // Input infix expression
    printf("Enter the infix expression: ");
    scanf("%s", infix);

    // Convert infix to postfix and print the result
    printf("Postfix expression: ");
    infixToPostfix(infix);
	getch();
    return 0;
}
