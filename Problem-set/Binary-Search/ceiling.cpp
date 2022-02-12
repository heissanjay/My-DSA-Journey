// ceiling
// find the smallest number which is greater than or equal to target
#include <iostream>
using namespace std;

// sorted array
int arr[10] = {2, 13, 27, 45, 67, 77, 81, 89, 92, 98};
int arrlen = sizeof(arr) / sizeof(arr[0]);
int findCeiling(int arr[], int target, int arrlen); // function prototype

int main(int argc, char const *argv[])
{
    cout << findCeiling(arr, 50, arrlen) << "\n";
    return 0;
}
int findCeiling(int arr[], int target, int arrlen)
{
    int start = 0;
    int end = arrlen - 1;

    if (target > arr[end])
        return -1;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        if (target < arr[mid])
        {
            end = mid - 1;
        }
        else if (target > arr[mid])
        {
            start = mid + 1;
        }
        else
        {
            return mid;
        }
    }
    return start;
}