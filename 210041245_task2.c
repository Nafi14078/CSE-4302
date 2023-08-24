#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    char data[MAX_SIZE];
    int top;
} Stack;

void initialize(Stack *stack) {
    stack->top = -1;
}

void push(Stack *stack, char item) {
    if (stack->top < MAX_SIZE - 1) {
        stack->data[++(stack->top)] = item;
    } else {
        printf("Stack overflow\n");
        exit(1);
    }
}

char pop(Stack *stack) {
    if (stack->top >= 0) {
        return stack->data[(stack->top)--];
    } else {
        printf("Stack underflow\n");
        exit(1);
    }
}

int main() {
    Stack stack;
    initialize(&stack);

    char line[100];
    int line_num = 0;

    while (fgets(line, sizeof(line), stdin)) {
        line_num++;

        char *token = strtok(line, " ");
        while (token != NULL) {
            if (token[0] == '<') {
                if (token[1] == '/') {
                    if (stack.top == -1) {
                        printf("Error at line %d: Closing tag without corresponding opening tag\n", line_num);
                        return 0;
                    }
                    char open_tag = pop(&stack);
                    char close_tag[strlen(token) - 3];
                    strncpy(close_tag, token + 2, strlen(token) - 3);
                    close_tag[strlen(token) - 3] = '\0';
                    if (strcmp(open_tag, close_tag) != 0) {
                        printf("Error at line %d: Mismatched opening and closing tags\n", line_num);
                        return 0;
                    }
                } else {
                    push(&stack, &token[1]);
                }
            }
            token = strtok(NULL, " ");
        }
    }

    if (stack.top != -1) {
        printf("Error: Unclosed tags\n");
    } else {
        printf("No error\n");
    }

    return 0;
}
