// implementation of binary tree

// including required libraries

#include <stdlib.h>
#include <iostream>
using namespace std;

// structure of node
struct Node
{
    int item;
    struct Node *left, *right;
};
// func to create a new node
struct Node *createNode(int item)
{
    // allocate memory for new node
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    // assinging data item to node
    newNode->item = item;
    // pointer to left node
    newNode->left = nullptr;
    // pointer to right node
    newNode->right = nullptr;

    return newNode;
}
int main(int argc, char const *argv[])
{
    struct Node *root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);

    root->left->left = createNode(4);
    root->left->right = createNode(5);

    return 0;
}