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

int main(int argc, char const *argv[])
{

    return 0;
}
