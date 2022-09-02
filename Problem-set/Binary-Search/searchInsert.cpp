// https://leetcode.com/problems/search-insert-position/

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int s = 0;
        int e = nums.size() - 1;
        
        while( s <= e){
            int m = (s + e) / 2;
            if(target < nums[m]){
                e = m - 1;
            }else if(target > nums[m]){
                s = m + 1;
            }else{
                return m;
            }
        }
        return s;
    }
};