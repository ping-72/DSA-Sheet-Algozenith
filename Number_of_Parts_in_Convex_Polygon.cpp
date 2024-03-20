// Soln 1:
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long int
const int mod = 1e9 + 7;

int inv(int a, int b = mod - 2) {
  int ans = 1;
  while (b) {
    if (b & 1) ans = (ans * a) % mod;
    a = (a * a) % mod;
    b /= 2;
  }
  return ans;
}

int inv2 = inv(2);
int inv24 = inv(24);

void solve() {
  int n;
  cin >> n;
  int ans = 1;
  for (int i = 0; i < 4; i++) ans = (ans * (n - i)) % mod;
  ans = (ans * inv24) % mod;
  int temp = (n * (n - 1)) % mod;
  ans = (ans + 1 + (temp * inv2) % mod);
  ans -= n;
  cout << (ans % mod + mod) % mod << endl;
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}


// Soln 2:
#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define LD long double

const int N = 100010;

int inf = 1e9;
int mod = 1e9 + 7;


ll power(ll x, int y, int p){
	ll res = 1;
	x = x % p; 
	while (y > 0) 
	{
		if (y & 1)
			res = (res * x) % p;

		
		y = y >> 1; // y = y/2
		x = (x * x) % p;
	}
	return res;
}

ll modInverse(ll n, int p){
	return power(n, p - 2, p);
}


ll nCrModPFermat(ll n, int r, int p){	
	if (n < r)
		return 0;

	if (r == 0)
		return 1;

	ll fac[n + 1];
	fac[0] = 1;
	for (int i = 1; i <= n; i++)
		fac[i] = (fac[i - 1] * i) % p;

	return (fac[n] * modInverse(fac[r], p) % p
			* modInverse(fac[n - r], p) % p)
		% p;
}


void solve(){
// formula
// Total number of parts = (1+((nC2) − N)+(nC4))%1000000007
ll n;
cin>>n;
ll nC2 = nCrModPFermat( n, 2, mod);
ll nC4 = nCrModPFermat( n, 4, mod);
ll ans = (1+((nC2) - n) + nC4 ) % mod;
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


