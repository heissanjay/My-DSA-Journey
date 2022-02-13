// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        vector<int> ans = {-1, -1};
        ans[0] = search(nums, target, true);
        if (ans[0] != -1)
            ans[1] = search(nums, target, false);
        return ans;
    }
    int search(vector<int> &nums, int target, bool firstOccu)
    {
        int ans = -1;
        int s = 0;
        int e = nums.size() - 1;
        while (s <= e)
        {
            int m = s + (e - s) / 2;
            if (target < nums[m])
            {
                e = m - 1;
            }
            else if (target > nums[m])
            {
                s = m + 1;
            }
            else
            {
                ans = m;
                if (firstOccu)
                {
                    e = m - 1;
                }
                else
                {
                    s = m + 1;
                }
            }
        }
        return ans;
    }
};