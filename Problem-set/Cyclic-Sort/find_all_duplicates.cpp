// https://leetcode.com/problems/find-all-duplicates-in-an-array/

class Solution
{
public:
    vector<int> findDuplicates(vector<int> &nums)
    {
        int i = 0;
        while (i < nums.size())
        {
            int crt = nums[i] - 1;
            if (nums[i] != nums[crt])
            {
                swap(nums, i, crt);
            }
            else
            {
                i++;
            }
        }
        vector<int> result;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] != i + 1)
            {
                result.push_back(nums[i]);
            }
        }
        return result;
    }
};