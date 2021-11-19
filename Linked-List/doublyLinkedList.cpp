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
void displayReverse(Node* tail){
	while(tail != NULL){
		cout<<tail->data<<"->";
		tail = tail->prev;
	}
	cout<<"END"<<endl;
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

void insertAfter(Node* preNode, int val){
	Node* newNode = new Node();
	newNode->data = val;

	newNode->next = preNode->next;
	preNode->next = newNode;
	newNode->prev = preNode;

	if(newNode->next != NULL){
		newNode->next->prev = newNode;
	}
}
void insertLast(Node** head,int val){
	Node* lNode = (*head);
	Node* newNode = new Node();

	newNode->data = val;
	newNode->next = NULL;
	if(*head == NULL){
		newNode->prev = NULL; *head = newNode; return;
	}
	while(lNode->next != NULL){
		lNode = lNode->next;
	}
	lNode->next = newNode;
	newNode->prev = lNode;
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
	Node* tail = fourth;

	// insertFront(&head,2);
	// insertBefore(&(third->next),4);
	display(head);
	insertAfter(fourth,5);
	display(head);
	insertLast(&head,6);
	display(head);
	displayReverse(tail);
	return 0;
}
