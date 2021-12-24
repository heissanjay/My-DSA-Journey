#include <iostream>
using namespace std;
#define SIZE 100

class Queue
{
public:
	int arr[SIZE];
	int front = -1, rear = -1;

	bool isEmpty()
	{
		if (front == rear == -1)
			return true;
		else
			return false;
	}
};

int main(int argc, char *argv[])
{
	Queue Que1;
	return 0;
}
