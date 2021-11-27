/* Array implementation of Stack */

#include<iostream>
using namespace std;

#define MAX 100	

// Defining the stack
class Stack{
	int top;
public:
	int arr[MAX];
	Stack() {top = -1;}
	bool push();
	int pop();
	int peek();
	bool isEmpty();
};

int main(int argc, char const *argv[])
{
	
	return 0;
}