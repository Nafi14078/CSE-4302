#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX_SIZE 100

typedef struct {
    int data[MAX_SIZE];
    int top;
} Stack;

void initialize(Stack *stack) {
    stack->top = -1;
}

bool isEmpty(Stack *stack) {
    return stack->top == -1;
}

void push(Stack *stack, int item) {
    if (stack->top < MAX_SIZE - 1) {
        stack->data[++(stack->top)] = item;
    } else {
        printf("Stack overflow\n");
        exit(1);
    }
}

int pop(Stack *stack) {
    if (stack->top >= 0) {
        return stack->data[(stack->top)--];
    } else {
        printf("Stack underflow\n");
        exit(1);
    }
}

int evaluatePostfix(char *expression) {
    Stack stack;
    initialize(&stack);

    for (int i = 0; expression[i] != '\0'; i++) {
        if (isdigit(expression[i])) {
            push(&stack, expression[i] - '0');
        } else {
            int operand2 = pop(&stack);
            int operand1 = pop(&stack);
            switch (expression[i]) {
                case '+':
                    push(&stack, operand1 + operand2);
                    break;
                case '-':
                    push(&stack, operand1 - operand2);
                    break;
                case '*':
                    push(&stack, operand1 * operand2);
                    break;
                case '/':
                    push(&stack, operand1 / operand2);
                    break;
            }
        }
    }

    return pop(&stack);
}

int main() {
    char expression[MAX_SIZE];
    printf("Enter postfix expression: ");
    fgets(expression, sizeof(expression), stdin);

    int result = evaluatePostfix(expression);
    printf("Result: %d\n", result);

    return 0;
}
