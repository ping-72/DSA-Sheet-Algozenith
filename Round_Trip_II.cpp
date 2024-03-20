#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define LD long double

const int N = 100010;

int inf = 1e9;
int mod = 1e9 + 7;

vector<vector<int>> g;
vector<int> visited;
vector<int> colour;

bool is_cycle=false;

void dfs(int node){
    if(is_cycle) return;
    colour[node] = 2;

    for(auto v:g[node]){
        if( colour[v] == 1){
            dfs(v);
        }
        else if( colour[node] == 2){

            // cycle mil gaya
            is_cycle = true;
            return;
        }
        else if( colour[v] == 3){
            // v node cross edge hai
            //this info is of no importance
        }
    }

    colour[node] = 3;

}

void solve(){
    int n,m;
    cin>>n>>m;

    g.resize(n+1);
    visited.assign(n+1,0);
    colour.assign(n+1,1);

    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        }

    if(n >=2){
        for(int i=1; i<n+1; i++){
        if( colour[i] == 1){
            dfs(i);

        }
    }
    }

    if(is_cycle){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }

    
    g.clear();
    visited.clear();
    colour.clear();
    is_cycle = false;
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