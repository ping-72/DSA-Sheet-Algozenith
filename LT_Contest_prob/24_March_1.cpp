class Solution
{
public:
    int maximumLengthSubstring(string s)
    {
        int l = 0, r = 0;
        int res = 0;
        map<char, int> mp;
        while (r < s.length())
        {
            mp[s[r]]++;

            while (mp[s[r]] > 2)
            {
                mp[s[l]]--;
                if (mp[s[l]] == 0)
                {
                    mp.erase(s[l]);
                }
                l++;
            }
            res = max(res, r - l + 1);
            r++;
        }
        return res;
    }
};