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
    /* if List is empty */
    if((*head) == NULL ){
        Node* newNode = new Node();
        newNode->data=val;
        newNode->next = newNode->prev = newNode;
        *head = newNode; return;
    }
    Node* last = (*head)->prev;
    Node* newNode = new Node();
    newNode->data = val;

    newNode->next = *head;
    newNode->prev = last;
     
    last->next = (*head)->prev = newNode;

    *head = newNode;
}
void insertEnd(Node** head,int val){
    /* if List is empty */
    if((*head) == NULL ){
        Node* newNode = new Node();
        newNode->data=val;
        newNode->next = newNode->prev = newNode;
        *head = newNode; return;
    }
    Node* last = (*head)->prev;
    Node* newNode = new Node();
    newNode->data  = val;

    newNode->next = *head;  
    newNode->prev = (*head)->prev = newNode;
    last->next = newNode;    
}
void insertAfter(Node** head,int val,int position){
    Node* temp = *head;
    Node* newNode = new Node();
    newNode->data= val;
    for(int i =1 ; i < position -1 && temp->next != *head ; ++i) temp = temp->next;    
    newNode->next = temp->next;
    newNode->prev = temp->next->prev = newNode;
    temp->next = newNode;
}
void deleteAtPos(Node** head,int position){
    Node* temp = *head;
    if(temp == NULL) return;
    if(position == 1){
        (*head)->prev->next = (*head)->next;
        (*head)->next->prev = (*head)->prev;
        *head = temp->next; free(temp); return;
    } 
    for(int i = 1; i < position - 1 && temp->next != *head;++i) temp = temp->next;
    /* return if index out of bound */
    if(temp == *head or temp->next == *head) return;
    
    /* delete a node at last postion */
    Node* node = temp->next->next;if(node == *head){
        temp->next=temp->next->next;
        node->prev = temp;
        free(temp->next); return;
    } 
    /*-------------------------------*/
    Node* newNode = temp->next;
    temp->next = node->next;
    newNode->next->prev = temp;
    free(node);
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

    // insertFront(&head,1);
    // insertEnd(&head,2);
    // display(head);
    insertFront(&head,0);
    display(head);
    insertEnd(&head,5);
    display(head);
    insertAfter(&head,1,3);
    display(head);
    deleteAtPos(&head,7);
    display(head);

    return 0;
}