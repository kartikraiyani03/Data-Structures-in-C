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

void BubbleSort(int a[], int n)
{
    int temp;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

int main()
{
    printf("\n");
    printf("NAME : KARTIK RAIYNAI \nENROLLMENT NO. : 210210116019 \n");
    printf("\n");

    int n = 7;
    int a[] = {99, 76, 28, 33, 45, 12, 9};

    Array(a, n);
    BubbleSort(a, n);
    printf("\n");
    printf("---------\n");
    printf("ARRAY AFTER BUBBLE SORT \n ");
    printf("---------\n");
    printf("\n");
    Array(a, n);

    return 0;
}