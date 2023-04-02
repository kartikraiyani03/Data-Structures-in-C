#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>

struct linkedlist
{
    int data;
    struct linkedlist *next;
};

struct linkedlist *head = NULL;

void CreateLinkedList()
{
    if (head == NULL)
    {

        int num;
        int n;

        printf("ENTER THE NUMBER OF NODES \n");
        scanf("%d", &n);

        if (n != 0)
        {
            struct linkedlist *node;
            struct linkedlist *temp;
            node = (struct linkedlist *)malloc(sizeof(struct linkedlist));
            head = node;
            temp = head;

            printf("ENTER THE NUMBER WHICH YOU WANT TO INSERT \n");
            scanf("%d", num);

            head->data = num;

            for (int i = 1; i < n; i++)
            {
                node = malloc(sizeof(struct linkedlist));
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

void printlist(struct linkedlist *ptr)
{

    printf("LIST IS..\n");

    while (ptr != NULL)
    {
        printf("%d-> ", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL \n\n");
}

struct linkedlist *insert(struct linkedlist *first, int val)
{

    struct linkedlist *ptr = (struct linkedlist *)malloc(sizeof(struct linkedlist));
    ptr->next = first;
    ptr->data = val;
    return ptr;
}

struct linkedlist *insertatEnd(struct linkedlist *first, int val)
{

    struct linkedlist *ptr = (struct linkedlist *)malloc(sizeof(struct linkedlist));
    struct linkedlist *p = first;
    ptr->data = val;

    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = NULL;

    return first;
}

struct linkedlist *insertatIndex(struct linkedlist *first, int val, int index)
{
    struct linkedlist *ptr = (struct linkedlist *)malloc(sizeof(struct linkedlist));
    struct linkedlist *p = first;

    int i = 0;
    while (i != index - 2)
    {
        p = p->next;
        i++;
    }
    ptr->next = p->next;
    p->next = ptr;
    ptr->data = val;

    return first;
}

struct linkedlist *insertAfterNode(struct linkedlist *first, int BeforeVal, int val)
{
    struct linkedlist *ptr = (struct linkedlist *)malloc(sizeof(struct linkedlist));
    struct linkedlist *p = first;

    while (p->data != BeforeVal)
    {
        p = p->next;
    }

    ptr->data = val;
    ptr->next = p->next;
    p->next = ptr;

    return first;
}

struct linkedlist *insertBeforeNode(struct linkedlist *first, int AfterVal, int val)
{
    struct linkedlist *ptr = (struct linkedlist *)malloc(sizeof(struct linkedlist));
    struct linkedlist *p = first;
    struct linkedlist *q = first->next;
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

struct linkedlist *delation(struct linkedlist *first)
{
    struct linkedlist *p = first;
    first = first->next;
    free(p);

    return first;
}

struct linkedlist *delationatEnd(struct linkedlist *first)
{
    struct linkedlist *p = first;
    struct linkedlist *q = p->next;

    while (q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }

    p->next = NULL;
    free(q);

    return first;
}

struct linkedlist *delationatIndex(struct linkedlist *first, int index)
{
    struct linkedlist *p = first;
    struct linkedlist *q = first->next;

    for (int i = 0; i < index - 2; i++)
    {
        p = p->next;
        q = q->next;
    }

    p->next = q->next;
    free(q);

    return first;
}

struct linkedlist *delationBeforeNode(struct linkedlist *first, int AfterVal)
{
    struct linkedlist *p = first;
    struct linkedlist *q = first->next;
    struct linkedlist *r = first->next->next;

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

struct linkedlist *delationAfterNode(struct linkedlist *first, int BeforeVal)
{
    struct linkedlist *p = first;
    struct linkedlist *q = first->next;

    while (p->data != BeforeVal)
    {
        p = p->next;
        q = q->next;
    }
    p->next = q->next;
    free(q);

    return first;
}

struct linkedlist *search(struct linkedlist *first, int val)
{
    struct linkedlist *ptr = first;
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

struct linkedlist *freelist(struct linkedlist *first)
{
    struct linkedlist *temp;
    temp = first;
    if (temp != NULL)
    {
        temp = temp->next;
        free(temp);
        freelist(first);
    }
    temp = NULL;
    return temp;
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

    struct linkedlist *first;
    struct linkedlist *second;
    struct linkedlist *third;
    struct linkedlist *fourth;
    struct linkedlist *fifth;

    first = (struct linkedlist *)malloc(sizeof(struct linkedlist));
    second = (struct linkedlist *)malloc(sizeof(struct linkedlist));
    third = (struct linkedlist *)malloc(sizeof(struct linkedlist));
    fourth = (struct linkedlist *)malloc(sizeof(struct linkedlist));
    fifth = (struct linkedlist *)malloc(sizeof(struct linkedlist));

    first->data = 1;
    first->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = fourth;

    fourth->data = 4;
    fourth->next = fifth;

    fifth->data = 5;
    fifth->next = NULL;

    while (1)
    {

        printf("\n");
        printf("NAME : KARTIK RAIYANI   ENROLLMENT NO. : 210210116019   \n");
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
            first = insert(first, element);
            // system("cls");
            break;

        case 2:

            printf("ENTER THE ELEMENT WHICH YOU WANT TO INSERT \n");
            scanf("%d", &element);
            first = insertatEnd(first, element);
            system("cls");
            break;

        case 3:
            printf("ENTER THE INDEX AT WHICH YOU WANT TO INSERT \n");
            scanf("%d", &index);
            printf("ENTER THE ELEMENT WHICH YOU WANT TO INSERT \n");
            scanf("%d", &element);
            first = insertatIndex(first, element, index);
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
            // system("cls");
            break;

        case 7:
            first = delationatEnd(first);
            system("cls");
            break;

        case 8:
            // printf("ENTER THE INDEX AT WHICH YOU WANT TO DELATION \n");
            // scanf("%d", INDEX);
            first = delationatIndex(first, 3);
            system("cls");
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