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
int cnt=0;
vector<vector<int> > g; // weighted_graph -> vector<vector<pair<int,int>>> g;
vector<int> vis;
vector<int> comp_no;


void dfs(int node, int comp){
    vis[node] = comp;
    cout<<node<<" " <<cnt<<endl;
    comp_no[node] = cnt;
    for(auto v:g[node]){
    if(!vis[v]){
        dfs(v,comp);
    }
    }
}

void solve(){
    // adjacency list
    cin>>n>>m;
    cout<<"N is -> "<<n<<endl;
    g.resize(n+1); // always resize the graph at the end of the test cases
    vis.assign(n+1, 0);
    for(int i=0;i<m ;i++){
        int a,b; // weighted_graph -> int a,b,c; cin>>a>>b>>c;
        cin>>a>>b;
        g[a].push_back(b); // weighted_graph -> g[a].push_back({b,c});
        g[b].push_back(a); // weighted_graph -> g[b].push_back({a,c});

    }
    vis.resize(n+1); 
    comp_no.resize(n+1);
    

     //for visiting all nodes  // O( N+M )
     int comp_num = 0;
     for(int i=1 ;i<n;i++){
        if(!vis[i]){
            comp_num++;
            cnt++;
            dfs(i,comp_num);
            }
     }

     for(int i=1; i<=n;i++){
        cout<<i<<" -> "<<comp_no[i]<<endl;
     }
   


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