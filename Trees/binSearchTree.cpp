// implementation binary Search trees
#include <iostream>
#include <queue>
using namespace std;

// structure of node
struct Node
{
    int item;
    struct Node *left;
    struct Node *right;
};

struct Node *createNode(int val)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->item = val;
    newNode->left = nullptr;
    newNode->right = nullptr;

    return newNode;
}
struct Node *insertNode(struct Node *node, int val)
{
    if (node == nullptr)
        return createNode(val);

    else if (val < node->item)
        node->left = insertNode(node->left, val);
    else
        node->right = insertNode(node->right, val);

    return node;
}
void levelOrderTraversal(struct Node *node)
{
    if (node == nullptr)
        return;

    queue<struct Node *> q;
    q.push(node);

    while (!q.empty())
    {
        struct Node *temp = q.front();
        cout << temp->item << " ";
        q.pop();

        if (temp->left != nullptr)
            q.push(temp->left);

        if (temp->right != nullptr)
            q.push(temp->right);
    }
    cout << "\n";
}
