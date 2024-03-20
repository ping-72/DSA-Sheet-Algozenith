#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define LD long double

const int N = 100010;

int inf = 1e9;
int mod = 1e9 + 7;


void solve(){
    int n,m,q;
    cin>>n>>m>>q;
    ll arr[n+1][m+1];
    for(int i=0;i<=n;i++){
      for(int j=0;j<=m;j++){
        arr[i][j] = 0;
      }
    }
    for(int i=1;i<=n;i++){
      for(int j=1;j<=m;j++){
        cin>>arr[i][j]; 
      }
    }
    for(int i=1;i<=n;i++){
      for(int j=1;j<=m;j++){
        arr[i][j] = (arr[i-1][j] + arr[i][j] )% mod ;
      }
    }

    while(q--){
      int x1,y1,x2,y2;ll sum=0;
      cin>>x1>>y1>>x2>>y2;
      for(int i=y1;i<=y2;i++){
        sum += (arr[x2][i] - arr[x1-1][i] +mod)% mod;
      }
      while(sum <0){
        sum = (sum+mod) % mod;
      }
      cout<<((sum+mod)%mod)<<endl;

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