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

    int orderAgonsticBinarySearch(MountainArray &mountainArr, int target, int s, int e)
    {
        bool is_non_de = mountainArr.get(s) < mountainArr.get(e);

        while (s <= e)
        {
            int m = s + (e - s) / 2;

            if (target == mountainArr.get(m))
            {
                return m;
            }
            if (is_non_de)
            {
                if (mountainArr.get(m) < target)
                {
                    s = m + 1;
                }
                else
                {
                    e = m - 1;
                }
            }
            else
            {
                if (mountainArr.get(m) > target)
                {
                    s = m + 1;
                }
                else
                {
                    e = m - 1;
                }
            }
        }
        return -1;
    }
    int findInMountainArray(int target, MountainArray &mountainArr)
    {
        int p = peakIndexInMountainArray(mountainArr);
        int f = orderAgonsticBinarySearch(mountainArr, target, 0, p);
        if (f != -1)
            return f;
        return orderAgonsticBinarySearch(mountainArr, target, p + 1, mountainArr.length() - 1);
    }
};