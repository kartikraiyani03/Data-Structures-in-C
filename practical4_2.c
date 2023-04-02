#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>

struct Circularlist
{
    int data;
    struct Circularlist *next;
};

struct Circularlist *head = NULL;

void CreateCircularlist()
{
    if (head == NULL)
    {

        int num;
        int n;

        printf("ENTER THE NUMBER OF NODES \n");
        scanf("%d", &n);

        if (n != 0)
        {
            struct Circularlist *node;
            struct Circularlist *temp;
            node = (struct Circularlist *)malloc(sizeof(struct Circularlist));
            head = node;
            temp = head;

            printf("ENTER THE NUMBER WHICH YOU WANT TO INSERT \n");
            scanf("%d", num);

            head->data = num;

            for (int i = 1; i < n; i++)
            {
                node = malloc(sizeof(struct Circularlist));
                temp->next = node;
                printf("ENTER THE NUMBER WHICH YOU WANT TO INSERT \n");
                scanf("%d", &num);
                node->data = num;
                temp = temp->next;
            }

            printf("LIST CREATED SUCCESFULLLY !! \n");
        }
    }
    else
    {
        printf("LIST IS ALREADY EXIST \n");
    }
}

void printlist(struct Circularlist *first)
{
    struct Circularlist *p = first;
    int flag = 0;

    printf("LIST IS..\n");

    if (first == NULL)
    {
        printf("LIST IS EMPTY \n \n");
    }
    else
    {

        while (p->next != first)
        {
            printf("%d-> ", p->data);
            p = p->next;
        }
    }
    printf("FIRST \n \n");
}

struct Circularlist *insertAtFirst(struct Circularlist *first, int val)
{
    struct Circularlist *ptr = (struct Circularlist *)malloc(sizeof(struct Circularlist));
    struct Circularlist *p = first->next;

    ptr->data = val;

    while (p->next != first)
    {
        p = p->next;
    }

    p->next = ptr;
    ptr->next = first;
    first = ptr;
    return first;
}

struct Circularlist *insertAtEnd(struct Circularlist *first, int val)
{

    struct Circularlist *ptr = (struct Circularlist *)malloc(sizeof(struct Circularlist));
    struct Circularlist *p = first;
    ptr->data = val;

    while (p->next != first)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = first;

    return first;
}

struct Circularlist *insertAtIndex(struct Circularlist *first, int val, int index)
{
    struct Circularlist *ptr = (struct Circularlist *)malloc(sizeof(struct Circularlist));
    struct Circularlist *p = first;

    int i = 1;
    while (i != index - 1)
    {
        p = p->next;
        i++;
    }
    ptr->next = p->next;
    p->next = ptr;
    ptr->data = val;

    return first;
}

struct Circularlist *insertAfterNode(struct Circularlist *first, int BeforeVal, int val)
{
    struct Circularlist *ptr = (struct Circularlist *)malloc(sizeof(struct Circularlist));
    struct Circularlist *p = first;

    while (p->data != BeforeVal)
    {
        p = p->next;
    }

    ptr->data = val;
    ptr->next = p->next;
    p->next = ptr;

    return first;
}

struct Circularlist *insertBeforeNode(struct Circularlist *first, int AfterVal, int val)
{
    struct Circularlist *ptr = (struct Circularlist *)malloc(sizeof(struct Circularlist));
    struct Circularlist *p = first;
    struct Circularlist *q = first->next;
    while (q->data != AfterVal)
    {
        p = p->next;
        q = q->next;
    }
    ptr->data = val;
    ptr->next = q;
    p->next = ptr;

    return first;
}

struct Circularlist *delation(struct Circularlist *first)
{
    struct Circularlist *p = first;
    struct Circularlist *q = first->next;

    first = first->next;
    free(p);

    while (q->next != first)
    {
        q = q->next;
    }
    q->next = first;

    return first;
}

struct Circularlist *delationatEnd(struct Circularlist *first)
{
    struct Circularlist *p = first;
    struct Circularlist *q = first->next;

    while (q->next != first)
    {
        p = p->next;
        q = q->next;
    }

    p->next = first;
    free(q);

    return first;
}

struct Circularlist *delationatIndex(struct Circularlist *first, int index)
{
    struct Circularlist *p = first;
    struct Circularlist *q = first->next;

    for (int i = 0; i < index - 2; i++)
    {
        p = p->next;
        q = q->next;
    }

    p->next = q->next;
    free(q);

    return first;
}

struct Circularlist *delationBeforeNode(struct Circularlist *first, int AfterVal)
{
    struct Circularlist *p = first;
    struct Circularlist *q = first->next;
    struct Circularlist *r = first->next->next;

    while (r->data != AfterVal)
    {
        p = p->next;
        q = q->next;
        r = r->next;
    }
    p->next = q->next;
    free(q);
    return first;
}

struct Circularlist *delationAfterNode(struct Circularlist *first, int BeforeVal)
{
    struct Circularlist *p = first;
    struct Circularlist *q = first->next;

    while (p->data != BeforeVal)
    {
        p = p->next;
        q = q->next;
    }
    p->next = q->next;
    free(q);

