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
