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
vector<int> CGPA_scores;
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
    int k;
    cin>>n>>m>>k;
    
    g.resize(n+1);
    vis.assign(n+1,0);
    CGPA_scores.assign(n+1, 0);
    comp_no.resize(n+1);
    size_connected_components.assign(n+1,1);

    for(int i=1; i <n+1; i++){
        cin>> CGPA_scores[i];
    }

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

int min_CGPA_score = inf;
for(int i=1; i<= n; i++){
    if(size_connected_components[comp_no[i]] >= k){
        min_CGPA_score = min(min,CGPA_scores[i]);
    }
}
cout<<max_CGPA_score<<endl;

g.clear();

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