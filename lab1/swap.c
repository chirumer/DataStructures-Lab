#include <stdio.h>

void swap(int* x, int* y) {
    
    int temp = *x;
    *x = *y;
    *y = temp;
}

int main() {
    
    int num1, num2;
    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);
    
    printf("Numbers before swapping: %d %d\n", num1, num2);
    swap(&num1, &num2);
    printf("Numbers after swapping: %d %d\n", num1, num2);
    
    return 0;
}
