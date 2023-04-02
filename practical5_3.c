#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>

struct tree
{
    int data;
    struct tree *right;
    struct tree *left;
    int height;
};

void inorder(struct tree *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

struct tree *CreateTree(int data)
{
    struct tree *node = (struct tree *)malloc(sizeof(struct tree));
    node->right = NULL;
    node->left = NULL;
    node->data = data;
    return node;
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

int MaxNum(int a, int b)
{
    if (a > b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

int Balance(struct tree *root)
{
    return Height(root->left) - Height(root->right);
}

struct tree *RightRotate(struct tree *root)
{
    struct tree *b = root->left;
    struct tree *e = b->right;

    b->right = root;
    root->left = e;

    root->height = MaxNum(Height(root->left), Height(root->right)) + 1;
    b->height = MaxNum(Height(b->left), Height(b->right)) + 1;
}
struct tree *LeftRotate(struct tree *root)
{
    struct tree *a = root->right;
    struct tree *e = a->left;

    a->left = root;
    root->right = e;

    root->height = MaxNum(Height(root->left), Height(root->right)) + 1;
    a->height = MaxNum(Height(a->left), Height(a->right)) + 1;
}

struct tree *insert(struct tree *root, int val)
{
    if (root == NULL)
    {
        return CreateTree(val);
    }
    if (root->data < val)
    {
        root->right = insert(root->right, val);
    }
    else if (root->data > val)
    {
        root->left = insert(root->left, val);
    }
    else
    {
        return root;
    }

    root->height = MaxNum(Height(root->left), Height(root->right)) + 1;

    int bf;
    bf = Balance(root);

    if (bf > 1 && root->left->data > val)
    {
        return RightRotate(root);
    }
    if (bf < -1 && root->right->data < val)
    {
        return LeftRotate(root);
    }
    if (bf > 1 && root->left->data < val)
    {
        root->left = LeftRotate(root->left);
        return RightRotate(root);
    }
    if (bf < 1 && root->right->data > val)
    {
        root->right = RightRotate(root->right);
        return LeftRotate(root);
    }

    return root;
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

int main()
{
    printf("\n");
    printf("NAME : KARTIK  RAIYANI   \nENROLLMENT NO. : 210210116019 \n");
    printf("\n");

    struct tree *root = NULL;

    int val;

    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 32);
    preorder(root);
    printf("\n");
    printf(" AVL TRAVERSAL AFTER INSERTION IS.. \n\n");
    root = insert(root, 12);
    root = insert(root, 22);
    root = insert(root, 34);
    preorder(root);

    return 0;
}