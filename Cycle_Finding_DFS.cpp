#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define LD long double

const int N = 100010;

int inf = 1e9;
int mod = 1e9 + 7;
// input -->
//   #nodes #edges 
//  edges from X to y
//  X Y 
// 8 7
//  1 2
//  2 3
//  3 4
//  4 1
//  1 3
//  7 6
//  6 8

int n,m;
vector<vector<int> > g; // weighted_graph -> vector<vector<pair<int,int>>> g;
vector<int> vis;
bool cycle_present = true;
vector<int> colour;


void dfs(int node, int col){ // colours are- 1 and 2
    vis[node] = 1;
    colour[node] =col;
    for(auto v:g[node]){
    if(!vis[v]){ // new node
        dfs(v, 3^col);
    }
    else{
        // new node
          if(colour[v] ==colour[node]){
            is_bipartite= false;
          }
          }
    }
}

void solve(){

    cin>>n>>m;
    g.resize(n+1); 
    vis.assign(n+1, 0);
    for(int i=0;i<m ;i++){
        int a,b; 
        cin>>a>>b;
        g[a].push_back(b); 
        g[b].push_back(a); 

    }
    vis.resize(n+1);
    colour.resize(n+1); 
    
     for(int i=1 ;i<n;i++){
        if(!vis[i]){
            dfs(i,1);
            }
     }
    cout<<is_bipartite<<endl;

    g.clear();
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