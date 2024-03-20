#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define LD long double

const int N = 100010;

int inf = 1e9;
int mod = 1e9 + 7;


void solve(){
    ll n,q,ans=0; cin>>n>>q;
    ll A[n+1],prefix_sum[n+1],B[n+1];

    for(int i=0;i<=n;i++){
        prefix_sum[i] = 0;
        B[i] = 0;
    }

    for(int i=1;i<=n;i++){
        cin>>A[i];
        
        prefix_sum[i] = ((A[i] + prefix_sum[i-1] ) );
        prefix_sum[i] %= mod;


        B[i] = ( A[i]*(i) ) % mod;
        B[i] += B[i-1]; 
        B[i] %= mod;
    }

    for (int i=0;i<q;i++){
        ll l,r; cin>>l>>r;
        ll ans = (prefix_sum[r] - prefix_sum[l-1]) *(1-l);
        ans %= mod;

        ans += (B[r] - B[l-1]);
        ans = (ans % mod + mod)% mod;
        cout<< ans << endl;
        
    }

}

signed main() {
  // freopen("IN", "r", stdin);
  // freopen("OUT", "w", stdout);

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
//int _t;cin>>_t;while(_t--)
solve();
 
  return 0;
}