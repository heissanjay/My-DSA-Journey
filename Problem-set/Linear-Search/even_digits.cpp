// https://leetcode.com/problems/find-numbers-with-even-number-of-digits

class Solution
{
public:
    int findNumbers(vector<int> &nums)
    {
        int count = 0;
        for (int num : nums)
        {
            if (isEven(num))
            {
                count++;
            }
        }
        return count;
    }
    bool isEven(int n)
    {
        int digits = findDigits(n);
        return digits % 2 == 0;
    }
    int findDigits(int num)
    {
        int ans = 0;
        // if negative number
        //  if(num < 0) num*=-1;  convert negative number to positive

        // if (num == 0) return 1;
        while (num > 0)
        {
            ans++;
            num /= 10;
        }
        return ans;
    }
};