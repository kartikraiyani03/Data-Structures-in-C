#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>

void Array(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
}

void InsertionSort(int a[], int n)
{
    int element, j;

    for (int i = 1; i <= n - 1; i++)
    {
        element = a[i];
        j = i - 1;
        while (j >= 0 && element < a[j])
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = element;
    }
}

int main()
{
    printf("\n");
    printf("NAME : KARTIK RAIYANI  \nENROLLMENT NO. : 210210116019 \n");
    printf("\n");

    int n = 7;
    int a[] = {66, 78, 97, 12, 10, 01, 03};
    Array(a, n);
    InsertionSort(a, n);
     printf("\n");
     printf("------\n");
    printf("AFTER SORTING \n ");
     printf("------\n");
    printf("\n");
    Array(a, n);

    return 0;
}