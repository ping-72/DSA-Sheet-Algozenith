#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define LD long double
#define F first 
#define S second

using ii= pair<int, int>;
const int N = 100010;

int inf = 1e9;
int mod = 1e9 + 7;

vector<string> arr;
int n,m;
int dist[1010][1010];
/*
6 6
S.#...
......
####.#
E.##.#
..#..#
#....#
*/

void bfs(ii st){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            dist[i][j] =1e9;
        }
    }

bool inside(int x, int y){
    if(x<0 || x>=n ||)
}

    dist[stating_point.F][starting_point.S] =0;
    queue<ii> q;
    q.push(st);

    while(! q.empty()){
        ii current= q.front();
        q.pop();
        int current_distance= dist[current.F][current.S];
    }

}


void solve(){
    cin>>n>>m;
    arr.resize(n);
    ii starting_cell,ending_cell;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        for(int j=0;j<m;j++){
            if(arr[i][j]=='S')
            starting_cell= {i,j};
            else if(arr[i][j]=='E')
            ending_cell= {i,j};
        }
    }

    bfs(st);
    cout<<dist[ending_cell.F][ending_cell.S]<<endl;

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