/*
Program to evaluate a Postfix expression with single digit operands
*/

// headerfiles
#include <stdio.h> // printf(), scanf()
#include <ctype.h> // isdigit()

// constants
#define MAX_ARR 100
#define MAX_STR 100

int stack[MAX_ARR];
int top = -1;

void push(int value) {
    stack[++top] = value;
}

int pop() {
    return stack[top--];
}

int main() {
    
    char expression[MAX_STR];
    printf("Enter the expression: ");
    scanf("%s", expression);
    
    char* ptr = expression;
    while (*ptr != '\0') {
        if (isdigit(*ptr)) {
            push(*ptr - '0');
            ++ptr;
            continue;
        }
        
        int num1 = pop();
        int num2 = pop();
        int result;
        switch(*ptr) {
            case '+':
                result = num2 + num1;
                break;
            case '-':
                result = num2 - num1;
                break;
            case '*':
                result = num2 * num1;
                break;
            case '/':
                result = num2 / num1;
                break;
            default:
                printf("Unrecognized symbol: %c", *ptr);
                return -1;
        }
        push(result);
        ++ptr;
    }
    printf("Result of the expression: %d\n", pop());
    return 0;
}
