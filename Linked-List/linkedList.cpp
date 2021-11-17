#include <iostream>
using namespace  std;

class Node{
public:
	int data;
	Node* next;
};


void insertFront(Node** temp,int d){
	Node* newNode = new Node();
	newNode->data = d;
	newNode->next = (*temp);
	(*temp) = newNode;
}

int main(int argc, char const *argv[])
{
	// creating new nodes
	Node* head = new Node();
	Node* second = new Node();
	Node* third = new Node();

	// assinging values to the node
	head->data = 2;
	head->next = second;

	second->data = 3;
	second->next = third;

	third->data  = 4;
	third->next = NULL;

	insertFront(&head,1);

	// printing linked list
	Node *n = head;
	while(n != NULL){
		cout<<n->data<<" ";
		n = n->next;
	}
	// output
	// 1 2 3 4

	cout<<endl;
	return 0;
}