#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define LD long double

#define F first
#define S second

const int N = 100010;

int inf = 1e9;
int mod = 1e9 + 7;

int dx[]={1,0,0,-1};
int dy[]={0,1,-1,0};

bool grid[1000][1000];
queue<pair<int,int>>   A_Player_occ,Monster_occ;
pair<int,int> par[1000][1000];
int distA[1000][1000];
int dist_of_Mon[1000][1000];
int n,m;



void solve(){
    cin>>n>>m;
    
    memset(grid, false,sizeof(grid));

    memset(dist_of_Mon, -1, sizeof(dist_of_Mon));
    memset(distA, -1, sizeof(distA));

    // input
    for(int i=0;i<n; i++){
      string s; cin>>s;

      for(int j=0;j<m; j++){
        grid[i][j] = true;
        if(s[j] == '#') grid[i][j] =false;
        else if(s[j] == 'M'){
          dist_of_Mon[i][j] =0;
          Monster_occ.push({i,j});
        }
        else if(s[j] == 'A'){
          if(i == 0 || i == n-1 || j ==0 || j== m-1){
               cout<<"YES"<<endl<<"0"<<endl;
            return;
          }
          A_Player_occ.push({i,j});
          distA[i][j] = 0;
          par[i][j] ={-1,-1};

        }
      }
    }

    while( !Monster_occ.empty() ){
      auto it= Monster_occ.front();
      Monster_occ.pop();
      int x= it.first, y= it.second;

      for(int i=0; i<4; i++){
        int x1= x +dx[i], y1= y+dy[i];
        if(x1<0 || y1<0 || x1>=n || y1>= m){
          continue;
        }
        if(grid[x1][y1] && dist_of_Mon[x1][y1] == -1){
          dist_of_Mon[x1][y1] = dist_of_Mon[x][y] +1;
          Monster_occ.push({x1,y1});
        }
      } 
    }

    while( !A_Player_occ.empty()){
      auto it = A_Player_occ.front();
      A_Player_occ.pop();
      int x = it.first; int y = it.second;

      for(int i=0; i<4;i++){
        int xx= x+dx[i], yy = y + dy[i];
        if(xx < 0 || xx >= n || yy < 0 || yy >= m)continue;
        if(grid[xx][yy] && distA[xx][yy] == -1){
          distA[xx][yy] = distA[x][y] + 1;
          A_Player_occ.push({xx , yy});
          par[xx][yy] = {x,y};
        }
      }
    }

    int finx = -1, finy = -1, findist = 1e9;

    for(int i=0; i<n; i++){
      if(grid[i][0] && distA[i][0] >=0 && (distA[i][0] < dist_of_Mon[i][0] || dist_of_Mon[i][0] == -1)){
        finx = i;finy = 0;
        findist = min( findist , distA[i][0] );
      }
      if(grid[i][m-1] && distA[i][m-1] >= 0 && (distA[i][m-1] < dist_of_Mon[i][m-1] || dist_of_Mon[i][m-1] == -1 )){
        finx = i; finy = m-1;
        findist = min(findist, distA[i][m-1]);
      }
    }

    for(int i=0;i<m; i++){
      if(grid[0][i] && distA[0][i] >= 0 && (distA[0][i] < dist_of_Mon[0][i] || dist_of_Mon[0][i] == -1)){
        finx = 0; finy = i;
        findist = min(findist, distA[0][i]);
      }
      if(grid[n-1][i] && distA[n-1][i] >= 0 && (distA[n-1][i] < dist_of_Mon[n-1][i] || dist_of_Mon[n-1][i] == -1)){
        finx = n-1; finy = i;
        findist = min( findist, distA[n-1][i]);
      }
    }

    if(finx == -1)
    cout<<"NO"<<endl;
    else{cout<<"YES"<<endl;
    cout<<findist<<endl;
    }


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