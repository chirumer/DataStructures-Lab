// to find factorial of a number using recursion

#include <stdio.h>

long long int factorial(int x) {
    if (x == 0) {
        printf("factorial of 0 is 1\n");
        return 1;
    }
    printf("factorial of %d is %d * factorial(%d)\n", x, x, x-1);
    return x * factorial(x-1);
}

int main() {

    int num;
    printf("Enter a number: ");
    scanf("%d", &num);

    long long int num_factorial = factorial(num);
    printf("Factorial of the number: %lld\n", num_factorial);

    return 0;
}
