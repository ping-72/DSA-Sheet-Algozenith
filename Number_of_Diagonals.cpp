#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define LD long double

const int N = 100010;

int inf = 1e9;
int mod = 1e9 + 7;


void solve(){
    int n; int ans;
    cin>>n;
    if(n%2){
        ans= (1ll * n * ((n-3)/2))% mod;
    }
    else{
        ans= (1ll * n/2 * ((n-3)))% mod;
    }
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