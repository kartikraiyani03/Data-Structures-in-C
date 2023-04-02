#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

struct tree
{
    int data;
    struct tree *right;
    struct tree *left;
};

struct tree *CreateTree(int data)
{
    struct tree *node = (struct tree *)malloc(sizeof(struct tree));
    node->right = NULL;
    node->left = NULL;
    node->data = data;
    return node;
}

void preorder(struct tree *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct tree *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

void inorder(struct tree *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int BinaryTree(struct tree *root)
{
    static struct tree *prev = NULL;

    if (root != NULL)
    {
        if (!BinaryTree(root->left))
        {
            return 0;
        }

        if (prev != NULL && root->data <= prev->data)
        {
            return 0;
        }

        prev = root;
        return BinaryTree(root->right);
    }

    else
    {
        return 1;
    }
}

int calculate(struct tree *root)
{
    int i = 0;

    while (root != NULL)
    {
        calculate(root->left);
        calculate(root->right);
        i++;
    }
    return i;
}

int Height(struct tree *root)
{
    int i = 0;
    int j = 0;

    while (root != NULL)
    {
        root = root->left;
        i++;
    }

    while (root != NULL)
    {
        root = root->right;
        j++;
    }

    if (i > j)
    {
        return i;
    }
    else
    {
        return j;
    }
}

struct tree *search(struct tree *root, int val)
{
    if (root == NULL)
    {
        return NULL;
    }

    if (root->data == val)
    {
        printf("VALUE IS IN THE TREE \n");
        return root;
    }

    if (root->data < val)
    {
        return search(root->right, val);
    }
    else
    {
        return search(root->left, val);
    }
}

struct tree *itrationSearch(struct tree *root, int value)
{
    while (root != NULL)
    {

        if (root->data == value)
        {
            return root;
        }
        else if (root->data > value)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    return NULL;
}

struct tree *insert(struct tree *root, int element)
{
    struct tree *prev = NULL;

    while (root != NULL)
    {
        prev = root;

        if (element == root->data)
        {
            return 0;
        }
        if (element < root->data)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }

    struct tree *leaf = CreateTree(element);

    if (element < prev->data)
    {
        prev->left = leaf;
    }
    else
    {
        prev->left = leaf;
    }
    return root;
}

struct tree *inOrderPrecedence(struct tree *root)
{
    root = root->left;

    while (root->right != NULL)
    {
        root = root->right;
    }

    return root;
}

struct tree *delation(struct tree *root, int val)
{
    struct tree *NewData;

    if (root == NULL)
    {
        return NULL;
    }
    if (root->left == NULL && root->right == NULL)
    {
        free(root);
        return NULL;
    }
    if (val > root->data)
    {
        root->right = delation(root->right, val);
    }
    else if (val < root->data)
    {
        root->left = delation(root->left, val);
    }
    else
    {
        NewData = inOrderPrecedence(root);
        root->data = NewData->data;
        root->left = delation(root->left, NewData->data);
    }
    return root;
}

int CountNode(struct tree *root)
{
    int i, j;
    int count;

    if (root == NULL)
    {
        return 0;
    }
    else
    {
        i = CountNode(root->left);
        j = CountNode(root->right);
    }
    count = i + j;
    return (count + 1);
}

int Maximum(struct tree *root)
{
    struct tree *ptr = root;

    while (ptr->right != NULL)
    {
        ptr = ptr->right;
    }
    return ptr->data;
}

int leafNode(struct tree *root)
{
    int i = 0;

    if (root == NULL)
    {
        return 0;
    }

    else if (root->right == NULL && root->right == NULL)
    {
        return 1;
    }
    else
    {
        return leafNode(root->right) + leafNode(root->left);
    }
}

void deletetree(struct tree *root)
{
    if (root == NULL)
    {
        return;
    }
    deletetree(root->left);
    deletetree(root->right);
    free(root);
}

int main()
{

    int value;

    struct tree *root = CreateTree(30);
    struct tree *a = CreateTree(20);
    struct tree *b = CreateTree(32);
    struct tree *c = CreateTree(12);
    struct tree *d = CreateTree(22);
    struct tree *e = CreateTree(34);

    root->right = b;
    root->left = a;
    a->left = c;
    a->right = d;
    b->right = e;

    int choice;
    int element;
    int val;

    while (1)
    {
        printf("\n");
        printf("NAME : KARTIK RAIYANI \nENROLLMENT NO. : 210210116019   \n");
        printf("\n");

        printf("1.  Preorder Traversal\n");
        printf("2.  Postorder Traversal\n");
        printf("3.  Inorder Traversal \n");
        printf("4.  Check the Tree  \n");
        printf("5.  Search  \n");
        printf("6.  Itration Search \n");
        printf("7.  Insert \n");
        printf("8.  Dealation \n");
        printf("9.  Calculate the Tree \n");
        printf("10. Coubt the Node \n");
        printf("11. Count the Leaf Node \n");
        printf("12. Delete Whole Tree \n");
        printf("13. Maximum Value Node \n");
        printf("14. Quit \n \n");

        printf("ENTER YOUR CHOICE \n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:

            printf("PREORDER TRAVERSAL IS \n");
            preorder(root);
            printf("\n \n");
            printf("PRESS ANY KEY TO CONTINUE \n");
            getch();

            break;

        case 2:

            printf("POSTORDER TRAVERSAL IS \n");
            printf("\n \n");
            postorder(root);
            printf("\n \n");
            printf("PRESS ANY KEY TO CONTINUE \n");
            getch();

            break;

        case 3:

            printf("INORDER TRAVERSAL IS \n");

            inorder(root);
            printf("\n \n");
            printf("PRESS ANY KEY TO CONTINUE \n");
            getch();

            break;

        case 4:

            if (BinaryTree(root))
            {
                printf("GIVEN TREE IS BINARY SEARCH TREE \n \n");
                printf("PREE ANY KEY TO CONTINUE \n");
                getch();
            }
            else
            {
                printf("GIVEN TREE IS NOT BINARY SEARCH TREE \n \n");
                printf("PREE ANY KEY TO CONTINUE \n");
                getch();
            }
            break;

        case 5:

            printf("ENTER THE VALUE WHICH YOU WANT TO FIND \n ");
            scanf("%d", &value);
            struct tree *m = insert(root, value);
            if (m != NULL)
            {
                printf("NUMBER %d FOUND \n \n", m->data);
            }
            else
            {
                printf("ELEMTN NOT FOUND \n \n");
            }
            break;

        case 6:

            printf("ENTER THE VALUE WHICH YOU WANT TO FIND \n ");
            scanf("%d", &value);
            struct tree *n = itrationSearch(root, value);
            if (n != NULL)
            {
                printf("NUMBER %d FOUND \n \n", n->data);
            }
            else
            {
                printf("ELEMTN NOT FOUND \n \n");
            }
            break;

        case 7:
            printf("ENTER THE NUMBER WHICH YOU WANT TO INSERT \n");
            scanf("%d", &element);
            struct tree *a = insert(root, element);

            break;

        case 8:
            printf("ENTER THE VALUE WHICH YOU WANT TO DELETE \n ");
            scanf("%d", &val);
            delation(root, val);
            printf("DELATION SUCCESFULL !! \n \n");
            printf("PRESS ANY KEY TO CONTINUE \n");
            getch();

            break;

        case 9:

            printf("HEIGHT OF THE TREE IS %d", Height(root));
            printf("\n \n");
            printf("PRESS ANY KEY TO CONTINUE \n");
            getch();

            break;

        case 10:

            printf("\n");
            printf("NUMBER OF NODES ARE..... \n \n");
            printf("%d\n \n", CountNode(root));
            printf("PRESS ANY KEY TO CONTINUE \n");
            getch();

            break;

        case 11:

            printf("\n");
            printf("NUMBER OF LEAF NODES ARE..... \n \n");
            printf("%d\n \n", leafNode(root));
            printf("PRESS ANY KEY TO CONTINUE \n");
            getch();

            break;

        case 12:

            printf("\n");
            deletetree(root);
            printf("TREE IS DELETED \n \n");
            printf("PRESS ANY KEY TO CONTINUE \n");
            getch();

            break;

        case 13:

            printf("\n");
            printf("MAXIMUM VALUE OF THE NODE IS....\n \n");
            printf("%d \n \n", Maximum(root));
            printf("PRESS ANY KEY TO CONTINUE \n");
            getch();

            break;

        case 14:
            exit(1);

        default:
            printf("INVALID CHOICE \n");
            break;
        }
    }

    return 0;
}
