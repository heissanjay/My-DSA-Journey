// implementation of binary tree

// including required libraries
#include <queue>
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
// Tree Traversal
// Pre-order Traversal
void traversePreOrder(struct Node *node)
{
    if (node != nullptr)
    {
        cout << node->item << " ";
        traversePreOrder(node->left);
        traversePreOrder(node->right);
    }
}

// In Order Traversal
void traverseInOrder(struct Node *node)
{
    if (node != nullptr)
    {
        traverseInOrder(node->left);
        cout << node->item << " ";
        traverseInOrder(node->right);
    }
}

// Post Order Traversal
void traversePostOrder(struct Node *node)
{
    if (node != nullptr)
    {
        traversePostOrder(node->left);
        traversePostOrder(node->right);
        cout << node->item << " ";
    }
}
// Level order insertion - using queue method
struct Node *levelOrderInsertion(struct Node *node, int item)
{
    if (node == nullptr)
    {
        node = createNode(item);
        return node;
    }
    queue<struct Node *> q;
    q.push(node);

    while (!q.empty())
    {
        struct Node *temp = q.front();
        q.pop();

        if (temp->left != nullptr)
            q.push(temp->left);
        else
        {
            temp->left = createNode(item);
            return node;
        }

        if (temp->right != nullptr)
            q.push(temp->right);
        else
        {
            temp->right = createNode(item);
            return node;
        }
    }
    return node;
}
// driver code
int main(int argc, char const *argv[])
{
    // creating root node
    struct Node *root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);

    root->left->left = createNode(4);
    root->left->right = createNode(5);

    levelOrderInsertion(root, 6);
    cout << "PreOrder Traversal :";
    traversePreOrder(root);
    cout << "\n";

    cout << "InOrder Traversal :";
    traverseInOrder(root);
    cout << "\n";

    cout << "Post Order Traversal :";
    traversePostOrder(root);
    cout << "\n";

    return 0;
}