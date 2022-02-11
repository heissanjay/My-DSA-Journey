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
vector<int> sortedMatrixSearch(int matrix[row][col], int target)
{
    // int row = row;
    // int c = col;

    if (col == 0) // matrix is empty
        return {-1, -1};

    if (row == 1) // only one row is present
        return binarySearch(matrix, 0, 0, col - 1, target);

    // assigning values
    int r_start = 0;
    int r_end = row - 1;
    int c_mid = col / 2;

    while (r_start < (r_end - 1)) // run till we remain with 2 rows
    {
        int mid = r_start + (r_end - r_start) / 2;
        if (matrix[mid][c_mid] == target) // element found
        {
            return {mid, c_mid};
        }
        else if (matrix[mid][c_mid] < target)
        {
            r_start = mid;
        }
        else
        {
            r_end = mid;
        }
    }
    // now we left with 2 rows
    // check  the elements of mid col
    if (matrix[r_start][c_mid] == target)
    {
        return {r_start, c_mid};
    }
    if (matrix[r_start + 1][c_mid] == target)
    {
        return {r_start + 1, c_mid};
    }
    // search in 1st half
    if (matrix[r_start][c_mid - 1] >= target)
    {
        return binarySearch(matrix, r_start, 0, c_mid - 1, target);
    }
    // search in 2nd half
    if (matrix[r_start][c_mid + 1] <= target && matrix[r_start][col - 1] >= target)
    {
        return binarySearch(matrix, r_start, c_mid + 1, col - 1, target);
    }
    // search in 3rd half
    if (matrix[r_start + 1][c_mid - 1] <= target)
    {
        return binarySearch(matrix, r_start + 1, 0, c_mid - 1, target);
    }
    else
    {
        return binarySearch(matrix, r_start + 1, c_mid + 1, col - 1, target);
    }
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