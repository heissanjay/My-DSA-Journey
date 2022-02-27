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
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] != i + 1)
            {
                return {nums[i], i + 1};
            }
        }
        return {-1, -1};
    }
    void swap(vector<int> &nums, int cur, int crt)
    {
        int temp = nums[cur];
        nums[cur] = nums[crt];
        nums[crt] = temp;
    }
};