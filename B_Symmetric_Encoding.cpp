#include <bits/stdc++.h>
using namespace std;

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        unordered_map<char, int> st;
        for (auto it : s)
        {
            st[it]++;
        }
        string match = "";
        for (auto it : st)
        {
            match += it.first;
        }

        sort(match.begin(), match.end());
        cout << match << endl;
        unordered_map<char, int> mp;
        for (int i = 0; i < match.size(); i++)
        {
            mp[match[i]] = i + 1;
        }
        // string ans = "";
        for (int i = 0; i < n; i++)
        {
            cout << match[-mp[s[i]] + match.size()];
        }
    }
    return 0;
}