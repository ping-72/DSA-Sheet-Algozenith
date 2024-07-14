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

int n;
int range(int st, int end, ll Tot, vector<int> &a, vector<int> &b, vector<int> &c, char curr)
{
    ll sum = 0;
    long double tot = (1.0 * Tot) / 3;
    while (st <= end && sum < tot)
    {
        if (curr == 'a')
        {
            sum += a[st++];
        }
        if (curr == 'b')
        {
            sum += b[st++];
        }
        if (curr == 'c')
        {
            sum += c[st++];
        }
    }
    if (sum < tot)
        return -1;

    return st - 1;
}

struct Range
{
    int l;
    int r;
};

void solve()
{
    // #S -> O()
    // #T -> O()
    cin >> n;
    vector<int> a(n + 1), b(n + 1), c(n + 1);
    Range A, B, C;

    ll tot = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i + 1];
        tot += a[i + 1];
    }
    for (int i = 0; i < n; i++)
        cin >> b[i + 1];
    for (int i = 0; i < n; i++)
        cin >> c[i + 1];

    // a b c
    {
        A.l = 1;
        A.r = range(A.l, n, tot, a, b, c, 'a');

        // abc
        {
            B.l = A.r + 1;
            B.r = range(B.l, n, tot, a, b, c, 'b');
            if (B.r != -1)
            {
                C.l = B.r + 1;
                C.r = range(C.l, n, tot, a, b, c, 'c');
                if (C.r != -1)
                {
                    C.r = n;
                    cout << A.l << " " << A.r << " " << B.l << " " << B.r << " " << C.l << " " << C.r << endl;
                    return;
                }
            }
        }

        // a c b
        {
            C.l = A.r + 1;
            C.r = range(C.l, n, tot, a, b, c, 'c');
            if (C.r != -1)
            {
                B.l = C.r + 1;
                B.r = range(B.l, n, tot, a, b, c, 'b');
                if (B.r != -1)
                {
                    B.r = n;
                    cout << A.l << " " << A.r << " " << B.l << " " << B.r << " " << C.l << " " << C.r << endl;
                    return;
                }
            }
        }
    }

    // b a c
    {
        B.l = 1;
        B.r = range(B.l, n, tot, a, b, c, 'b');

        // bac
        {
            A.l = B.r + 1;
            A.r = range(A.l, n, tot, a, b, c, 'a');
            if (A.r != -1)
            {
                C.l = A.r + 1;
                C.r = range(C.l, n, tot, a, b, c, 'c');
                if (C.r != -1)
                {
                    C.r = n;
                    cout << A.l << " " << A.r << " " << B.l << " " << B.r << " " << C.l << " " << C.r << endl;
                    return;
                }
            }
        }

        // bca
        {
            C.l = B.r + 1;
            C.r = range(C.l, n, tot, a, b, c, 'c');
            if (C.r != -1)
            {
                A.l = C.r + 1;
                A.r = range(A.l, n, tot, a, b, c, 'a');
                if (A.r != -1)
                {
                    A.r = n;
                    cout << A.l << " " << A.r << " " << B.l << " " << B.r << " " << C.l << " " << C.r << endl;
                    return;
                }
            }
        }
    }

    // c b a
    {
        C.l = 1;
        C.r = range(C.l, n, tot, a, b, c, 'c');

        // cba
        {
            B.l = C.r + 1;
            B.r = range(B.l, n, tot, a, b, c, 'b');
            if (B.r != -1)
            {
                A.l = B.r + 1;
                A.r = range(A.l, n, tot, a, b, c, 'a');
                if (A.r != -1)
                {
                    A.r = n;
                    cout << A.l << " " << A.r << " " << B.l << " " << B.r << " " << C.l << " " << C.r << endl;
                    return;
                }
            }
        }

        // cab
        {
            // c a b
            A.l = C.r + 1;
            A.r = range(A.l, n, tot, a, b, c, 'a');
            if (A.r != -1)
            {
                B.l = A.r + 1;
                B.r = range(B.l, n, tot, a, b, c, 'b');
                if (B.r != -1)
                {
                    B.r = n;
                    cout << A.l << " " << A.r << " " << B.l << " " << B.r << " " << C.l << " " << C.r << endl;
                    return;
                }
            }
        }
    }

    cout << -1 << endl;
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
