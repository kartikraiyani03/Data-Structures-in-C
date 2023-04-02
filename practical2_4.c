#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>

struct stack
{
    int top;
    int size;
    char *arr;
};

int top(struct stack *st)
{
    return st->arr[st->top];
}

int isEmpty(struct stack *st)
{
    if (st->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(struct stack *st)
{
    if (st->top == st->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(struct stack *st, char val)
{
    if (isFull(st))
    {
        printf("can not able to push");
    }
    else
    {
        st->top++;
        st->arr[st->top] = val;
    }
}

char pop(struct stack *st)
{

    if (isEmpty(st))
    {
        printf("Can not able to pop \n");
        return -1;
    }

    else
    {
        st->top--;
        return st->arr[st->top];
    }
}

int isOprator(char op)
{
    if (op == '+' || op == '-' || op == '*' || op == '/')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int precedence(char op)
{
    if (op == '*' || op == '/')
    {
        return 3;
    }
    else if (op == '+' || op == '-')
    {
        return 2;
    }
    else
    {
        return 0;
    }
}

char *infixtopostfix(char *infix)
{
    struct stack *st = (struct stack *)malloc(sizeof(struct stack));
    st->size = 100;
    st->top = -1;
    st->arr = (char *)malloc(sizeof(char) * st->size);

    char *postfix = (char *)malloc((strlen(infix) + 1) * sizeof(char));
    int i, j;
    i = 0;
    j = 0;

    while (infix[i] != '\0')
    {
        if (!isOprator(infix[i]))
        {
            postfix[j] = infix[i];
            i++;
            j++;
        }
        else
        {
            if (precedence(infix[i]) > precedence(top(st)))
            {
                push(st, infix[i]);
                i++;
            }
            else
            {
                postfix[j] = pop(st);
                j++;
            }
        }
    }

    while (!isEmpty(st))
    {
        postfix[j] = pop(st);
        j++;
    }
    postfix[j] = '\0';
    return postfix;
}

int main()
{
    printf("\n");
    printf("NAME : KARTIK RAIYANI   ENROLLMENT NO. : 210210116019   \n");
    printf("\n");

    char *infix = "a+b-c*d/e";
    // printf("ENTER THE INFIX \n");
    // scanf("%s", infix);

    printf("THE POSTFIX IS %s", infixtopostfix(infix));

    return 0;
}