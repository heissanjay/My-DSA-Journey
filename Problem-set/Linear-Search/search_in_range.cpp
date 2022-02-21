// we will provided with an array and target and range to search for the target
// if target presents in the range return index else return -1.

#include <iostream>
#include <vector>
using namespace std;

vector<int> arr = {23, 56, 78, 34, 15, 89};
int searchInRange(vector<int> &nums, int target, int s, int e)
{
    if (nums.size() == 0)
        return -1;

    for (int i = s; i <= e; i++)
    {
        if (target == nums[i])
        {
            return i;
        }
    }
    return -1;
}
int main(int argc, char const *argv[])
{
    cout << searchInRange(arr, 12, 1, 4) << "\n";
    return 0;
}
