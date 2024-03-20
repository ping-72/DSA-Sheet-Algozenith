class Solution
{
public:
    string minimizeStringValue(string s)
    {
        int n = s.length();
        string ans, s1, str;
        ans = s;
        int charCount[27]; // Count the no of times a character occured in the string
        set<pair<int, char>> pq;

        // Inserting the pair with {0, character}
        for (int i = 0; i < 26; i++)
        {
            pq.insert({0, 'a' + i});
        }

        for (int i = 0; i < n; i++)
        {
            if (s[i] == '?')
            {
            }
            else
            {
                char b = s[i];
                pq.erase(pq.find({charCount[(b - 'a') + 1], b}));
                charCount[(b - 'a') + 1]++;
                pq.insert({charCount[(b - 'a') + 1], b});
            }
        }

        //         // for (int i = 0; i < 26; i++)
        //         // {
        //         //     pq.insert({0, 'a' + i});
        //         // }

        for (int i = 0; i < n; i++)
        {
            if (s[i] == '?')
            {
                auto it = pq.begin();
                int a = it->first;
                char b = it->second;
                a++;
                s[i] = b;
                charCount[b + 1 - 'a']++;
                str.push_back(b);
                pq.erase(pq.begin());
                pq.insert({a, b});
            }
        }

        sort(str.begin(), str.end());
        for (int i = 0; i < str.size(); i++)
        {
            cout << str[i];
        }
        cout << endl;
        int k = 0;
        for (int i = 0; i < n; i++)
        {
            if (ans[i] == '?')
            {
                ans[i] = str[k];
                k++;
            }
        }
        return ans;
    }
};