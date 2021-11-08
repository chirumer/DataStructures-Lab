#include <stdio.h>

void towers(int num, char from, char to, char aux) {
    if (num == 1) {
        printf("Move disk 1 from %c to %c\n", from, to);
        return;
    }
    towers(num-1, from, aux, to);
    printf("Move disk %d from %c to %c\n", num, from, to);
    towers(num-1, aux, to, from);
}

int main() {
    int num;
    printf("Enter number of disks: ");
    scanf("%d", &num);

    printf("Sequence of moves:\n");
    towers(num, 'A', 'C', 'B');

    return 0;
}
