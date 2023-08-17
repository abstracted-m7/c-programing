

#include <stdio.h>

int main() {
    int num;

    // Input the number from the user
    printf("Enter an integer: ");
    scanf("%d", &num);

    // Check if the number is odd or even
    if (num % 2 == 0) {
        printf("%d is an even number.\n", num);
    } else {
        printf("%d is an odd number.\n", num);
    }

    return 0;
}
