#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define LD long double

const int N = 100010;

int inf = 1e9;
int mod = 1e9 + 7;

int n,m;
int vis[1000][1000];
vector<string> arr;
using ii= pair<int,int>;
int dx[]={1,0,-1,0};
int dy[]={0,-1,0,1};

bool check(int x,int y){
  if(x<0 || x>=n || y<0 || y>=m){
    return false;
  }
  else{ return true; }
}


void dfs(ii k){
  int x= k.first,y= k.second;
  vis[x][y] =true;
  for(int i=0;i<4;i++){
    if(check(x+dx[i],y+dy[i]) && arr[x+dx[i]][y+dy[i]] =='.'){
      if(!vis[x+dx[i]][y+dy[i]]){
        dfs({x+dx[i],y+dy[i]});
      }
    }
  }
}


void solve(){
  cin>>n>>m;
  arr.resize(n+1);

  for(int i=0;i<n;i++){
    cin>>arr[i];
  }

  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){ vis[i][j] = 0;}
  }
  int cntOfRooms = 0;
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      if(!vis[i][j]  && arr[i][j] == '.'){
        dfs({i,j});
        cntOfRooms++;
      }
    }
  }
  cout<<cntOfRooms<<endl;

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