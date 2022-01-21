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
int main(int argc, char const *argv[])
{

    return 0;
}
