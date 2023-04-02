#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>

int main()
{
    printf("\n");
    printf("NAME : KARTIK RAIYANI  \nENROLLMENT NO. : 210210116019 \n");
    printf("\n");

    int i, j;
    int weight[10][10];
    int x[10];
    int path[10][10];
    int node;
    int vnode;
    int pathnode;
    int row, col, min, index;
    index = 1;

    printf("Enter the Number Of Nodes \n");
    scanf("%d", &node);

    printf("Enter the Matrix \n\n");
    for (i = 1; i <= node; i++)
    {
        for (j = 1; j <= node; j++)
        {
            scanf("%d", &weight[i][j]);
        }
    }

    printf("Enter the visited node \n");
    scanf("%d\n", &vnode);
    printf("Enter the PAth of selected Node \n");
    scanf("%d", &pathnode);

    for (i = 1; i <= pathnode; i++)
    {
        for (j = 1; j <= node; j++)
        {
            scanf("%d", &path[i][j]);
        }
    }

    for (i = 1; i <= pathnode; i++)
    {
        x[i] = 0;
        row = 1;
        for (j = 1; j < node; j++)
        {
            if (row != vnode)
            {
                col = path[i][j + 1];
                x[i] = x[i] + weight[row][col];
            }
            row = col;
        }
    }

    min = x[i];
    for (i = 1; i <= pathnode; i++)
    {
        if (x[i] <= min)
        {
            min = x[i];
            index = i;
        }
    }

    printf("The Minimum Distace is %d\n\n", min);
    printf("Minimum Distace Path is.....\n");
    for (i = 1; i <= node; i++)
    {
        if (path[index][i] != 0)
        {
            printf("%d >>> ", path[index][i]);
        }
    }

    return 0;
}