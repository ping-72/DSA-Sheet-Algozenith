#include <bits/stdc++.h>
using namespace std;

#define ll long long
ll mod = 1e9 + 7;
#define endl '\n'
#define F first
#define S second
#define print(a)          \
    for (auto x : a)      \
        cout << x << " "; \
    cout << endl
#define print_pair(a) \
    for (auto x : a)  \
    cout << x.F << " " << x.S << endl

ll gcd(ll a, ll b)
{
    if (a == 0 || b == 0)
        return a + b;
    return gcd(b, a % b);
}
ll lcm(ll a, ll b) { return (b / gcd(a, b)) * a; }

bool primecheck(ll n)
{
    if (n == 2)
        return 1;
    if (n == 1)
        return 0;
    for (ll i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return 0;
    }
    return 1;
}

ll binary_exponentiation(ll a, ll b, ll mod)
{
    ll ans = 1;
    while (b)
    {
        if (b % 2 == 1)
        {
            ans = (ans * a) % mod;
        }
        a = (a * a) % mod;
        b = b / 2;
    }
    return ans % mod;
}

ll inv(ll x, ll mod) { return binary_exponentiation(x, mod - 2, mod); }
ll add(ll a, ll b, ll mod) { return (mod + (a % mod + b % mod) % mod) % mod; }
ll sub(ll a, ll b, ll mod) { return (mod + (a % mod - b % mod) % mod) % mod; }
ll mul(ll a, ll b, ll mod) { return (mod + (a % mod * b % mod) % mod) % mod; }
ll div(ll a, ll b, ll mod) { return (mod + (a % mod * inv(b, mod) % mod) % mod) % mod; }

int dp[105][105][105];
string s1, s2, s3;

int rec(int a, int b, int c)
{
    if (a == -1 || b == -1 || c == -1)
        return 0;
    if (dp[a][b][c] != -1)
        return dp[a][b][c];

    if (s1[a] == s2[b] && s2[b] == s3[c])
    {
        return dp[a][b][c] = 1 + rec(a - 1, b - 1, c - 1);
    }
    else
    {
        return dp[a][b][c] = max(max(rec(a - 1, b, c), rec(a, b - 1, c)), rec(a, b, c - 1));
        // dp[i][j][k] = max(max(lcsOf3(i-1,j,k),lcsOf3(i,j-1,k)),lcsOf3(i,j,k-1));
    }
}
void solve()
{
    // #S -> O(n*m*o)
    // #T -> O(n*m*o)
    cin >> s1 >> s2 >> s3;
    memset(dp, -1, sizeof(dp));

    int m = s1.size();
    int n = s2.size();
    int o = s3.size();

    cout << rec(m - 1, n - 1, o - 1) << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll _t;
    cin >> _t;
    while (_t--)
        solve();
    return 0;
}