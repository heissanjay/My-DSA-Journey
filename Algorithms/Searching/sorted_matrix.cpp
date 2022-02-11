// searching for an element in a sorted matrix
#include <bits/stdc++.h>
using namespace std;
#define row 4
#define col 4

int matrix[row][col] =
    {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
};
vector<int> binarySearch(int matrix[row][col], int r, int col_start, int col_end, int target)
{
    while (col_start <= col_end)
    {
        int mid = col_start + (col_end - col_start) / 2;
        if (matrix[r][mid] == target)
        {
            return {r, mid};
        }
        else if (matrix[r][mid] < target)
        {
            col_start = mid + 1;
        }
        else
        {
            col_end = mid - 1;
        }
    }
    return {-1, -1};
}
int main(int argc, char const *argv[])
{
    vector<int> result = sortedMatrixSearch(matrix, 12);
    for (int i = 0; i < 2; i++)
    {
        cout << result[i] << " ";
    }
    cout << "\n";
    return 0;
}