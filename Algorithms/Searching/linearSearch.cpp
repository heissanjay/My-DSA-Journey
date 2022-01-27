// implementation of linear search

#include <iostream>
using namespace std;

#define SIZE 10
int linearSearch(int target); // function prototype

int arr[SIZE] = {34, 26, 12, 89, 45, 69, 90, 345, 73, 56};
int main(int argc, char const *argv[])
{

    return 0;
}
int linearSearch(int target)
{
    for (int i = 0; i < SIZE; ++i)
    {
        if (arr[i] == target)
            return i;
    }
    return -1;
}