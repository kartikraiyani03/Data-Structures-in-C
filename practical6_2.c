#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>

int done[7] = {0, 0, 0, 0, 0, 0, 0};
int graph[7][7] = {
    {0, 0, 0, 0, 1, 1, 1},
    {1, 0, 0, 0, 0, 1, 1},
    {0, 0, 0, 1, 0, 1, 1},
    {0, 1, 0, 0, 0, 1, 1},
    {1, 1, 0, 0, 0, 0, 1},
    {0, 1, 1, 1, 0, 0, 1},
    {1, 1, 1, 0, 0, 1, 0},
};

void DFS(int i)
{
    int j;

    printf("DEPTH FIRST SEARCH IS..\n\n");
    printf("%d ", i);
    done[i] = 1;


    for (int j = 0; j < 7; j++)
    {
        if (graph[i][j] == 1 && !done[j])
        {
            DFS(j);
        }
    }
}

int main()
{
    printf("\n");
    printf("NAME :KARTIK RAIYANI  \nENROLLMENT NO. : 210210116019 \n");
    printf("\n");

    DFS(1);

    return 0;
}