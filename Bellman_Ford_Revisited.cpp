#include<bits/stdc++.h>
using namespace std;

#define ll long long
ll mod = 1e9+7;
#define endl '\n'
#define F first
#define S second
#define print(a)       		for(auto x : a) cout << x << " "; cout << endl
#define print_pair(a)           for(auto x : a) cout << x.F << " " << x.S << endl

int n,m;
vector<vector<ll>> g;

void bellman_ford(int sr){

}

void solve(){
   // #S -> O()
   // #T -> O()
   cin>>n>>m;
   g.resize(n+1,vector<ll>(n+1,0));
   for(int i=0; i<m; i++){
    int a,b,c;
    cin>>a>>b>>c;
    g[a][b] = -c;
    g[b][a] = -c;
   }

   
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    // ll _t; cin>>_t; while(_t--)
    solve(); return 0;
}