    return first;
}

struct Circularlist *search(struct Circularlist *first, int val)
{
    struct Circularlist *ptr = first;
    int i = 1;

    while (ptr->data != val)
    {
        ptr = ptr->next;
        i++;
    }

    printf("The data of the Node is %d \n", ptr->data);
    printf("The Index of the Node is %d", i);

    if (ptr->data != val)
    {
        printf("VALUE NOT FOUND \n\n");
    }
}

int main()

{

    int index;
    int value;
    int ch;
    int element;
    int BeforeVal;
    int AfterVal;
    int INDEX;

    struct Circularlist *first;
    struct Circularlist *second;
    struct Circularlist *third;
    struct Circularlist *fourth;
    struct Circularlist *fifth;

    first = (struct Circularlist *)malloc(sizeof(struct Circularlist));
    second = (struct Circularlist *)malloc(sizeof(struct Circularlist));
    third = (struct Circularlist *)malloc(sizeof(struct Circularlist));
    fourth = (struct Circularlist *)malloc(sizeof(struct Circularlist));
    fifth = (struct Circularlist *)malloc(sizeof(struct Circularlist));

    first->data = 1;
    first->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = fourth;

    fourth->data = 4;
    fourth->next = fifth;

    fifth->data = 5;
    fifth->next = first;

    while (1)
    {

        printf("\n");
        printf("NAME : KARTIK RAIYANI   ENROLLMENT NO. : 210210116019 \n");
        printf("\n");

        printf("1.  INSERT THE ELEMENT AT BEGINING \n");
        printf("2.  INSERT THE ELEMENT AT THE END \n");
        printf("3.  INSERT AT INDEX \n");
        printf("4.  INSERT AFTER A NODE \n");
        printf("5.  INSERT BEFORE A NODE \n");
        printf("6.  DELATION AT BEGINING \n");
        printf("7.  DELATION AT END \n");
        printf("8.  DELATION AT INDEX \n");
        printf("9.  DELATION BEFORE NODE \n");
        printf("10. DELATION AFTER NODE \n");
        printf("11. SEARCH THE NODE \n");
        printf("12. DISPLAY \n");
        printf("13. EXIT \n \n");

        printf("ENTER YOUR CHOICE.. \n");
        scanf("%d", &ch);

        switch (ch)

        {
        case 1:
            printf("ENTER THE ELEMENT WHICH YOU WANT TO INSERT \n");
            scanf("%d", &element);
            first = insertAtFirst(first, element);
            // system("cls");
            break;

        case 2:

            printf("ENTER THE ELEMENT WHICH YOU WANT TO INSERT \n");
            scanf("%d", &element);
            first = insertAtEnd(first, element);
            system("cls");
            break;

        case 3:
            printf("ENTER THE INDEX AT WHICH YOU WANT TO INSERT \n");
            scanf("%d", &index);
            printf("ENTER THE ELEMENT WHICH YOU WANT TO INSERT \n");
            scanf("%d", &element);
            first = insertAtIndex(first, element, index);
            system("cls");
            break;

        case 4:
            printf("ENTER THE VALUE AFTER YOUT WANT TO INSERT \n");
            scanf("%d", &BeforeVal);
            printf("ENTER THE ELEMENT WHICH YOU WANT TO INSERT AFTER NODE \n");
            scanf("%d", &element);
            first = insertAfterNode(first, BeforeVal, element);
            system("cls");
            break;

        case 5:
            printf("ENTER THE VALUE BEFORE YOUT WANT TO INSERT \n");
            scanf("%d", &AfterVal);
            printf("ENTER THE ELEMENT WHICH YOU WANT TO INSERT BEFORE NODE \n");
            scanf("%d", &element);
            first = insertBeforeNode(first, AfterVal, element);
            system("cls");
            break;

        case 6:
            first = delation(first);
            system("cls");
            break;

        case 7:
            first = delationatEnd(first);
            // system("cls");
            break;

        case 8:
            // printf("ENTER THE INDEX AT WHICH YOU WANT TO DELATION \n");
            // scanf("%d", INDEX);
            first = delationatIndex(first, 3);
            // system("cls");
            break;

        case 9:
            printf("ENTER THE VALUE BEFORE YOU WANT TO DELETE \n");
            scanf("%d", &AfterVal);
            first = delationBeforeNode(first, AfterVal);
            system("cls");
            break;

        case 10:
            printf("ENTER THE VALUE AFTER YOU WANT TO DELETE \n");
            scanf("%d", &BeforeVal);
            first = delationAfterNode(first, BeforeVal);
            system("cls");
            break;

        case 11:
            // printf("ENTER THE VALUE WHICH YOU WANT TO FIND \n");
            // scanf("%d", value);
            search(first, 3);
            break;

        case 12:
            // system("cls");
            printlist(first);
            printf("PRESS ANY KEY TO CONTINUE \n");
            getch();
            system("cls");
            break;

        case 13:
            exit(1);

        default:
            printf("invalid choicen \n");
        }
    }

    return 0;
}