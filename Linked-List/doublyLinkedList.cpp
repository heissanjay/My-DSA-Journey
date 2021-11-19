#include <iostream>
using namespace std;

class Node{
public:
	int data;
	Node* prev;
	Node* next;
};


void display(Node* n){
	while(n != NULL){
		cout<<n->data<<"->";
		n= n->next;
	}
	cout<<"NULL"<<endl;
}
// void insertFront(Node** temp, int val){
// 	Node* newNode = new Node();
// 	newNode->data = val;

// 	newNode->next = (*temp);
// 	newNode->prev = NULL;
// 	if((*temp) != NULL) (*temp)->prev = newNode;
// 	(*temp) = newNode;
// }


void insertBefore(Node** temp, int val){
	Node* newNode = new Node();
	newNode->data = val;
	newNode->next = (*temp);
	newNode->prev = (*temp)->prev;
	(*temp) = newNode;
}



int main(int argc, char const *argv[])
{
	Node* head = NULL;
	head = new Node();
	Node* second = new Node();
	Node* third = new Node();
	Node* fourth = new Node();


	head->prev = NULL;
	head->data = 1;
	head->next = second;
	
	second->prev = head;
	second->data = 2;
	second->next = third;

	third->prev = second;
	third->data = 3;
	third->next = fourth;

	fourth->prev = third;
	fourth->data = 4;
	fourth->next = NULL;

	// insertFront(&head,2);
	insertBefore(&(third->next),4);
	display(head);
	return 0;
}
