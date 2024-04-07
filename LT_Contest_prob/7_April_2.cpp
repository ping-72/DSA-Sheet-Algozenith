class Solution
{
public:
    long long minOperationsToMakeMedianK(vector<int> &nums, int k)
    {
        int n = nums.size();
        int ans = 0;
        if ((n % 2))
        { // odd hai
            sort(nums.begin(), nums.end());
            if (k > nums[n / 2])
            {
                for (int i = n / 2; (i < n && k > nums[i]); i++)
                {
                    ans += (k - nums[i]);
                }
            }
            else if (k < nums[n / 2])
            {
                for (int i = n / 2; (i >= 0 && k < nums[i]); i--)
                {
                    ans += (nums[i] - k);
                }
            }
        }
        else
        { // even number
            sort(nums.begin(), nums.end());
            if (k > (nums[n / 2] + nums[n / 2 + 1]) / 2)
        }
        return ans;
    }
};