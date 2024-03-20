#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define LD long double

const int N = 100010;

int inf = 1e9;


ll binpow(ll a, ll x,ll p){
  // (a^x) % p
  ll n,ans=1;
  while(x){
    if(x%2){
      ans = ((ans %p) *(a%p)) %p;
    }
    a= ((a % p) *(a%p))% p;
    x=x/2;
  }
  return ans;
}


void solve(){
    ll a,b,c,res,ans,mod;
    cin>>a>>b>>c>>mod;
    // ((a^b)^c) % p =?

    if(b==0 && c!=0){
      cout<<1<<endl;
    }
    else if(a==0 || a%mod==0){
      cout<<0<<endl;
    }
    else{
      res = binpow(b,c,mod-1);
      ans = binpow(a,res, mod);
      cout<<ans<<endl;

    }

    

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

