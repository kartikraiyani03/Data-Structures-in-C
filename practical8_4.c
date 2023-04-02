#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>

int linearSearch(int a[], int n, int val)
{
    for (int i = 0; i < n; i++)
    {
        if (a[i] == val)
        {
            printf("ELEMENT IS IN THE ARRAY\n");
            return a[i];
        }
    }
}

int main()
{
    printf("\n");
    printf("NAME : KAERTIK RAIYANI   \nENROLLMENT NO. : 210210116019 \n");
    printf("\n");

    int Value;
    int size = 8;
    int a[] = {101, 45,98, 34, 12, 1, 0};
    // printf("\n");
    // printf("ENTER THE VALUE WHICH YOU WANT TO FIND \n \n");
    // scanf("%d", Value);
    printf("\n");
    printf("%d", linearSearch(a, 8, 0));

    return 0;
}