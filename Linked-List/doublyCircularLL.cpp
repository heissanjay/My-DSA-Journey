/* Doubly Circular Linked List */

#include <iostream>
using namespace std;
class Node{
public:
    int data;
    Node* prev;
    Node* next;
};
void display(Node* head){
	Node* temp = head;
	cout<<"HEAD->";
	do{
		cout<<temp->data<<"->";
		temp = temp->next;
	}while(temp != head);
	cout<<"HEAD"<<endl;
}
void insertFront(Node** head,int val){
    Node* last = (*head)->prev;
    Node* newNode = new Node();
    newNode->data = val;

    newNode->next = *head;
    newNode->prev = last;
     
    last->next = (*head)->prev = newNode;

    *head = newNode;
}

int main(int argc, char const *argv[]){
    Node* head = NULL;
    head  = new Node();
    Node* second = new Node();
    Node* third = new Node();
    Node* last = new Node();

    // assinging data to node
    head->prev = last;
    head->data = 1;
    head->next = second;

    second->prev = head;
    second->data = 2;
    second->next = third;

    third->prev = second;
    third->data = 3;
    third->next = last;

    last->prev = third;
    last->data = 4;
    last->next = head;
    
    display(head);
    insertFront(&head,0);
    display(head);

    return 0;
}