#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define LD long double

const int N = 100010;

int inf = 1e9;
int mod = 1e9 + 7;

int n,m;
vector<vector<pair<int,int>>> g;
vector<ll> cnt, d, mnd, mxd;
ll dist[1000100];
vector<bool> vis(n+1,false);

void dij(){
    for(int i=1;i<n+1;i++){
        dist[i] = inf;
    }
    cnt.assign(n+1, 0);
    d.assign(n+1, 0);
    mnd.assign(n+1, 0);
    mxd.assign(n+1, 0);


    priority_queue<;
    dq.push_front(1);
    dist[1] = 0;
    vis[1] = 0;
    while(!dq.empty()){
        auto curr = dq.front();
        dq.pop_front();
        for(auto (q):g[curr]){
            int v = q.first;
            int c = q.second;
            if(vis[v]){
                if(dist[curr]+c < dist[v]){
                    dist[v] = dist[curr]+c;
                    if(c==0) dq.push_front(v);
                    else dq.push_back(v);
                }
            }
            else{
                vis[v] = true;
                dist[v] = dist[curr]+c;
                if(c==0) dq.push_front(v);
                else dq.push_back(v);
            }
        }
    }
}

void solve(){
    cin>>n >>m;
    g.resize(n+1);
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a >>b >>c;
        g[a].push_back({b,c});
        g[b].push_back({a,c});
    }

    dij();
    if(dist[n] != inf){
    cout<<dist[n]<<" ";
    }

    else
    cout<<-1<<endl;
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