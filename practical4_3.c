#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>

struct Doublylist
{
    int data;
    struct Doublylist *next;
    struct Doublylist *prev;
};

struct Doublylist *head = NULL;

void CreateDoublylist()
{
    if (head == NULL)
    {

        int num;
        int n;

        printf("ENTER THE NUMBER OF NODES \n");
        scanf("%d", &n);

        if (n != 0)
        {
            struct Doublylist *node;
            struct Doublylist *temp;
            node = (struct Doublylist *)malloc(sizeof(struct Doublylist));
            head = node;
            temp = head;

            printf("ENTER THE NUMBER WHICH YOU WANT TO INSERT \n");
            scanf("%d", num);

            head->data = num;

            for (int i = 1; i < n; i++)
            {
                node = malloc(sizeof(struct Doublylist));
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

void printlist(struct Doublylist *ptr)
{
   
    printf("LIST IS..\n \n \n");
    printf("NULL <-> ");
    while (ptr != NULL)
    {
        printf("%d <-> ", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL \n \n \n");
}

struct Doublylist *insert(struct Doublylist *first, int val)
{

    struct Doublylist *ptr = (struct Doublylist *)malloc(sizeof(struct Doublylist));
    ptr->next = first;
    ptr->data = val;
    ptr->prev = NULL;
    return ptr;
}

struct Doublylist *insertatEnd(struct Doublylist *first, int val)
{

    struct Doublylist *ptr = (struct Doublylist *)malloc(sizeof(struct Doublylist));
    struct Doublylist *p = first;
    ptr->data = val;

    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = NULL;
    ptr->prev = p;

    return first;
}

struct Doublylist *insertatIndex(struct Doublylist *first, int val, int index)
{
    struct Doublylist *ptr = (struct Doublylist *)malloc(sizeof(struct Doublylist));
    struct Doublylist *p = first;

    int i = 0;
    while (i != index - 2)
    {
        p = p->next;
        i++;
    }
    ptr->next = p->next;
    p->next = ptr;
    ptr->data = val;
    ptr->prev = p;

    return first;
}

struct Doublylist *insertAfterNode(struct Doublylist *first, int BeforeVal, int val)
{
    struct Doublylist *ptr = (struct Doublylist *)malloc(sizeof(struct Doublylist));
    struct Doublylist *p = first;

    while (p->data != BeforeVal)
    {
        p = p->next;
    }

    ptr->data = val;
    ptr->next = p->next;
    p->next = ptr;
    ptr->prev = p;
    // ptr->prev->data = BeforeVal;

    return first;
}

struct Doublylist *insertBeforeNode(struct Doublylist *first, int AfterVal, int val)
{
    struct Doublylist *ptr = (struct Doublylist *)malloc(sizeof(struct Doublylist));
    struct Doublylist *p = first;
    struct Doublylist *q = first->next;

    while (q->data != AfterVal)
    {
        p = p->next;
        q = q->next;
    }
    ptr->data = val;
    ptr->next = q;
    p->next = ptr;
    ptr->prev = p;

    return first;
}

struct Doublylist *delation(struct Doublylist *first)
{
    struct Doublylist *ptr = first;
    first = first->next;
    free(ptr);

    return first;
}

struct Doublylist *delationatEnd(struct Doublylist *first)
{
    struct Doublylist *p = first;
    struct Doublylist *q = p->next;

    while (q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }

    p->next = NULL;
    free(q);

    return first;
}

struct Doublylist *delationatIndex(struct Doublylist *first, int index)
{
    struct Doublylist *p = first;
    struct Doublylist *q = first->next;

    for (int i = 0; i < index - 2; i++)
    {
        p = p->next;
        q = q->next;
    }

    p->next = q->next;
    q->next->prev = p;
    free(q);

    return first;
}

struct Doublylist *delationBeforeNode(struct Doublylist *first, int AfterVal)
{
    struct Doublylist *p = first;
    struct Doublylist *q = first->next;
    struct Doublylist *r = first->next->next;

    while (r->data != AfterVal)
    {
        p = p->next;
        q = q->next;
        r = r->next;
    }
    p->next = q->next;
    free(q);
    r->prev = p;
    return first;
}

struct Doublylist *delationAfterNode(struct Doublylist *first, int BeforeVal)
{
    struct Doublylist *p = first;
    struct Doublylist *q = first->next;

    while (p->data != BeforeVal)
    {
        p = p->next;
        q = q->next;
    }
    p->next = q->next;
    free(q);

    return first;
}

struct Doublylist *search(struct Doublylist *first, int val)
{
    struct Doublylist *ptr = first;
    int i = 0;

    while (ptr->data != val)
    {
        ptr = ptr->next;
        i++;
    }

    if (ptr->data == val)
    {
        printf("The data of the Node is %d \n", ptr->data);
        printf("The Index of the Node is %d", i);
    }
    else
    {
        printf("NODE NOT FOUND \n");
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

    struct Doublylist *first;
    struct Doublylist *second;
    struct Doublylist *third;
    struct Doublylist *fourth;
    struct Doublylist *fifth;

    first = (struct Doublylist *)malloc(sizeof(struct Doublylist));
    second = (struct Doublylist *)malloc(sizeof(struct Doublylist));
    third = (struct Doublylist *)malloc(sizeof(struct Doublylist));
    fourth = (struct Doublylist *)malloc(sizeof(struct Doublylist));
    fifth = (struct Doublylist *)malloc(sizeof(struct Doublylist));

    first->data = 1;
    first->next = second;
    first->prev = NULL;

    second->data = 2;
    second->next = third;
    second->prev = first;

    third->data = 3;
    third->next = fourth;
    third->prev = second;

    fourth->data = 4;
    fourth->next = fifth;
    fourth->prev = third;

    fifth->data = 5;
    fifth->next = NULL;
    fifth->prev = fourth;

    // printlist(first);

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
            printf("ENTER THE ELEMENT AFTER YOU WANT TO INSERT \n");
            scanf("%d", &BeforeVal);
            printf("ENTER THE ELEMENT WHICH YOU WANT TO INSERT AFTER NODE \n");
            scanf("%d", &element);
            first = insertAfterNode(first, BeforeVal, element);
            system("cls");
            break;

        case 5:
            printf("ENTER THE ELEMENT BEFORE YOU WANT TO INSERT \n");
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
            // scanf("%d", index);
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
            printf("ENTER THE ELEMENT AFTER YOU WANT TO INSERT \n");
            scanf("%d", &BeforeVal);
            first = delationAfterNode(first, BeforeVal);
            system("cls");
            break;

        case 11:
            // printf("ENTER THE VALUE WICH YOU WANT TO FIND \n");
            // scanf("%d", value);
            search(first, 3);

        case 12:
            // system("cls");
            printlist(first);
            printf("PRESS ANY KEY TO CONTINUE \n");
            getch();
            // system("cls");
            break;

        case 13:
            exit(1);

        default:

            printf("invalid choicen \n");
        }
    }

    return 0;
}