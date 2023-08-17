// pi(r*r)

#include <stdio.h>
#include <math.h>
int main()
{
    float radius,pi,area;
    printf("Enter the value of radius : ");
    scanf("%f",&radius);
    pi = 3.14;
    area =pi*(radius*radius);
    printf("Arae of a circle : %f",area);
}