#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define LD long double

const int N = 100010;

int inf = 1e9;
int mod = 1e9 + 7;

using ii = pair<int, int>;
vector<vector<pair<int, int> > > g;
using state = pair<int, int>;

int dist[1001][1001];
int vis[1001][1001];

void dijkstra(state st){

  priority_quque<pair<int, state>> pq;
  
  dist[st.first][st.second] = 0;
  pq.push(make_pair(0,st));
  
  while(!pq.empty()){
    auto val = pq.top(); pq.pop();
    int cur_dist = val.first;
    int cur_state = val.second;
  }

  }

void solve(){
    int n,m,k;
    cin>>n>>m>>k;  
    g.resize(n+1);

    int st_node = 1, en_node = 0;
    for(int i=0;i<m;i++){
        int a,b,p,d;
        cin>>a>>b>>p>>d;
        g[a].push_back(make_pair(b, make_pair(p,d)));
        g[b].push_back(make_pair(a, make_pair(p,d)));
    } 

    state st = {st_node,0};
    dijkstra(st);
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