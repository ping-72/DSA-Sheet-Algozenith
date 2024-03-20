class Solution
{
public:
    vector<string> shortestSubstrings(vector<string> &arr)
    {

        vector<string> ans(arr.size());
        for (int i = 0; i < arr.size(); i++)
        {
            ans[i] = "";
        }

        map<string, long long> mp;
        for (int i = 0; i < arr.size(); i++)
        {
            string s = arr[i];
            set<string> st;

            for (int j = 0; j < s.length(); j++)
            {
                for (int k = 1; j + k <= s.length(); k++)
                {
                    st.insert(s.substr(j, k));
                }
            }
            for (auto &s1 : st)
            {
                cout << s1 << " ";
                mp[s1]++;
            }
        }

        for (int i = 0; i < arr.size(); i++)
        {
            string s = arr[i];
            set<string> st;

            for (int j = 0; j < s.length(); j++)
            {
                for (int k = 1; j + k <= s.length(); k++)
                {
                    st.insert(s.substr(j, k));
                }
            }
            for (auto &s1 : st)
            {
                if (mp[s1] == 1)
                {
                    ans[i] = s1;
                    break;
                }
            }
        }
        return ans;
    }
};