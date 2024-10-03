
#include<stdio.h>

int main()
{
    int arr[] = { 1, 4, 6, 7, 23, 46, 68, 78, 98, 135, 156, 676};
    int mid, size = sizeof(arr) / sizeof(arr[0]);
    int left = 0, right = size - 1, target = 135;
    int flag = 0;

    while (left <= right)
    {
        mid = left + ( right - left) /2;

        if (arr[mid] == target)
        {
            flag = 1;
            printf("\nThe element %d found at position %d.",arr[mid],mid+1);
            break;
        }
        
        else if (arr[mid] < target)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }

    }
    if ( flag == 0)
    {
       printf("The element %d is not found in the array..",target);
    }
    
    return 0;
}