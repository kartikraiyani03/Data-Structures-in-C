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

void SelectionSort(int a[], int n)
{
    int min, j, temp;
    for (int i = 0; i < n - 1; i++)
    {
        min = i;
        for (j = i + 1; j < n; j++)
        {
            if (a[j] < a[min])
            {
                min = j;
            }
        }
        temp = a[i];
        a[i] = a[min];
        a[min] = temp;
    }
}

int main()
{
    printf("\n");
    printf("NAME : KARTIK RAIYANI \nENROLLMENT NO. : 210210116019 \n");
    printf("\n");

    int n = 7;
    int a[] = {101, 45,98, 34, 12, 1, 0};

    Array(a, n);
    SelectionSort(a, n);
    printf("\n");
    printf("-------\n");
    printf("AFTER SORTING \n");
    printf("-------\n");
    printf("\n");
    Array(a, n);

    return 0;
}