// find the minimum value in an array
// find the maximum value in an array
#include <iostream>
#include <vector>
using namespace std;

vector<int> arr = {23, 56, 78, 34, 15, 89};
int findMin(vector<int> &nums)
{
    int ans = nums[0];

    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] < ans)
        {
            ans = nums[i];
        }
    }
    return ans;
}
int findMax(vector<int> &nums)
{
    int ans = nums[0];

    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] > ans)
        {
            ans = nums[i];
        }
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    cout << findMin(arr) << "\n";
    cout << findMax(arr) << "\n";
    return 0;
}
