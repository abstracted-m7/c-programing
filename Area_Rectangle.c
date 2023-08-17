// side_1*side_2

#include <stdio.h>
#include <math.h>
int main()
{
    float side_1,side_2,area;
    printf("Enter the value of side_1 : ");
    scanf("%f",&side_1);
    printf("Enter the value of side_2 : ");
    scanf("%f",&side_2);
    area = side_1*side_2;
    printf("Area of a rectangle : %f",area);
}