#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define LD long double

const int N = 100010;

int inf = 1e9;
int mod = 1e9 + 7;

vector<vector<pair<int,int>>> g;
vector<bool> visited;
vector<ll> min_dist;
// queue<int> q;
int n,m;

class comp{
    public:
    bool operator()(
        pair<int,int> p1, pair<int,int> p2){
            return p1.second > p2.second;
        }
};

void dijkstra(){
    min_dist[1] = 0;
    priority_queue<pair<int,int> , vector<pair<int,int>>, comp> pq;
    pq.push({1,0});

    while(!pq.empty()){
        auto val = pq.top();
        int node = val.first;
        int curWeight = val.second;

        pq.pop();
        if(visited[node]) continue;
        visited[node] = true;

        for(auto neighnode : g[node]){
            int neigh = neighnode.first;
            int weight = neighnode.second;
            if(min_dist[neigh] > min_dist[node] + weight){
                min_dist[neigh] = min_dist[node] + weight;
                pq.push( make_pair(neigh, min_dist[neigh]));
            }
        }
    }
}

void solve(){
    cin>>n>>m;
    g.assign(n+1, vector<pair<int,int> >());
    visited.assign(n+1, false);
    min_dist.assign(n+1, 1e9);

    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        g[a].push_back({b,c});
    }
    
    dijkstra();
    for(int i=1; i<=n; i++) cout<< min_dist[i]<<" ";

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