// implementation of avl tree

#include <iostream>
using namespace std;

// struct of the node
struct Node
{
    int item;
    struct Node *left, *right;
    int height;
};

// func to find max of two number
int max(int a, int b)
{
    return (a > b) ? a : b;
}
// get the height of the node
int getHeight(struct Node *node)
{
    if (node == nullptr)
    {
        return 0;
    }
    return node->height;
}
// func to create a new node

struct Node *createNode(int val)
{
    // allocate memory for new node
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->item = val;
    newNode->left = nullptr;
    newNode->right = nullptr;
    newNode->height = 1;
    return newNode;
}

// func to get the balance factor of a node
int getBalanceFactor(struct Node *node)
{
    if (node == nullptr)
        return 0;

    return getHeight(node->left) - getHeight(node->right);
}
// left rotate
struct Node *left_rotate(struct Node *x)
{
    struct Node *y = x->right; // y is right sub tree of x
    struct Node *t = y->left;
    y->left = x;
    x->right = t; // t is y's left sub tree

    x->height = max(getHeight(x->left), getHeight(x->right)) + 1; // height of x
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1; // height of y

    return y; // y becomes root
}
// right rotate
struct Node *right_rotate(struct Node *y)
{
    struct Node *x = y->left;
    struct Node *t = x->right;
    x->right = y;
    y->left = t;

    x->height = max(getHeight(x->left), getHeight(x->right)) + 1; // height of x
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1; // height of y

    return x; // x becomes root
}