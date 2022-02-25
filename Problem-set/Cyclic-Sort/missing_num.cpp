// https://leetcode.com/problems/missing-number/

class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        int i = 0;
        while (i < nums.size())
        {
            int crt = nums[i];
            if (nums[i] < nums.size() && nums[i] != nums[crt])
            {
                swap(nums, i, crt);
            }
            else
            {
                i++;
            }
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] != i)
            {
                return i;
            }
        }

        return nums.size();
    }
    void swap(vector<int> &arr, int a, int b)
    {
        int temp = arr[a];
        arr[a] = arr[b];
        arr[b] = temp;
    }
};