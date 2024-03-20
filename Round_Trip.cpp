#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define LD long double

const int N = 100010;

int inf = 1e9;
int mod = 1e9 + 7;
int  n,m;
vector<vector<int>> g;
vector<int> vis;
vector<int> colour;
bool is_cycle = false;

// Find the cyckle which has back edges 
// and count the no ->> that giuves the no of cycles in the graph

void dfs(int node, int parent){

    // marking of visiting the node
    vis[node] = 1;
    colour[node] = 2;
    for(auto v:g[node]){
        if( !vis[v] ){
            dfs(v, node);            
        }
        else if(v != parent && colour[v] ==2){

            // cycle mil gaya.....
            is_cycle = true;

        }else if(colour[v] == 3){

            // this info id of no use.....
        }
    }
    colour[node] = 3;
}


void solve(){
    cin >>n >>m ;
    g.resize(n+1);
    vis.assign(n+1,0);
    colour.assign(n+1,1);

    for(int i=0; i<m; i++){
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    for(int i=1; i<=n; i++){
        if(! vis[i]){
            dfs(i,0);
        }
    }

    if(is_cycle){
        cout<<"YES"<<endl;
    }
    else {cout<<"NO"<<endl;}


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