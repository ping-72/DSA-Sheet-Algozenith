#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

ll gcd(ll a, ll b) { 
    if (a == 0 || b == 0) return a + b; 
    return gcd(b, a % b); 
}

ll lcm(ll a, ll b) { 
    return (b / gcd(a, b)) * a; 
}

bool primecheck(ll n) {
    if (n == 2) return 1;
    if (n == 1) return 0;
    for (ll i = 2; i * i <= n; i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}

ll binary_exponentiation(ll a, ll b, ll mod) {
    ll ans = 1;
    while (b) {
        if (b % 2 == 1) {
            ans = (ans * a) % mod;
        }
        a = (a * a) % mod;
        b = b / 2;
    }
    return ans % mod;
}

ll inv(ll x, ll mod) {
    return binary_exponentiation(x, mod - 2, mod);
}

ll add(ll a, ll b, ll mod) {
    return (mod + (a % mod + b % mod) % mod) % mod;
}

ll sub(ll a, ll b, ll mod) {
    return (mod + (a % mod - b % mod) % mod) % mod;
}

ll mul(ll a, ll b, ll mod) {
    return (mod + (a % mod * b % mod) % mod) % mod;
}

ll div(ll a, ll b, ll mod) {
    return (mod + (a % mod * inv(b, mod) % mod) % mod) % mod;
}

void solve(){
        int n, x;
        cin >> n >> x;

        long long tripletCount = 0;
        for (int a = 1; a <= x; ++a) {
            int maxB = min(x - a, n / a);
            for (int b = 1; b <= maxB; ++b) {
                int maxC = min(x - a - b, (n - a * b) / (a + b));
                tripletCount += max(0, maxC);
            }
        }

        cout << tripletCount << "\n";
    }


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); 
    cout.tie(0);
    
    int t; 
    cin >> t; 
    while (t--) {
        solve();
    } 
    return 0;
}
