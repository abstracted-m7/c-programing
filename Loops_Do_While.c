// // Do_While loops type
// // C program to illustrate
// // do-while loop
// #include <stdio.h>

// // Driver code
// int main()
// {
// // Initialization expression
// int i = 2;

// do
// {
// 	// loop body
// 	printf( "Hello World\n");

// 	// Update expression
// 	i++;
	
// 	// Test expression
// } while (i < 1);

// return 0;
// }


// // 2.  Program to add numbers until the user enters zero
// // Gives input until the input value is zero(0)
// #include <stdio.h>
// int main() {
//   double number, sum = 0;

//   // the body of the loop is executed at least once
//   do {
//     printf("Enter a number: ");
//     scanf("%lf", &number);
//     sum += number;
//   }
//   while(number != 0.0);

//   printf("Sum = %.2lf",sum);

//   return 0;
// }



// // 3. preodic table 
// #include<stdio.h>  
// void main ()  
// {  
//    int n=2,i,choice;  
//    do  
//    {  
//        i=1;  
//        while(i<=10)  
//        {  
//            printf("%d X %d = %d\n",n,i,n*i);  
//            i++;  
//        }  
//        printf("do you want to continue with the table of %d , enter any non-zero value to continue.",n+1);  
//        scanf("%d",&choice);  
//     if(choice == 0)  
//        {  
//            break;  
//        }  
//        n++;  
//    }while(1);  
// }  