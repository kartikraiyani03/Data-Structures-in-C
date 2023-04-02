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
    int a;

    if (isEmpty(st))
    {
        printf("Can not able to pop");
    }

    else
    {
        st->top--;
        return st->arr[st->top];
    }
}

int parenthisis(char *str)
{
     struct stack *st;

    st->size = 100;
    st->top = -1;
    st->arr = (char *)malloc(sizeof(char));

    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == '(')
        {
            push(st, '(');
        }

        else if (str[i] == ')')
        {
            if (isEmpty(st))
            {
                return 0;
            }
            else
            {
                pop(st);
            }
        }
    
    }
    if (isEmpty(st))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    struct stack *st;

    char *str = "(1*8(2/10))";

    if (parenthisis(str))
    {
        printf(" \n \n PARENTHISIS MATCHING !!!! \n \n");
    }

    else
    {
        printf("\n\nPARENTHISIS NOT MATCHING !!!! \n\n");
    }
    
    return 0;
}