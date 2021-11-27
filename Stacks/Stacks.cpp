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
	bool push(int val);
	int pop();
	int peek();
	bool isEmpty();
};
// function to push the element to the stack
bool Stack::push(int val){
	if(top >= (MAX - 1)){
		cout<<"Stack OverFlow"<<endl;
		return false;
	}else{
		arr[top++]=val;
		return true;
	}
}

int main(int argc, char const *argv[])
{
	class Stack stk;
	stk.push(3);
	return 0;
}