#include <stdio.h>

int main() {
    int num1, num2, num3;
    float average;

    // Input three numbers from the user
    printf("Enter first integer number : ");
    scanf("%d",&num1);
    printf("Enter Second integer number : ");
    scanf("%d",&num2);
    printf("Enter third integer number : ");
    scanf("%d",&num3);

    // Calculate the average
    average = (float)(num1 + num2 + num3) / 3;

    // Print the average
    // note : %.2f use for two decimal value.
    printf("Average of %d, %d, and %d is %.2f\n", num1, num2, num3, average);

    return 0;
}


