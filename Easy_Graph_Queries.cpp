#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define LD long double

const int N = 100010;

int inf = 1e9;
int mod = 1e9 + 7;

vector<vector<int> > g;
vector<int> vis;
vector<int> comp_no;
vector<int> size_connected_components;
int n,m;
int cnt=0;

void dfs(int node){
    vis[node] = 1;
    comp_no[node] =cnt;
    for(auto v:g[node]){
        if(! vis[v]){
            dfs(v);
            size_connected_components[cnt]++;
        }
    }

}

void solve(){
    int q;
    cin>>n>>m>>q;
    g.resize(n+1);
    vis.assign(n+1,0);
    comp_no.resize(n+1);
    size_connected_components.assign(n+1,1);

    for(int i=0; i<m ;i++){
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    for(int i=1; i<=n; i++){
        if(! vis[i]){
            cnt++;
            dfs(i);
        }
    }
    
    
    // for(int i=1; i<=n; i++){
    //     cout<<i<<" "<<comp_no[i]<<endl;
    // }
    // for(int i=1; i<= cnt; i++){
    //     cout<<i<<" -> "<<size_connected_components[i]<<endl;
    // }

while(q--){
    int f;
    cin>>f;
    if(f==1){
        int x;
        cin>>x;
        cout<<size_connected_components[comp_no[x]]<<endl;

    }
    else if(f==2){
        int x,y;
        cin>>x>>y;
        if(comp_no[x]==comp_no[y]){
            cout<<"YES "<<endl;
        }
        else cout<<"NO "<<endl;
    }
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