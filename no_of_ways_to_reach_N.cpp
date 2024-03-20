#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define LD long double

const int N = 100010;

int inf = 1e9;
int mod = 1e9 + 7;

int n,ans=0;
int level_vis[n+1];

int rec(int level){
    // pruning

    // base case
    if(level == n) { level_vis[level] = 1; return 1;}
    // choice
    // cache
    if(level_vis[level] == 1){
        
    }
    for(int step = 1; step <= 3; step++){
        //check
        if(level+step <= n){
            int ways=rec(level+step);
            level_vis[level] =1;
            cout<<"Level is ->"<< level<<" ways ->"<< ways <<endl;
            ans+= ways;
            cout<<"Ans is ->"<< ans <<endl;
        }
    }
    return ans;
}
void solve(){
    cin>>n;
    cout<<rec(0);
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