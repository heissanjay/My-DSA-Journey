
// implementation of selection sort
#include <iostream>
using namespace std;

int arr[] = {6, 5, 12, 10, 9, 1};
int n = sizeof(arr) / sizeof(arr[0]); // n = 6
// func to swap two variables
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[min] > arr[j])
            {
                min = j;
            }
        }
        swap(&arr[min], &arr[i]);
    }
}
void display(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

int main(int argc, char const *argv[])
{
    cout << "Array before sorted :"
         << "\n";
    display(arr, n);
    selectionSort(arr, n);
    cout << "Sorted Array :"
         << "\n";
    display(arr, n);
    return 0;
}
