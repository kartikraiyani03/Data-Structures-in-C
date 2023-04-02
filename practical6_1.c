#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>

struct queue
{
    int size;
    int front;
    int rear;
    int *arr;
};

int isFull(struct queue *q)
{
    if (q->rear == q->size - 1 && q->front == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isEmpty(struct queue *q)
{
    if (q->rear == q->front || q->rear == -1)
    {
        return 1;
    }

    else
    {
        return 0;
    }
}

void enqueue(struct queue(*q), int val)
{
    if (isFull(q))
    {
        printf("queue is full \n");
    }
    else
    {
        q->rear++;
        q->arr[q->rear] = val;
    }
}

int dequeue(struct queue *q)
{
    if (isEmpty(q))
    {
        printf("queue is empty \n");
    }

    else
    {
        q->front++;
        return q->arr[q->front];
    }
}

void display(struct queue *q)
{
    printf("ELEMENTS ARE... \n");

    if (q->rear == q->front)
    {
        printf("QUEUE IS EMPTY \n ");
    }
    else
    {
        for (int i = q->rear; i > q->front; i--)
        {
            printf("%d \t", q->arr[i]);
        }
        printf("\n");
        printf("\n");
    }
}

int main()
{

    printf("\n");
    printf("NAME : KARTIK RAIYANI \nENROLLMENT NO. : 210210116019 \n");
    printf("\n");

    struct queue q;

    q.size = 5;
    q.front = -1;
    q.rear = -1;

    q.arr = (int *)malloc(sizeof(int) * q.size);

    int i = 5;

    int done[7] = {0, 0, 0, 0, 0, 0, 0};

    int graph[7][7] = {

        {0, 0, 1, 0, 0, 1, 0},
        {1, 0, 0, 0, 0, 1, 1},
        {0, 0, 0, 1, 0, 1, 1},
        {1, 0, 0, 0, 0, 1, 1},
        {1, 1, 0, 1, 0, 1, 0},
        {1, 1, 0, 0, 0, 0, 1},
        {1, 0, 1, 1, 0, 1, 0},
    };

    printf("BFS IS ...\n\n");
    printf("\n");
    printf("%d", i);          

    done[i] = 1;
    enqueue(&q, i);


    while (!isEmpty(&q))
    {
        int node = dequeue(&q);
        for (int j = 0; j < 7; j++)
        {
            if (graph[node][j] == 0 && done[j] == 0)
            {
                printf("%d ", j);
                done[j] = 1;
                enqueue(&q, j);
            }
        }
    }

    return 0;
}