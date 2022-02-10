// an effective approach to search for an element in
// row wise sorted and column wise sorted Matrix

#include <iostream>
#include <vector>

using namespace std;
#define row 4
#define col 4

int arr[row][col] = {
    {10, 20, 30, 40},
    {15, 25, 35, 45},
    {27, 29, 37, 48},
    {32, 33, 39, 50}};

vector<int> row_col_search(int[row][col], int target)
{

    // matrix is empty
    if (col == 0)
        return {-1, -1};

    int r = 0;
    int c = col - 1;
    while (r < row && c >= 0)
    {
        if (arr[r][c] == target)
        {
            return {r, c};
        }
        else if (arr[r][c] > target)
        {
            c--;
        }
        else
        {
            r++;
        }
    }
    return {-1, -1};
}

int main(int argc, char const *argv[])
{
    int tar = 35;
    vector<int> result = row_col_search(arr, tar);
    for (int i = 0; i < 2; i++)
    {
        cout << result[i] << " ";
    }
    cout << "\n";

    return 0;
}
