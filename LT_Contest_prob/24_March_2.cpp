class Solution
{

public:
    int minOperations(int k)
    {
        int ans = 1e9;
        if (k == 1)
            return 0;
        for (int i = 1; i < k; i++)
        {
            ans = min(ans, ((i - 1) + ((k % i) ? (k / i) : ((k / i) - 1))));
        }
        return ans;
    }
};