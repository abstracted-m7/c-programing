#include <stdio.h>

int main() {
    int n, i;
    int fib1 = 0, fib2 = 1, nextTerm = fib1+fib2;

    // Input the number of terms from the user
    printf("Enter the number of terms: ");
    scanf("%d", &n);

    // Print the first two terms of the Fibonacci series
    // %llu use for unsigned long long int value

    printf("Fibonacci Series: %d, %d", fib1, fib2);

    // Generate the series
    for (i = 3; i <= n; ++i) {
        nextTerm = fib1 + fib2;
        printf(", %d", nextTerm);
        fib1 = fib2;
        fib2 = nextTerm;
    }

    printf("\n");

    return 0;
}
