#include <iostream>
using namespace std;
#define SIZE 100

class Queue
{
public:
	int arr[SIZE];
	int front = -1, rear = -1;
	int arr_size = sizeof(arr) / sizeof(arr[0]);
	bool isEmpty()
	{
		if (front == -1 && rear == -1)
			return true;
		else
			return false;
	}
	bool isFull()
	{
		if (rear >= SIZE)
			return true;
		else
			return false;
	}
	int enqueue(int val)
	{
		if (isFull())
		{
			cout << "Queue is full" << endl;
			return 0;
		}
		else if (isEmpty())
		{
			front++;
			rear++;
			arr[rear] = val;
			return 0;
		}
		else
		{
			rear++;
			arr[rear] = val;
			return 0;
		}
	}
	void display()
	{
		for (int i = 0; i < rear + 1; ++i)
			cout << arr[i] << " ";
	}
};

int main(int argc, char *argv[])
{
	Queue Que1;
	Que1.enqueue(1);
	Que1.enqueue(3);
	Que1.enqueue(5);
	Que1.enqueue(6);
	Que1.enqueue(6);
	Que1.enqueue(7);
	Que1.display();
	return 0;
}
