
// implementation of selection sort
#include <iostream>
using namespace std;

int arr[] = {6, 5, 12, 10, 9, 1};
int n = sizeof(arr) / sizeof(arr[0]); // n = 6

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
