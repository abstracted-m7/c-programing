// // 1. preodic table using For loop
// #include <stdio.h>  
// int main()  
// {  
//    int n;// variable declaration  
//    printf("Enter the value of n :");
//    scanf("%d",&n);
//    // Displaying the n tables.  
//    for(int i=1;i<=n;i++)  // outer loop  
//    {  
//        for(int j=1;j<=10;j++)  // inner loop  
//        {  
//            printf("%d\t",(i*j)); // printing the value.  
//        }  
//        printf("\n");  
//    }
// }

// // 2. Numbers print in metrix form m*n using while loop
// #include <stdio.h>  
// int main()  
// {  
//    int rows,columns,k=1;    
//    printf("Enter the number of rows :");   
//    scanf("%d",&rows);  
//    printf("\nEnter the number of columns :"); 
//    scanf("%d",&columns); 
//     //2d array declaration 
//     int a[rows][columns];   
//     int i=1;  
//     // outer loop  
//    while(i<=rows) 
//    {  
//        int j=1;  
//        // inner loop 
//       while(j<=columns)   
//        {  
//             // printing the value of k. 
//            printf("%d\t",k);  
//            // increment counter   
//            k++;   
//            j++;  
//        }  
//        i++;  
//        printf("\n");  
//    }  
// }  


// // 3.printing the pattern 
// //      ******** 
// //      ******** 
// //      ******** 
// //      ******** 
// #include <stdio.h>  
// int main()  
// {  
 
// int i=1;  
// // outer loop  
// do           
// {  
//     int j=1; 
//     // inner loop   
//     do       
//    {  
//       printf("*");  
//       j++;  
//    }while(j<=8);  
//     printf("\n");  
//     i++;  
//      }while(i<=4);  
// }  


