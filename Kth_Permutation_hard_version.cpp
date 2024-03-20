#include <bits/stdc++.h>
using namespace std;
#define IOS                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);

void func(int k, vector<int> &arr)
{
    int n = (int)arr.size();
    k--;
    vector<int> ans;
    int fact = 1;
    for (int i = 1; i < n; i++)
    {
        fact = i * fact;
    }
    while (1)
    {
        ans.push_back(arr[k / fact]);
        arr.erase(arr.begin() + k / fact);
        if ((int)arr.size() == 0)
            break;
        k %= fact;
        fact /= (int)arr.size();
    }
    for (auto i : ans)
    {
        cout << i << " ";
    }
    cout << "\n";
}

void solve()
{
    int n, k;
    cin >> n >> k;
    if (n <= 13)
    {
        vector<int> arr;
        for (int i = 1; i <= n; i++)
        {
            arr.push_back(i);
        }
        func(k, arr);
    }
    else
    {
        vector<int> arr;
        for (int i = 1; i < n - 12; i++)
        {
            cout << i << " ";
        }
        for (int i = n - 12; i <= n; i++)
        {
            arr.push_back(i);
        }
        func(k, arr);
    }
}

signed main()
{
    IOS;
    solve();
    return 0;
}
