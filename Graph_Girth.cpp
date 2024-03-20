#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define LD long double

const int N = 100010;

int inf = 1e9;
int mod = 1e9 + 7;

vector<vector<int> >  g;
vector<bool> vis;
int shortes_cycle = inf;

int shortest_cycle_length( vector<vector<int>> adj) {
    int N = adj.size(), INF = N + 1;

    int shortest_cycle = INF; 
    for (int starting_node = 0; starting_node < N; ++starting_node) {
        
        queue<int> Q;
        vector<bool> visited(N, false);
        vector<int> dist(N, INF), parent_of(N, -1);

        Q.push(starting_node);
        visited[starting_node] = true;
        dist[starting_node] = 0;
        
        while (!Q.empty()) {
            int curr = Q.front();
            Q.pop();
            
            for (int next_node : adj[curr]) {
                
                if (!visited[next_node]) {
                    visited[next_node] = true;
                    dist[next_node] = dist[curr] + 1;
                    parent_of[next_node] = curr;
                    
                    Q.push(next_node);
                }
                else if (parent_of[curr] != next_node) {
                    shortest_cycle = min(shortest_cycle, dist[curr] + dist[next_node] + 1);
                }
            }
        }
    }
        return (shortest_cycle == INF ? -1 : shortest_cycle);
}

void solve(){
    int n,m;
    cin>>n>>m;
    vis.assign(n+1,false);
    g.resize(n+1);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    // for(int i=1;i<=n;++i){
    //     queue<int> q;
    //     vector<int> dist(n+1, inf), parent_of(n+1, -1);

    //     q.push(i);
    //     vis[i] = true;
    //     dist[i] = 1;

    //     while( !q.empty()){
    //         int curr = q.front();
    //         q.pop();

    //         for(int next_node:g[curr]){
    //             if(!vis[next_node]){ // if node is not visited
    //                 vis[next_node] = true;
    //                 dist[next_node] = dist[curr]+1;
    //                 parent_of[next_node] = curr;
    //                 q.push(next_node);
    //             }
    //             else if(parent_of[curr] != next_node){// if node is visited and not a current node
    //                 shortes_cycle = min(shortes_cycle, dist[curr]+dist[next_node]+1);

    //             }
    //         }
    //     }
    // }
    shortes_cycle = shortest_cycle_length(g);
    
    cout<<shortes_cycle<<endl;
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