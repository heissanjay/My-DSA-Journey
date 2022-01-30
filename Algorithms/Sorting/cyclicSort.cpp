// implementation of cyclic sort

#include <iostream>
using namespace std;
#define SIZE 10
// array of Range 1 to N
int arr[] = {2, 4, 5, 6, 10, 9, 1, 7, 3, 8}; // here N  = 10;
int arrlen = sizeof(arr) / sizeof(arr[0]);

void cyclicSort(int arr[], int arrlen); // function prototype
void swap(int arr[], int cur, int crt); // function prototype

int main(int argc, char const *argv[])
{
    cyclicSort(arr, arrlen);
    for (int i = 0; i < arrlen; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
    return 0;
}

void cyclicSort(int arr[], int arrlen)
{
    int i = 0;

    while (i < arrlen)
    {
        int crt = arr[i] - 1;
        if (arr[i] != arr[crt])
        {
            swap(arr, i, crt);
        }
        else
        {
            i++;
        }
    }
}
void swap(int arr[], int cur, int crt)
{
    int temp = arr[cur];
    arr[cur] = arr[crt];
    arr[crt] = temp;
}