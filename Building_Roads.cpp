#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define LD long double

const int N = 100010;

int inf = 1e9;
int mod = 1e9 + 7;

int n,m;
vector<vector<int>> g;
vector<int> visited;
int cnt_components = 0;

void dfs(int node){
    visited[node] = 1;
    for(auto v: g[node]){
        if( !visited[v] ){
            dfs(v);
        }
    }
}


void solve(){
    cin>>n>>m;
    g.resize(n+1);
    visited.assign(n+1,0);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    for(int i=1;i <= n;i++){
        if(!visited[i]){
            dfs(i); cnt_components++;
        }
    }
    cout<< cnt_components-1 <<endl;
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