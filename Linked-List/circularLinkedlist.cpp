#include <iostream>
using namespace std;

class Node{
public:
	int data;
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


int main(int argc, char const *argv[])
{
	Node* head = NULL;
	head = new Node();
	Node* second = new Node();
	Node* third = new Node();
	Node* four = new Node();

	// assigning data to nodes
	head->data = 1;
	head->next = second;

	second->data = 2;
	second->next = third;

	third->data = 3;
	third->next = four;

	four->data  = 4;
	four->next = head; /*  Circular linked list */

	display(head);

	return 0;
}