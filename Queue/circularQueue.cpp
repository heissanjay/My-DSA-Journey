// Circular queue array implementation
#include <iostream>
using namespace std;
#define MAX 10
class CircularQueue
{
public:
    int arr[MAX];
    int front = -1, rear = -1;
    void enqueue(int val);
    void dequeue();
    void display();
};
void CircularQueue::enqueue(int val)
{
    if (((front == 0) && (rear = MAX - 1)) || (rear + 1 == front))
        cout << "queue is full";
    else if (rear == -1)
        front = rear = 0;
    else if (rear = MAX - 1)
        rear = 0;
    else
        rear++;

    arr[rear] = val;
}
void CircularQueue::dequeue()
{
    if (front == -1)
        cout << "queue is empty";
    else
    {
        int del = arr[front];
        if (front == rear)
            front = rear = -1;
        else if (front == MAX - 1)
            front = 0;
        else
            front++;

        cout << del << endl;
    }
}

int main(int argc, char const *argv[])
{
    CircularQueue Cqueue;
    Cqueue.enqueue(3);
    Cqueue.enqueue(12);
    Cqueue.enqueue(43);
    Cqueue.enqueue(67);
    Cqueue.enqueue(33);
    Cqueue.enqueue(22);
    Cqueue.enqueue(86);
    return 0;
}
