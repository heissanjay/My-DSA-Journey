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