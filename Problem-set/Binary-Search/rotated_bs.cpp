// https://leetcode.com/problems/search-in-rotated-sorted-array/

class Solution
{
public:
    // find pivot element
    int findPivot(vector<int> &arr)
    {
        int s = 0;
        int e = arr.size() - 1;

        while (s <= e)
        {
            int m = s + (e - s) / 2;
            if (m < e && arr[m] > arr[m + 1])
            {
                return m;
            }

            if (s > m && arr[m - 1] > arr[m])
            {
                return m - 1;
            }
            if (arr[m] <= arr[s])
            {
                e = m - 1;
            }
            else
            {
                s = m + 1;
            }
        }
        return -1;
    }
    // simple binary search
    int binarySearch(vector<int> &arr, int target, int start, int end)
    {
        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            if (arr[mid] == target)
            {
                return mid;
            }
            else if (arr[mid] < target)
            {
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }
        return -1;
    }