#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define LD long double

const int N = 100010;

int inf = 1e9;
int mod = 1e9 + 7;

vector<vector<pair<int, int> > > g;
int n,m;
vector<int> dist;
vector<bool> vis;

void ZeroOneBFS(int st){
    for(int i=0;i<=n;i++){
        vis[i] = false;
        dist[i] = 1e9;
    }

    deque<int> dq;
    dist[st] = 0;
    vis[st] = true;
    auto curr = st;
    dq.push_back(st);
    while(!dq.empty()){
        auto nn = dq.front();
        dq.pop_front();
        for(auto v:g[nn]){
            int c = v.second;
            int node = v.first;
            if(dist[node] > dist[nn]+c){
                dist[node] = dist[nn]+c;
                // cout<<"Reached "<<node<<" distance: "<<dist[node]<<endl;
                if(c)   dq.push_back(node);
                else    dq.push_front(node);
            }

        }
    }


}

void solve(){
    cin>>n>>m;
    g.resize(n+1);
    dist.resize(n+1);
    vis.resize(n+1);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back({b,0});        
        g[b].push_back({a,1});        
    }

    ZeroOneBFS(1);
    if(dist[n] != 1e9)
        cout<<dist[n]<<endl;
    else cout<<-1<<endl;
vis.clear();
dist.clear();
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


