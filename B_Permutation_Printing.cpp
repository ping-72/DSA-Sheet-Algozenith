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

void solve()
{
    ll n;
    cin >> n;
    ll i = 1;
    ll j = n;
    if (n % 2)
    {
        int i1;
        for (i1 = 0; i1 < n / 2; i1++)
            cout << n - i1 << " " << i1 + 1 << " ";
        cout << n - i1 << " ";
    }
    else
    {
        for (int i1 = 0; i1 < n / 2; i1++)
            cout << n - i1 << " " << i1 + 1 << " ";
    }
    cout << '\n';
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    // solve();
    return 0;
}