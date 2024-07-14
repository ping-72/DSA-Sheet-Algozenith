#include <bits/stdc++.h>
using namespace std;

void findTopoSort(int node, vector<int> &vis, stack<int> &st, vector<vector<int>> &adj)
{
    vis[node] = 1;

    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            findTopoSort(it, vis, st, adj);
        }
    }
    st.push(node);
}

vector<int> topo(int N, vector<vector<int>> &adj)
{
    stack<int> st;
    vector<int> vis(N + 1, 0);
    for (int i = N; i > 0; i--)
    {
        if (vis[i] == 0)
        {
            findTopoSort(i, vis, st, adj);
        }
    }
    vector<int> topo;
    while (!st.empty())
    {
        topo.push_back(st.top());
        st.pop();
    }
    return topo;
}

void solve()
{
    // #S -> O()
    // #T -> O()

    int n;
    cin >> n;

    string s[n + 1];
    map<string, int> mp;

    for (int i = 1; i <= n; i++)
    {
        cin >> s[i];
        mp[s[i]] = i;
    }

    vector<vector<int>> g(n + 1);
    int m;
    cin >> m;
    while (m--)
    {
        string a, b;
        cin >> a >> b;
        // cout << mp[b] << " " << mp[a] << endl;
        g[mp[a]].push_back(mp[b]);
    }
    cout << endl;

    vector<int> v;
    // Topo Sort
    v = topo(n, g);

    for (auto l : v)
    {
        cout << s[l] << " ";
    }
    cout << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    long long _t;
    cin >> _t;
    while (_t--)
        solve();
    return 0;
}
