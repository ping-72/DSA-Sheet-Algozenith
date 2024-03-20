#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define LD long double

const int N = 100010;

int inf = 1e9;
int mod = 1e9 + 7;

vector<vector<pair<int,int>>> g;
int n,m;
vector<bool> vis;
vector<ll> dist;
ll max_node_time = 0;
ll max_time = 0;


void dij(int st){

    dist[st] = 0;
    //vis[st] = true;
    priority_queue<pair<ll,int>> pq;
    pq.push({-0, st});

    while(!pq.empty()) {
      auto curr = pq.top(); pq.pop();
      if(vis[curr.second]) continue;
      
      vis[curr.second] = true;
      for(auto v:g[curr.second]){
        int neigh = v.first;
        int wt = v.second;
        if(dist[neigh] > dist[curr.second] + wt){
                  dist[neigh] = dist[curr.second] + wt;
                  pq.push({-dist[neigh], neigh});
        }
      }

    }
}

void solve(){
    cin>>n>>m;
    g.resize(n+1);
    vis.assign(n+1, false);
    dist.assign(n+1, 1e17);
    for(int i=0;i<m;i++){
        int u,v,d;
        cin>>u>>v>>d;
        g[u].push_back({v,d});
        g[v].push_back({u,d});
    }
    int a;
    cin>>a;
    dij(a);

    // for(int i=1;i<=n;i++){
    //   cout<<dist[i]<<" ";
    // }cout<<endl;

    for(int i=1;i<=n;i++){ // o(n)
    ll time = dist[i]*10;
      max_time = max(max_time, time);
    }
    

    for(int i=1;i<=n;i++){// O(2* #edge)
      //cout<<"Node no "<<i<<endl;
      for(auto v:g[i]){
        int thread_len = v.second;
        int edge = v.first;
        if(min(dist[i], dist[edge])+ thread_len*1ll > max(dist[i], dist[edge])){
          ll time_add = (thread_len*1ll - abs(dist[edge] - dist[i]))*5 + 10*max(dist[edge], dist[i]);
          max_time = max(max_time, time_add);
        }
      }
    }
    cout<<max_time;
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
