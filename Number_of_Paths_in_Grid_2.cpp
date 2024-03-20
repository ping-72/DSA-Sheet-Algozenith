#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define MP make_pair
#define mod 1000000007ll
#define endl '\n'
#define all(v) (v).begin(), (v).end()
#define pb push_back
#define tzll(x) __builtin_ctzll(x)
#define lzll(x) __builtin_clzll(x)
#define lz(x) __builtin_clz(x)
#define tz(x) __builtin_ctz(x)
#define popc(x) __builtin_popcount(x)
#define popcll(x) __builtin_popcountll(x)
#define ss second
#define pi pair<int, int>
#define ff first
#define si set<long long>
#define spi set<pair<int, int>>
#define msi multiset<long long>
#define vi vector<long long>
#define vc vector<char>
#define vvi vector<vector<int>>
#define vvc vector<vector<char>>
#define vpii vector<pair<long long, long long>>
#define input(v)       \
    for (auto &it : v) \
    cin >> it
#define output(v)      \
    for (auto &it : v) \
    cout << it << " "
ll powmod(ll a, ll b)
{
    ll res = 1;
    a %= mod;
    assert(b >= 0);
    for (; b; b >>= 1)
    {
        if (b & 1)
            res = res * a % mod;
        a = a * a % mod;
    }
    return res;
}
long long gcd(long long a, long long b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
int n, m, k;
vvi v;
int dp[205][205][403];
int rec(int i, int j, int k)
{
    if (i >= n || j >= m)
        return 0;
    if (k <= 0 && v[i][j] == 1)
        return 0;
    if (i == n - 1 && j == m - 1)
    {
        return 1;
    }
    if (dp[i][j][k] != -1)
        return dp[i][j][k];
    int ans = 0;
    // if current cell blocked
    if (v[i][j] == 1 && k >= 1)
    {
        ans += (rec(i + 1, j, k - 1)) % mod;
        ans += (rec(i, j + 1, k - 1)) % mod;
    }
    else if (v[i][j] == 0) // if not blocked
    {
        ans += (rec(i + 1, j, k)) % mod;
        ans += (rec(i, j + 1, k)) % mod;
    }
    return dp[i][j][k] = ans % mod;
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> m >> k;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; ++j)
            {
                for (int l = 0; l <= k; ++l)
                    dp[i][j][l] = -1;
            }
        }
        v.clear();
        v.assign(n, vi(m, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                int x;
                cin >> x;
                v[i][j] = x;
            }
        }
        cout << rec(0, 0, k) % mod << endl;
    }
}