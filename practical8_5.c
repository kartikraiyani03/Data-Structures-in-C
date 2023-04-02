#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>

int BinarySearch(int a[], int size, int val)
{
    int low, mid, high;
    low = 0;
    high = size - 1;

    while (low <= high)
    {
        mid = (low + high) / 2;
        if (a[mid] == val)
        {
            return mid;
        }
        if (a[mid] < val)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -2;
}

int main()
{
    printf("\n");
    printf("NAME : KARTIK RAIYANI   \nENROLLMENT NO. : 210210116019 \n");
    printf("\n");

    int Value;
    int element;
    int size = 6;
    
    int a[] = {66, 78, 97, 12, 10, 01, 03};

    printf("Enter the Element Which You Want to Find \n");
    scanf("%d",&element);
    printf("Element Found at Index %d",BinarySearch(a, 6, element));


    return 0;
}