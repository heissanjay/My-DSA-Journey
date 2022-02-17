// https://leetcode.com/problems/find-in-mountain-array/

class Solution
{
public:
    int peakIndexInMountainArray(MountainArray &mountainArr)
    {
        int s = 0;
        int e = mountainArr.length() - 1;

        while (s < e)
        {
            int m = s + (e - s) / 2;
            if (mountainArr.get(m) > mountainArr.get(m + 1))
            {
                e = m;
            }
            else
            {
                s = m + 1;
            }
        }
        return s;
    }
}