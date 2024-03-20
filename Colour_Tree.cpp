#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define LD long double

const int N = 100010;

int inf = 1e9;
int mod = 1e9 + 7;

vector<vector<int> > g;
int n;
vector<int> visited;
vector<int> colour_of_node;
bool two_teams_possible = true;

void dfs(int node, int colour){
    visited[node] = 1;
    colour_of_node[node] = colour;
    for(auto v:g[node]){
        if( !visited[v] ){ // its a new node
            dfs(v, (3-colour));
        }
        else{// its an older node
        if(colour_of_node[v] == colour){
            two_teams_possible = false;
            return; //the dfs is broke from here and result is achieved
        }
        }
    }
}

void solve(){
    cin>>n;
    g.resize(n+1);
    visited.assign(n+1,0);
    colour_of_node.resize(n+1);
    for(int i=1;i<n;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    
    int cnt=0;
    for(int i=1;i <= n;i++){
        int a= g[i].size();
        cnt = max(cnt, a);
    }
    cout<<cnt+1<<endl;
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