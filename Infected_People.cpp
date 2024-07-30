#include<bits/stdc++.h>
using namespace std;

#define ll long long

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

int n, m;

bool isValid(int a, int b, vector<vector<int>>& g){
    if(a<0 || b<0) return false;
    if(a>=n || b>=m)return false;
    if(g[a][b] == 0 )return false;
    return true;
}

void solve(){

   cin>>n>>m;
   
   int INF = 1e8;
   int vis[n][m] = {INF};

   queue<pair<int, int>> q;
   vector<vector<int>> g(n, vector<int> (m,0));

   for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
        cin>>g[i][j];
        vis[i][j] = INF;
        if(g[i][j] == 2){
            vis[i][j] = 0;
            q.push({i, j});
        }
    }
   }

   while(!q.empty()){    
        auto it = q.front();
        int a = it.first;
        int b = it.second;
        int dist = vis[a][b];
        // cout<<"Checking "<<a<<" "<<b<<endl;
        q.pop();
        for(int i=0; i<4;i++){
            int curr_x = a+dx[i];
            int curr_y = b+dy[i];
            if(isValid(curr_x, curr_y, g) && vis[curr_x][curr_y] > dist+1){
                vis[curr_x][curr_y] = dist+1;
                q.push({curr_x, curr_y});
            }
        }
   }


   int ans = 0;
//    for(int i=0; i<n; i++){
//         for(int j=0; j<m; j++){
//             // if(g[i][j]){
//                 cout<<vis[i][j]<<" ";
//             // }
//         }cout<<endl;
//     }

   for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
        if(g[i][j]){
            ans = max(ans, vis[i][j]);
        }
    }
   }
   if(ans == INF){
    cout<<-1<<endl;
    return;
   }
   cout<<ans<<endl;
   
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    // ll _t; cin>>_t; while(_t--)
    solve(); return 0;
}
