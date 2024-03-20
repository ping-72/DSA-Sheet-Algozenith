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

//Function Overloading -> OOPs
void printer(vector<int> v){
    cout<<"[ ";
    for(auto x:v){
        cout<<x<<", ";
    }
    cout<<"] "<<endl;
}

void printer(vector<vector<int>> v){
    cout<<"[ ";
    for(auto x:v){
        printer(x);
    }
    cout<<"] "<<endl;
}

void dfs(int node){
    vis[node] = 1;
    for(auto v:g[node]){
    if(!vis[v]){
        dfs(v);
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
    // printer(g);cout<<endl;
    vis.resize(n+1); 
    // printer(vis); cout<<endl;

    // for visiting one node
    dfs(1);
     cout<<"N is -> "<<n<<endl;
     //for visiting all nodes 
     // O( N+M )
     for(int i=1 ;i<n;i++){
        cout<<i<<" "<<endl;
        if(!vis[i]){
            dfs(i);
            }
            printer(vis);
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