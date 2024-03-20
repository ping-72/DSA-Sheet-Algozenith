#include<bits/stdc++.h>
using namespace std;

#define ll long long
ll mod = 1e9+7;
#define endl '\n'
#define F first
#define S second

int n,m;
vector<vector<ll>> dist;

void flloyd_warshal(){
    for(int i=1;i<=n;i++){
        dist[i][i] = 0;
    }

    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
}

void solve(){
   cin>>n>>m;
   int q;
   cin>>q;
   dist.resize(n+1, vector<ll>(n+1, 1e18));

   for(int i=0;i<m;i++){
        ll a,b,c;
        cin>>a>>b>>c;
        if(dist[a][b] > c){
            dist[a][b] = c;
            dist[b][a] = c;
        }
   }

   flloyd_warshal();

   
   while(q--){
        int a,b;
        cin>>a>>b;
        if(dist[a][b] == 1e18){
            cout<<-1<<endl;
        }
        else 
        cout<<dist[a][b]<<endl;
   }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    // ll _t; cin>>_t; while(_t--)
    solve();
    return 0;
}
