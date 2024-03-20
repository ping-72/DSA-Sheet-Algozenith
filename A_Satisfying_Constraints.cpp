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
// #define print_pair(a)           for(auto x : a) cout << x.F << " " << x.S << endl

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
    // #S -> O()
    // #T -> O()
    int n;
    cin >> n;
    int ans = 0;
    int grtr = INT_MAX, lessser = -1;
    set<int> nt_equal;

    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        if (a == 2)
            grtr = min(grtr, b);
        if (a == 1)
            lessser = max(lessser, b);
        if (a == 3)
            nt_equal.insert(b);
        // cout<<lessser<<" se "<<grtr<<endl;
    }

    if (grtr <= lessser)
    {
        if (grtr == lessser && nt_equal.find(grtr) == nt_equal.end())
        {
            cout << 1 << endl;
            return;
        }
        cout << 0 << endl;
        return;
    }

    else
    {
        int cnt = grtr - lessser + 1;
        for (auto v : nt_equal)
        {
            if (v >= lessser && v <= grtr)
            {
                cnt--;
            }
        }
        cout << cnt << endl;
        return;
    }
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