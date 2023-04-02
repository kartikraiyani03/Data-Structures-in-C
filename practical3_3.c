#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

struct DEqueue
{
    int size;
    int rear;
    int front;
    int *arr;
};   

int isEmpty(struct DEqueue *dq)
{
    if (dq->front == dq->rear && dq->front != -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(struct DEqueue *dq)
{
    if (dq->rear == dq->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void enqueueatR(struct DEqueue *dq, int val)
{
    if (isFull(dq))
    {
        printf("can't able to enqueue \n");
    }
    else
    {
        dq->rear++;
        dq->arr[dq->rear] = val;
    }
}

void enqueueatF(struct DEqueue *dq, int val)
{
    if (isFull(dq))
    {
        printf("can't able to enqueue \n");
    } 
    else
    {
        dq->arr[dq->front] = val;
        dq->front--;
    }
}

int dequeueatF(struct DEqueue *dq)
{
    if (isEmpty(dq))
    {
        return 1;
    }
    else
    {
        dq->front++;
        return dq->arr[dq->front];
    }
}

int dequeueatR(struct DEqueue *dq)
{
    if (isEmpty(dq))
    {
        return 1;
    }
    else
    {
        dq->rear--;
        return dq->arr[dq->rear];
    }
}

void display(struct DEqueue *dq)
{
    printf("ELEMENTS ARE... \n \n");

    if (dq->rear == dq->front)
    {
        printf(" DOUBLE ENDED QUEUE IS EMPTY \n ");
    }
    else
    {
        for (int i = dq->rear; i > dq->front; i--)
        {
            printf("%d \t", dq->arr[i]);
        }
        printf("\n");
    }
}

int main()
{
    struct DEqueue *dq;

    dq->size = 5;
    dq->rear = 0;
    dq->front = 0;

    dq->arr = (int *)malloc(sizeof(int) * dq->size);

    int ch;
    int ele;
    int choice1;
    int choice2;

    system("cls");

    printf("\n");
    printf("NAME : KARTIK RAIYANI   ENROLLMENT NO. : 210210116019   \n");
    printf("\n");

    while (1)
    {

        printf("1. ENQUEUE AT FRONT \n");
        printf("2. ENQUEUE AT REAR  \n");
        printf("3. DEQUEUE AT FRONT \n");
        printf("4. DEQUEUE AT REAR \n");
        printf("5. DISPLAY \n");
        printf("6. EXIT \n \n");

        printf("ENTER YOUR CHOICE \n \n");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("ENTER THE ELEMENT YOU WANT TO ENQUEUE AT FRONT \n");
            scanf("%d", &ele);
            enqueueatF(&dq, ele);
            system("cls");

        case 2:
            printf("ENTER THE ELEMENT YOU WANT TO ENQUEUE AT REAR \n");
            scanf("%d", &ele);
            enqueueatR(&dq, ele);
            printf("hello");
            system("cls");

        case 3:
            dequeueatF(&dq);
            system("cls");

        case 4:
            dequeueatR(&dq);
            system("cls");

        case 5:
            display(&dq);
            break;

        case 6:
            exit(1);

        default:
            printf("invalid choice \n");
            break;
        }
    }

    return 0;
}