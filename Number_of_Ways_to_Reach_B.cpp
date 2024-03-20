#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define LD long double

const int N = 200010;

int inf = 1e9;
int mod = 1e9 + 7;

ll factorialNumInverse[N+1];
ll naturalNumInverse[N+1];
ll fact[N+1];

// Function to precompute inverse of numbers
void InverseofNumber(ll p){
    naturalNumInverse[0] = naturalNumInverse[1] = 1;
    for (int i = 2; i <= N; i++)
        naturalNumInverse[i] = naturalNumInverse[p % i] * (p - p / i) % p;
}
// Function to precompute inverse of factorials
void InverseofFactorial(ll p){
    factorialNumInverse[0] = factorialNumInverse[1] = 1;
 
    // precompute inverse of natural numbers
    for (int i = 2; i <= N; i++)
        factorialNumInverse[i] = (naturalNumInverse[i] * factorialNumInverse[i - 1]) % p;
}
 
// Function to calculate factorial of 1 to N
void factorial(ll p){
    fact[0] = 1;
 
    // precompute factorials
    for (int i = 1; i <= N; i++) {
        fact[i] = (fact[i - 1] * i) % p;
    }
}
 
// Function to return nCr % p in O(1) time
ll Binomial(ll N, ll R, ll p){
    // n C r = n!*inverse(r!)*inverse((n-r)!)
    ll ans = (((fact[N] %p) * (factorialNumInverse[R] % p))
              % p * (factorialNumInverse[N - R] % p)) % p;
    return ans;
}

void solve(){
    ll n,ans,m;
    cin>>n>>m;
    // (m+n)!/ m! * n! 
    ans = Binomial(n+m,m,mod);   
    cout<<ans<<endl;

}

signed main() {
  // freopen("IN", "r", stdin);
  // freopen("OUT", "w", stdout);

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
int _t;cin>>_t;while(_t--)
solve();
 
  return 0;
}