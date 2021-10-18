// to demonstrate implementing a stack using an array

// header files
#include <stdio.h>
#include <stdbool.h>

// constants
#define STACK_LIMIT 1000

struct Stack {
    int elements[STACK_LIMIT];
    int size, last_index;
};

void stack_init(struct Stack* stack, int size) {
    stack->last_index = -1;
    stack->size = size;
}

void stack_display(struct Stack stack) {
    printf("Stack Data:\n");
    printf("size: %d\n", stack.size);
    printf("elements:");
    for (int i = 0; i <= stack.last_index; ++i) {
        printf(" %d", stack.elements[i]);
    }
    printf("\n");
}

bool stack_is_full(struct Stack stack) {
    return stack.last_index == stack.size - 1;
}

bool stack_is_empty(struct Stack stack) {
    return stack.last_index == -1;
}

void stack_push(struct Stack* stack, int item) {
    if (stack_is_full(*stack)) {
        printf("stack overflow\n");
        return;
    }
    stack->elements[++stack->last_index] = item;
}

void stack_pop(struct Stack* stack, int* element) {
    if (stack_is_empty(*stack)) {
        printf("stack underflow\n");
        return;
    }
    *element = stack->elements[stack->last_index--];
}

int main() {
    // data
    struct Stack stack;
    
    int size;
    printf("Enter size of the stack: ");
    scanf("%d", &size);
    
    stack_init(&stack, size);
    
    // menu
    printf("(1) push\n(2) pop\n(EOF) exit\n");
    char input;
    while ((input = getchar()) != EOF) {
        
        if (input == '1') {
            
            int element;
            printf("Enter element to be pushed: ");
            scanf("%d", &element);
            
            stack_push(&stack, element);
            stack_display(stack);
        }
        if (input == '2') {

            int element;
            stack_pop(&stack, &element);
            stack_display(stack);
        }
        
        printf("(1) push\n(2) pop\n(EOF) exit\n");
    }
    
    return 0;
}
