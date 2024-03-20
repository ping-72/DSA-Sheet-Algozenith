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

// *********************
// We need to find out the longest common
// substring between string s and reverse string of s ,
// and the rest needs to be added to make a  pallindrome
// *********************

string s, s_rev;

void reverse_str(string &s1)
{
    int n = s1.length();
    for (int i = 0; i < n / 2; i++)
    {
        swap(s1[i], s1[n - i - 1]);
    }
}

int lcs(int a, int b)
{
    int L[a + 1][b + 1];
    int i, j;

    for (i = 0; i <= a; i++)
    {
        for (j = 0; j <= b; j++)
        {
            if (i == 0 || j == 0)
            {
                L[i][j] = 0;
            }
            else if (s[i - 1] == s_rev[j - 1])
            {
                L[i][j] = L[i - 1][j - 1] + 1;
            }
            else
            {
                L[i][j] = max(L[i - 1][j], L[i][j - 1]);
            }
        }
    }
    return L[a][b];
}

void solve()
{
    // #S -> O(n^2)
    // #T -> O(n^2)
    cin >> s;
    int n = s.length();
    s_rev = s;

    reverse_str(s_rev);
    // cout << lcs(n, n) << endl;
    cout << (n - lcs(n, n)) << endl;
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