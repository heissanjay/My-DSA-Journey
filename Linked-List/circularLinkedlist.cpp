#include <iostream>
using namespace std;

class Node{
public:
	int data;
	Node* next;
};

int main(int argc, char const *argv[])
{
	Node* head = NULL;
	head = new Node();
	Node* second = new Node();
	Node* third = new Node();
	Node* four = new Node();

	// // assiging data to nodes

	head->data = 1;
	head->next = second;
	second->data = 2;
	second->next = third;
	third->data = 3;
	third->next = four;
	four->data = 4;
	four->next = head;

	

	return 0;
}