class Solution
{
public:
    int earliestSecondToMarkIndices(vector<int> &nums, vector<int> &changeIndices)
    {
        int n = nums.size();
        int m = changeIndices.size();
        vector<bool> set(n, false);
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            if (nums[i] == 0)
                set[i] = true;
        }
        if (sum > m)
            return -1;

        map<int, int> mp;
        for (int i = 0; i < changeIndices.size(); i++)
        {
            mp[changeIndices[i]]++;
        }

        for (int i = 0; i < changeIndices.size(); i++)
        {
            int s = changeIndices[i];
            if (nums[s] == 0)
                set[s] == true;
        }
    }
};