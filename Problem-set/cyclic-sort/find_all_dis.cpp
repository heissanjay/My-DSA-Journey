// https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/

class Solution
{
public:
    vector<int> findDisappearedNumbers(vector<int> &nums)
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
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] != i + 1)
            {
                ans.push_back(i + 1);
            }
        }
        return ans;
    }
};