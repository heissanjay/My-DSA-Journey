/* Array implementation of Stack */
#include <iostream>
using namespace std;
#define MAX 100

class Stack{
	int top;
	int arr[MAX];
public:
	Stack(){
		top = -1;
	}
	bool isFull();
	bool isEmpty();
	int push(int val);
	void display();
	int pop();
	int peek();
};
bool Stack::isFull(){
	if(top >= MAX)
		return true;
	else
		return false;
}

bool Stack::isEmpty(){
	if(top == -1)
		return true;
	else 
		return false;
}
int Stack::push(int val){
	if(isFull()){
		cout<<"Stack Overflow"<<endl;return 0;
	}
	else{
		top++;
		arr[top] = val;
		return 0;
	}
}
int Stack::pop(){
	int popVal = arr[top];
	top--;
	return popVal;
}

void Stack::display(){
	for(int i = top;i >= 0; --i)
		cout<<arr[i]<<"\n";
}
int Stack::peek(){
	int peekVal = arr[top];
	return peekVal;
}

int main(int argc, char const *argv[])
{
	Stack stk;
	stk.push(1);
	stk.push(2);
	stk.push(3);
	stk.push(4);
	stk.display();
	cout<<"\n";
	stk.pop();
	stk.display();
	cout<<"\n";
	stk.peek();
	return 0;
}
