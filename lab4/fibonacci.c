// to find the nth fibonacci series number using recursion

#include <stdio.h>

int fibonacci(int x) {
    if (x == 1 || x == 2) {
        printf("%dth fibonacci number is 1\n", x);
        return 1;
    }
    printf("%dth fibonacci number is fibonacci(%d) + fibonacci(%d)\n", x, x-1, x-2);
    return fibonacci(x-1) + fibonacci(x-2);
}

int main() {

    int num;
    printf("Enter a number: ");
    scanf("%d", &num);

    int num_fibonacci = fibonacci(num);
    printf("(%d)th fibonacci number is: %d\n", num, num_fibonacci);

    return 0;
}
