//Tower of hanoi

#include <stdio.h>

void towerOfHanoi(int n, char A, char C, char B) {
    if (n == 1) {
        printf("Move from %c to %c\n", A, C);
        return;
    }
    towerOfHanoi(n - 1, A, B, C);
    printf("Move from %c to %c\n", A, C);
    towerOfHanoi(n - 1, B, C, A);
}

int main() {
    int numDisks = 3;  // Number of disks

    printf("Tower of Hanoi solution:\n");
    towerOfHanoi(numDisks, 'A', 'C', 'B');

    return 0;
}
