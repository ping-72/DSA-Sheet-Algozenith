#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define LD long double

const int N = 100010;

int inf = 1e9;
int mod = 1e9 + 7;

int n,m,cnt=0;
vector<vector<int>> g;
vector<int> vis;
vector<int> comp_no_of_the_node;
vector<int> comp_size;

void dfs(int node)
{
    vis[node]=1;
    comp_no_of_the_node[node]=cnt;
    for( auto v:g[node]){
        if(! vis[v]){
            dfs(v);
            comp_size[cnt]++;
        }
    }

}

void solve(){
    cin>>n>>m;
    g.resize(n+1);
    vis.assign(n+1,0);
    comp_no_of_the_node.resize(n+1);
    comp_size.assign(n+1,1);

    for(int i=0; i<m; i++){
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    for(int i=1; i<=n; i++){
        // O( n+m )
        if(! vis[i]){
            cnt++;
            dfs(i);
        }
    }

    if(cnt >=2){
        // O(cnt)
    int sum=comp_size[1];
    ll ans=0;
    for(int i=2; i<= cnt; i++){
        ans += ( 1ll* comp_size[i]* sum) ;
        sum+= comp_size[i];
    }

    for(int i=1 ; i<= cnt; i++)
    {
       // cout<<"no of nodes in "<<i<<" is ->"<<comp_size[i]<<endl;
    }

    cout<<ans<<endl;
    }

    else 
    cout<<"0"<<endl;


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