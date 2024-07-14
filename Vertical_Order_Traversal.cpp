
#include <bits/stdc++.h>
using namespace std;

#define ll int64_t
#define endl '\n'

struct TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x)
    {
        this->data = x;
        this->left = nullptr;
        this->right = nullptr;
    }
};

class Solution
{

public:
    vector<vector<int>> verticalTraversal(TreeNode *root)
    {
        queue<pair<TreeNode *, pair<int, int>>> q;
        map<int, map<int, multiset<int>>> mp;

        q.push({root, {0, 0}});

        while (!q.empty())
        {
            auto it = q.front();
            q.pop();

            TreeNode *node = it.first;
            int verticle = it.second.first;
            int lvl = it.second.second;

            mp[verticle][lvl].insert(node->data);

            if (node->left)
            {
                q.push({node->left, {verticle - 1, lvl + 1}});
            }
            if (node->right)
            {
                q.push({node->right, {verticle + 1, lvl + 1}});
            }
        }

        vector<vector<int>> ans;

        for (auto m : mp)
        {
            vector<int> each_lvl;
            for (auto in_map_map : m.second)
            {
                each_lvl.insert(each_lvl.end(), in_map_map.second.begin(), in_map_map.second.end());
            }
            ans.push_back(each_lvl);
        }
        return ans;
    }
};

TreeNode *deserialize(string data)
{
    if (data.size() == 0)
        return nullptr;
    vector<string> dat;
    string t;
    for (auto c : data)
    {
        if (c == ',')
        {
            dat.push_back(t);
            t.clear();
        }
        else
            t.push_back(c);
    }
    dat.push_back(t);
    int i = 0;
    queue<TreeNode *> q;
    TreeNode *root = new TreeNode(stoll(dat[0]));
    q.push(root);
    auto cur = root;
    i++;
    while (!q.empty())
    {
        auto x = q.front();
        q.pop();
        if (dat[i] != "x")
        {
            x->left = new TreeNode(stoll(dat[i]));
            q.push(x->left);
        }
        i++;
        if (dat[i] != "x")
        {
            x->right = new TreeNode(stoll(dat[i]));
            q.push(x->right);
        }
        i++;
    }
    return root;
}

void solve()
{
    string tr;
    cin >> tr;
    Solution sol;
    auto root = deserialize(tr);
    auto ans = sol.verticalTraversal(root);
    for (auto x : ans)
    {
        for (auto y : x)
            cout << y << " ";
        cout << endl;
    }
    cout << endl;
}
int main()
{
    ios_base ::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

#ifdef Mastermind_
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t = 1;
    // int i = 1;
    cin >> t;
    while (t--)
    {
        // cout << "Case #" << i << ": ";
        solve();
        // i++;
    }
    return 0;
}
