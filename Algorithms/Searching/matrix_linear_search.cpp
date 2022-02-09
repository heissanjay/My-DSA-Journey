// implementation of linear search in 2D array
#include <iostream>
#include <vector>
using namespace std;
#define row 3
#define col 4
int arr[row][col] = {
    {6, 10, 15, 18},
    {12, 16, 21, 34},
    {17, 20, 24, 46}};

vector<int> linearSearch(int arr[row][col], int target)
{
    if (col == 0)
        return {-1, -1};

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (arr[i][j] == target)
            {
                return {i, j};
            }
        }
    }
    return {-1, -1};
}
int main(int argc, char const *argv[])
{
    vector<int> result = linearSearch(arr, 21);
    for (int i = 0; i < 2; i++)
    {
        cout << result.at(i) << " ";
    }
    cout << "\n";
    return 0;
}
