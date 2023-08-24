#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 5

typedef struct {
    int arr[MAX_SIZE];
    int top;
} Stack;

void initialize(Stack *stack) {
    stack->top = -1;
}

bool is_empty(Stack *stack) {
    return stack->top == -1;
}

bool is_full(Stack *stack) {
    return stack->top == MAX_SIZE - 1;
}

bool push(Stack *stack, int item) {
    if (is_full(stack)) {
        return false;
    }
    stack->arr[++stack->top] = item;
    return true;
}

int pop(Stack *stack) {
    if (is_empty(stack)) {
        return -1;
    }
    return stack->arr[stack->top--];
}

int top(Stack *stack) {
    if (is_empty(stack)) {
        return -1;
    }
    return stack->arr[stack->top];
}

int main() {
    Stack stack;
    initialize(&stack);

    int function_id, parameter;
    while (1) {
        scanf("%d", &function_id);

        if (function_id == -1) {
            break;
        }

        switch (function_id) {
            case 1:
                scanf("%d", &parameter);
                if (push(&stack, parameter)) {
                    printf("Pushed %d\n", parameter);
                } else {
                    printf("overflow%d\n", parameter);
                }
                break;

            case 2:
                if (!is_empty(&stack)) {
                    printf("Popped %d\n", pop(&stack));
                } else {
                    printf("underflow");
                }
                break;

            case 3:
                printf("IsEmpty: %s\n", is_empty(&stack) ? "true" : "false");
                break;

            case 4:
                printf("IsFull: %s\n", is_full(&stack) ? "true" : "false");
                break;

            case 5:
                printf("Size: %d\n", stack.top + 1);
                break;

            case 6:
                if (!is_empty(&stack)) {
                    printf("Top item: %d\n", top(&stack));
                } else {
                    printf("Stack is empty. No top item\n");
                }
                break;

            default:
                printf("Invalid function ID\n");
                break;
        }
    }

    return 0;
}
