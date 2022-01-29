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
// void levelOrderTraversal(struct Node *node)
// {
//     if (node == nullptr)
//         return;

//     queue<struct Node *> q;
//     q.push(node);

//     while (!q.empty())
//     {
//         struct Node *temp = q.front();
//         cout << temp->item << " ";
//         q.pop();

//         if (temp->left != nullptr)
//             q.push(temp->left);

//         if (temp->right != nullptr)
//             q.push(temp->right);
//     }
//     cout << "\n";
// }
void inorderTraversal(struct Node *root)
{
    if (root != nullptr)
    {
        inorderTraversal(root->left);
        cout << root->item << " ";
        inorderTraversal(root->right);
    }
}
struct Node *findMin(struct Node *root)
{
    struct Node *temp = root;
    while (temp != nullptr && temp->left != nullptr)
    {
        temp = temp->left;
    }
    return temp;
}
struct Node *deleteNode(struct Node *root, int val)
{
    // base cases
    if (root == nullptr)
        return root;
    else if (val < root->item)
        root->left = deleteNode(root->left, val);
    else if (val > root->item)
        root->right = deleteNode(root->right, val);
    else
    {
        // Case 1: If the node contains no child
        if (root->left == nullptr && root->right == nullptr)
        {
            free(root);
            root = nullptr;
        }
        // case 2: if the node contains only one child ( either left or right)
        else if (root->left == nullptr)
        {
            struct Node *temp = root;
            root = root->right;
            free(temp);
        }
        else if (root->right == nullptr)
        {
            struct Node *temp = root;
            root = root->left;
            free(root);
        }
        // case 3. if the node contains two children
        else
        {
            // find minimum value in the right sub tree
            struct Node *temp = findMin(root->right);
            // assign it to root
            root->item = temp->item;
            // delete the duplicate
            root->right = deleteNode(root->right, temp->item);
        }
    }
    return root;
}
int main(int argc, char const *argv[])
{
    struct Node *root = nullptr;
    root = createNode(10);
    root->left = createNode(5);
    root->right = createNode(15);

    root->left->left = createNode(1);
    root->left->right = createNode(8);

    root->right->left = createNode(13);
    root->right->right = createNode(20);

    insertNode(root, 35);
    inorderTraversal(root);
    cout << "\n";
    deleteNode(root, 8);
    inorderTraversal(root);
    cout << "\n";
    return 0;
}
