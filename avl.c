/*
#include <stdio.h>
#include <stdlib.h>

struct avl{
int data;
int height;
struct avl *left;
struct avl *right;
};

int max(int a, int b)
{
    return (a>b)? a:b;
}

int height(struct avl *n)
{
    if(n==NULL)
        return(0);
    return(n->height);
}

struct avl *createNode(struct avl *root, int data)
{
    struct avl *t = (struct avl *)malloc(sizeof(struct avl));
    t->data=data;
    t->left=NULL;
    t->right=NULL;
    t->height=1;
    return(t);
};

int getBalance(struct avl *n)
{
    if(n==NULL)
        return(0);
    return(height(n->left)-height(n->right));
}

struct avl *rightRotate(struct avl *y)
{
    struct avl *x=y->left;
    struct avl *t2=x->right;

    //Rotate
    x->right=y;
    y->left=t2;

    x->height = max(height(x->left),height(x->right))+1;
    y->height = max(height(y->left),height(y->right))+1;

    return(x);
};

struct avl *leftRotate(struct avl *y)
{
    struct avl *x=y->right;
    struct avl *t2=x->left;

    //Rotate
    x->left=y;
    y->right=t2;

    x->height = max(height(x->left),height(x->right))+1;
    y->height = max(height(y->left),height(y->right))+1;

    return(x);
};

struct avl *insert(struct avl *root, int data)
{
    if(root==NULL)
        return(createNode(root, data));
    if(data < root->data)
        root->left = insert(root->left, data);
    else if(data > root->data)
        root->right = insert(root->right, data);
    else
        return root;

    root->height = 1+max(height(root->left), height(root));

    int balance=getBalance(root);

    if(balance >1 && data < root->left->data)
        return(rightRotate(root));
    if(balance <-1 && data > root->right->data)
        return(leftRotate(root));
    if(balance >1 && data >root->left->data){
        root->left=leftRotate(root->left);
        return(rightRotate(root));
    }
    if(balance<-1 && data<root->right->data){
        root->right=rightRotate(root->right);
        return(leftRotate(root));
    }
    return(root);
};

void preOrder(struct avl *root)
{
    if(root != NULL)
    {
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

int menu()
{
    int ch;
    printf("\n1. Add value");
    printf("\n2. Preorder value");
    printf("\n3. Exit");
    printf("\nEnter choice: ");
    scanf("%d", &ch);
    return ch;
}

void main()
{
    int item;
    struct avl *root=NULL;
    while(1)
    {
        switch(menu())
        {
        case 1:
            printf("Enter number to insert: ");
            scanf("%d", &item);
            root = insert(root, item);
            preOrder(root);
            break;
        case 2:
            preOrder(root);
            break;
        case 3:
            exit(0);
        default:
            printf("Invalid");
        }
    }
    getch();
}
