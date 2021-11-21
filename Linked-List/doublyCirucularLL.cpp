/* Doubly Circular Linked List */

#include <iostream>
using namespace std;
class Node{
public:
    int data;
    Node* prev;
    Node* next;
};


int main(int argc, char const *argv[]){
    Node* head = NULL; head  = new Node();
    Node* second = new Node();
    Node* third = new Node();
    Node* four = new Node();

    // assinging data to node
    head->prev = four;
    head->data = 1;
    head->next = second;

    second->prev = head;
    second->data = 2;
    second->next = third;

    third->prev = second;
    third->data = 3;
    third->next = four;

    four->prev = third;
    four->data = 4;
    four->next = head;
    

    return 0;
}