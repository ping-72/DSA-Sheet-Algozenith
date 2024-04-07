class Solution
{
public:
    int longestMonotonicSubarray(vector<int> &nums)
    {
        int n = nums.size();
        int ans = 1;

        for (int i = 0; i < n; i++)
        {
            int j = i + 1;
            int cnt = 1;
            while (j < n && nums[j] > nums[j - 1])
            { // strictly decreasing
                cnt++;
                j++;
            }
            ans = max(ans, cnt);

            int j = i + 1;
            int cnt = 1;
            while (j < n && nums[j] < nums[j - 1])
            { // strictly increasing
                cnt++;
                j++;
            }
            ans = max(ans, cnt);
        }

        return ans;
    }
};