//  https://leetcode.com/problems/find-the-duplicate-number/

class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        int i = 0;
        while (i < nums.size())
        {
            if (nums[i] != i + 1)
            {
                int crt = nums[i] - 1;
                if (nums[i] != nums[crt])
                {
                    swap(nums, i, crt);
                }
                else
                {
                    return nums[i];
                }
            }
            else
            {
                i++;
            }
        }
        return -1;
    }
    void swap(vector<int> &arr, int cur, int crt)
    {
        int temp = arr[cur];
        arr[cur] = arr[crt];
        arr[crt] = temp;
    }
};