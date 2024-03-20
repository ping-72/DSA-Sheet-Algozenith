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

// int dp[100010][5];
// int cnt_str[100010];
int n;
string t = "0100";

int pw(int a, int b, int p)
{
    if (b == 0)
        return 1;
    int t = pw(a, b / 2, p);
    t = (t * t) % p;
    if (b % 2)
        return (a * t) % p;
    return t;
}

int dp[1000100][5];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    dp[0][0] = 1;
    for (int i = 1; i <= 1000000; ++i)
    {
        for (int j = 0; j <= 4; ++j)
        {
            // 0100
            vector<int> v;
            if (j == 0)
            {
                v = {0, 2};
            }
            else if (j == 1)
            {
                v = {0, 1};
            }
            else if (j == 2)
            {
                v = {1, 3};
            }
            else if (j == 3)
            {
                v = {2};
            }
            else
            {
                v = {3, 4, 4};
            }
            for (int k : v)
            {
                dp[i][j] = (dp[i][j] + dp[i - 1][k]) % mod;
            }
        }
    }
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        cout << (pw(2, n, mod) - dp[n][4] + mod) % mod << endl;
    }
    return 0;
}