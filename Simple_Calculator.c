// #include <stdio.h>

// int main() {
//     printf("Welcome to the Simple Calculator!\n");
    
//     while (1) {
//         printf("1. Add\n");
//         printf("2. Subtract\n");
//         printf("3. Multiply\n");
//         printf("4. Divide\n");
//         printf("5. Quit\n");
//         printf("Select an operation: ");
        
//         int operation;
//         scanf("%d", &operation);
        
//         if (operation >= 1 && operation <= 4) {
//             double num1, num2;
//             printf("Enter two numbers: ");
//             scanf("%lf %lf", &num1, &num2);
            
//             switch (operation) {
//                 case 1:
//                     printf("Result: %.2lf\n", num1 + num2);
//                     break;
//                 case 2:
//                     printf("Result: %.2lf\n", num1 - num2);
//                     break;
//                 case 3:
//                     printf("Result: %.2lf\n", num1 * num2);
//                     break;
//                 case 4:
//                     if (num2 != 0) {
//                         printf("Result: %.2lf\n", num1 / num2);
//                     } else {
//                         printf("Cannot divide by zero!\n");
//                     }
//                     break;
//             }
//         } else if (operation == 5) {
//             printf("Goodbye!\n");
//             return 0;
//         } else {
//             printf("Invalid operation.\n");
//         }
//     }
    
//     return 0;
// }


