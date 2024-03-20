#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define LD long double

const int N = 100010;

int inf = 1e9;
int mod = 1e9 + 7;

ll power(ll x, ll y){
    ll res =1;
    while(y){
        if(y&1)
            res = (res*x)% mod;
        y=y/2;
        x= (x*x)%mod;
    }
    return (res% mod);
}
void solve(){
    ll n,q,k;
    cin>>n>>q>>k;
    ll A[n+1],b[n+1];

    for(int i=0;i<n;i++){A[i] = 0;b[i] = 0;}
    ll temp_k =k;

    ll powerOf_K[n+1]; powerOf_K[0]=1;
    for(int i=1;i<n;i++){
        powerOf_K[i] = powerOf_K[i-1] * k % mod;
    }

     for(int i=1;i<=n;i++){
        cin>>A[i];
        b[i] = (A[i] * ((temp_k) % mod ))%mod;
        temp_k = (k * temp_k) % mod;
        b[i] = (b[i]+ mod)% mod;
     }
     // prefix_Sum B
     for(int i=1;i<=n;i++){
        b[i] += b[i-1];
        b[i] = (b[i] + mod)% mod; 
     }
     // Calaulating K-inverse formula
     while ((q--)){
        ll l,r;
        cin>>l>>r;
        ll ans = b[r] - b[l-1];

        if(ans <0)
            ans+=mod;
// -->> this below line needs revision;
        ans = ans* power(powerOf_K[l] , mod-2)%mod;
        cout<<ans<<endl;
        /* code */
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