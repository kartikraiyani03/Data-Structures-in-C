#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>

struct TBT
{
    int data;
    struct TBT *right;
    struct TBT *left;
    int rightT;
    int leftT;
};

void preorder(struct TBT *root)
{
    struct TBT *ptr;
    if (root == NULL)
    {
        printf("TREE IS EMPTY \n\n");
        return;
    }
    ptr = root;

    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        if (ptr->leftT == 0)
            ptr = ptr->left;
        else if (ptr->rightT == 0)
            ptr = ptr->right;
        else
        {
            while (ptr != NULL && ptr->rightT == 1)
                ptr = ptr->right;
            if (ptr != NULL)
                ptr = ptr->right;
        }
    }
}


struct TBT *insucc(struct TBT *root)
{
    struct TBT *ptr = root;

    if (ptr->rightT == 1)
    {
        return ptr->right;
    }
    else
    {
        ptr = ptr->right;
        while (ptr->leftT == 0)
        {
            ptr = ptr->left;
        }
        return ptr;
    }
}
void inorder(struct TBT *root)
{
    struct TBT *ptr;
    if (root == NULL)
    {
        printf("TREE IS EMPTY \n\n");
        return;
    }

    ptr = root;
    while (ptr->leftT == 0)
        ptr = ptr->left;

    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = insucc(ptr);
    }
}

struct TBT *inpred(struct TBT *root)
{
    struct TBT *ptr = root;
    if (ptr->leftT == 1)
    {
        return ptr->left;
    }
    else
    {
        ptr = ptr->left;
        while (ptr->leftT == 0)
        {
            ptr = ptr->right;
        }
        return ptr;
    }
}

struct TBT *insert(struct TBT *root, int val)
{
    struct TBT *ptr = root;
    struct TBT *temp;
    struct TBT *pre = NULL;

    while (ptr != NULL)
    {
        if (ptr->data == val)
        {
            printf("DUPLICATE VALUE");
            break;
        }
        pre = ptr;
        if (ptr->data > val)
        {
            if (ptr->leftT == 0)
            {
                ptr = ptr->right;
            }
            else
            {
                break;
            }
        }
        else
        {
            if (ptr->rightT == 0)
            {
                ptr = ptr->right;
            }
            else
            {
                break;
            }
        }

        temp = (struct TBT *)malloc(sizeof(struct TBT));
        temp->data = val;
        temp->leftT = 1;
        temp->rightT = 1;
        if (pre == NULL)
        {
            root = temp;
            temp->left = NULL;
            temp->right = NULL;
        }
        else if (pre->data > val)
        {
            temp->left = pre->left;
            temp->right = pre;
            pre->leftT = 0;
            pre->left = temp;
        }
        else
        {
            temp->left = pre;
            temp->right = pre->right;
            pre->rightT = 0;
            pre->right = temp;
        }
    }
    return root;
}

int main()
{
    int choice;
    int val;
    struct TBT *root = NULL;

    while (1)
    {
        printf("\n");
        printf("NAME : KARTIK RAIYANI   \nENROLLMENT NO. : 210210116019   \n");
        printf("\n");

        printf("1. Insertion \n");
        printf("2. Inorder Traversal\n");
        printf("3 Preorder Traversal PREORDER TRAVERSAL\n");
        printf("4. Quiit \n");
        printf("ENTER YOUR CHOICE \n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            // system("cls");
            printf("ENTER THE NUMBER WHICH YOU WANT TO INSERT \n");
            scanf("%d", &val);
            root = insert(root, val);
            printf("\n \n");
            printf("PRESS ANY KEY TO CONTINUE \n");
            getch();
            // system("cls");
            break;

        case 2:
            // system("cls");
            inorder(root);
            printf("\n \n");
            printf("PRESS ANY KEY TO CONTINUE \n");
            getch();
            // system("cls");
            break;

        case 3:
            // system("cls");
            preorder(root);
            printf("\n \n");
            printf("PRESS ANY KEY TO CONTINUE \n");
            getch();
            // system("cls");
            break;

        case 4:
            exit(1);

        default:
            printf("INVALID CHOICE \n ");
        }
    }

    return 0;
}