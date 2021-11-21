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
    
    display(head);

    return 0;
}