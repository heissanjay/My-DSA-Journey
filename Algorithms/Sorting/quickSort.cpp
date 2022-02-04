// implementation of quick sort

#include <iostream>
using namespace std;

void quicksort(int arr[], int low, int high)
{
    if (low >= high)
        return;

    int first = low;
    int last = high;
    int mid = (first + last) / 2;
    int pivot = arr[mid];

    while (first <= last)
    {
        while (arr[first] < pivot)
        {
            first++;
        }
        while (arr[last] > pivot)
        {
            last--;
        }

        if (first <= last)
        {
            // swap
            int temp = arr[first];
            arr[first] = arr[last];
            arr[last] = temp;
            first++;
            last--;
        }
    }

    quicksort(arr, low, last);
    quicksort(arr, first, high);
}

void print_array(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
}
int main(int argc, char const *argv[])
{
    int arr[] = {2, 4, 9, 23, 56, 3, 7, 1, 78};
    int len = sizeof(arr) / sizeof(arr[0]);
    cout << "Array before Sorted: ";
    print_array(arr, len);

    quicksort(arr, 0, len);

    cout << "Array after Sorted: ";
    print_array(arr, len);

    return 0;
}
