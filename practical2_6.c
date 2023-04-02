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
int Digit(int n)
{
    if (n == 1 || n == 2 || n == 3 || n == 4 || n == 5 || n == 6 || n == 7 || n == 8 || n == 9 || n == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

char *Evaluation(char *exp)
{
     struct stack *st = (struct stack*) malloc (sizeof(struct stack));
     
    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (Digit(exp[i]))
        {
            push(st, exp[i]);
        }
        else
        {
            int val1 = pop(st);
            int val2 = pop(st);

            switch (exp[i])
            {
            case '+':
                push(st, val1 + val2);
                break;
            case '-':
                push(st, val1 - val2);
                break;
            case '*':
                push(st, val1 * val2);
                break;
            case '/':
                push(st, val1 / val2);
                break;
            }
        }
    }
    return st->arr[st->top];
}

int display(struct stack *st)
{
    if (st->top >= -1)
    {
        printf("ELEMENTS \n \n");

        for (int i = st->top; i > -1; i--)
        {
            printf("%c \n", st->arr[i]);
        }
    }
    else
    {
        printf("EMPTY");
    }
}

int main()
{
  struct stack st;

    char exp[] = "342+-8+";
    printf("evaluation is %d", Evaluation(exp));
    display(&st);

    return 0;
}