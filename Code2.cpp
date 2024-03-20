class Solution
{
private:
    vector<int> arr;
    int dp[2005][2005][2005];

public:
    int rec(int sum, int i, int j)
    {
        if (i >= j)
            return 0;

        int a = 0, b = 0, c = 0;
        if (arr[i] + arr[i + 1] == sum)
        {
            a = rec(sum, i + 2, j);
        }
        if (arr[j] + arr[j - 1] == sum)
        {
            b = rec(sum, i, j - 2);
        }
        if (arr[i] + arr[j] == sum)
        {
            c = rec(sum, i + 1, j - 1);
        }

        return max(a, max(b, c));
    }

    int maxOperations(vector<int> &nums)
    {
        arr.resize(nums.size());
        int n = nums.size();
        for (int i = 0; i < nums.size(); i++)
        {
            arr[i] = nums[i];
        }
        int a = rec(arr[0] + arr[1], 2, n - 1);
        int b = rec(arr[n - 2] + arr[n - 1], 0, n - 3);
        int c = rec(arr[0] + arr[n - 1], 1, n - 2);

        return (max(a, max(b, c)));
    }
};