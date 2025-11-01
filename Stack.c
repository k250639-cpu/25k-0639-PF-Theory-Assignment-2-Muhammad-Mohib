#include <stdio.h>

void push(int stack[], int *top, int maxSize) {
    int num;
    if (*top == maxSize - 1) {
        printf("Overflow! The stack is full.\n");
        return;
    }
    printf("Enter value to push: ");
    scanf("%d", &num);
    (*top)++;
    stack[*top] = num;
    printf("Value %d pushed onto stack.\n", num);
}

void pop(int stack[], int *top) {
    if (*top == -1) {
        printf("Underflow! The stack is empty.\n");
        return;
    }
    printf("Value %d popped from stack.\n", stack[*top]);
    (*top)--;
}

void peek(int stack[], int top) {
    if (top == -1) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Top element is: %d\n", stack[top]);
}

void display(int stack[], int top) {
    if (top == -1) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack elements:\n");
    for (int i = top; i >= 0; i--) {
        printf("%d\n", stack[i]);
    }
}

int main() {
    int stack[100];
    int top = -1;
    int maxSize = 100;
    int choice;

    do {
        printf("\n===== Stack Menu =====\n");
        printf("1. PUSH\n");
        printf("2. POP\n");
        printf("3. PEEK\n");
        printf("4. DISPLAY\n");
        printf("5. EXIT\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                push(stack, &top, maxSize);
                break;
            case 2:
                pop(stack, &top);
                break;
            case 3:
                peek(stack, top);
                break;
            case 4:
                display(stack, top);
                break;
            case 5:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}
