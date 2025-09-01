#include <stdio.h>

int intPow(int base, int exp) {
    int result = 1;
    for (int i = 0; i < exp; i++) {
        result *= base;
    }
    return result;
}

int main() {
    int n;
    printf("Enter the number: ");
    scanf("%d", &n);

    int test = n;
    int copy = n;
    int power = 0, rm, sum = 0;


    while (copy > 0) {
        copy = copy / 10;
        power++;
    }
    printf("Digits = %d\n", power);


    while (test > 0) {
        rm = test % 10;
        sum += intPow(rm, power);
        test = test / 10;
    }

    printf("Sum = %d\n", sum);

    if (sum == n) {
        printf("It is an Armstrong number\n");
    } else {
        printf("It is not an Armstrong number\n");
    }

    return 0;
}
