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

        while (num > 0)
        {
            ans++;
            num /= 10;
        }
        return ans;
    }
};