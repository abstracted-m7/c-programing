#include <stdio.h>

int main() {
    int num1, num2, num3;

    // Input three numbers from the user
    printf("Enter first integer number : ");
    scanf("%d",&num1);
    printf("Enter Second integer number : ");
    scanf("%d",&num2);
    printf("Enter third integer number : ");
    scanf("%d",&num3);

    // Compare the numbers to find the greatest
    if (num1 >= num2 && num1 >= num3) {
        printf("%d is the greatest number.\n", num1);
    } else if (num2 >= num1 && num2 >= num3) {
        printf("%d is the greatest number.\n", num2);
    } else {
        printf("%d is the greatest number.\n", num3);
    }

    return 0;
}
