#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define LD long double

const int N = 100010;

int inf = 1e9;
int mod = 1e9 + 7;

int n,m;
int k;
bool vis[2050][2050];
ll dp[2050][2050];

ll rec(int level, int prev_col, int cnt_k){
    // prune
    if(cnt_k > k){
        return 0;
    }
    // base
    if(level == n || cnt_k == k){
        if(cnt_k == k)
            return 1;
        return 0;
    }
    // cache
    if(vis[level][cnt_k]){
        for(int i=0; i<m; i++){
            return dp[level][cnt_k];
        }
    }
    // compute
    if(cnt_k < k){
        for(int i=0; i<m; i++){
            // if(prev_col == i){
            //     return rec(level+1, i, cnt_k);
            // }
            vis[level][cnt_k] = true;
            return (dp[level][cnt_k] = (rec(level+1,prev_col, cnt_k)||rec(level+1, i, cnt_k+1)));
        }
    }
    // save and return
}

void solve(){
    cin>>n>>m>>k;
    ll ans = 0;

    for(int i=0; i<2050; i++){
        for(int j=0; j<2050; j++){
            vis[i][j] = false;
            dp[i][j] = 0;
        }
    }
    for(int i=0;i<m;i++){
        ans = (ans%mod + 1ll*rec(1,i,0)%mod )%mod;
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