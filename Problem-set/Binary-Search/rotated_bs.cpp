// https://leetcode.com/problems/search-in-rotated-sorted-array/

class Solution
{
public:
    // find pivot element
    int findPivot(vector<int> arr)
    {
        int start = 0;
        int end = arr.size() - 1;
        while (start <= end)
        {
            int mid = start + (end - start) / 2;

            if (mid < end && arr[mid] > arr[mid + 1])
            {
                return mid;
            }
            if (mid > start && arr[mid] < arr[mid - 1])
            {
                return mid - 1;
            }
            if (arr[mid] <= arr[start])
            {
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
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
    int search(vector<int> &nums, int target)
    {
        int piv = findPivot(nums);
        // array is not rotated
        if (piv == -1)
        {
            return binarySearch(nums, target, 0, nums.size() - 1);
        }
        if (nums[piv] == target)
            return piv;

        if (target >= nums[0])
        {
            return binarySearch(nums, target, 0, piv - 1);
        }
        else
        {
            return binarySearch(nums, target, piv + 1, nums.size() - 1);
        }
    }
};