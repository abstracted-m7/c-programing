// easy process

#include <stdio.h>
int main()
{
    int num,fact=1;
    printf("Enter the number : ");
    scanf("%d",&num);
    if (num==0 || num==1)
    {
        return 1;
    }
    else
    {
        for (int i = 2; i <= num; i++)
    {
        fact=fact*i;
    }
    printf(" Factorial of %d is : %d ",num,fact);
    return 0;
    }
}




// using declaration
// #include <stdio.h>

// int factorial(int n);

// int main() {
//     int num;

//     // Input the number from the user
//     printf("Enter a non-negative integer: ");
//     scanf("%d", &num);

//     // Calculate and print the factorial
//     if (num < 0) {
//         printf("Factorial is not defined for negative numbers.\n");
//     } else {
//         int result = factorial(num);
//         printf("Factorial of %d is %d\n", num, result);
//     }

//     return 0;
// }

// int factorial(int n) {
//     if (n == 0 || n == 1) {
//         return 1;
//     } else {
//         return n * factorial(n - 1);
//     }
// }



