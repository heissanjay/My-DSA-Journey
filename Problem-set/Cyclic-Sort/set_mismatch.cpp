//  https://leetcode.com/problems/set-mismatch/'

class Solution
{
public:
    vector<int> findErrorNums(vector<int> &nums)
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