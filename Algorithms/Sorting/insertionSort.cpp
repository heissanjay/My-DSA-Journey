// implementaiton of insertion sort

#include <iostream>
using namespace std;

int arr[] = {6, 5, 12, 10, 9, 1};
int n = sizeof(arr) / sizeof(arr[0]);

// func to swap two variables
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void insertionSort(int arr[])
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j > 0; j--)
        {
            if (arr[j] < arr[j - 1])
            {
                swap(&arr[j], &arr[j - 1]);
            }
            else
            {
                break;
            }
        }
    }
}
void display(int arr[])
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}
int main(int argc, char const *argv[])
{
    display(arr);
    insertionSort(arr);
    display(arr);
    return 0;
}
