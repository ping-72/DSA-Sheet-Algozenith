#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define LD long double

const int N = 100010;

int inf = 1e9;
int mod = 1e9 + 7;

using ii = pair<int , int>;
#define F first
#define S second
int dist[1010][1010];
void bfs(ii st){}

/*
6 6
S.#...
......
####.#
E.##.#
..#..#
#....#
*/

int n,m;
vector<string> arr;


void solve(){
    cin>>n>>m;
    arr.resize(n);
    ii starting_cell,ending_cell;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        for(int j=0;j<m; j++){
            if(arr[i][j] == 'S') starting_cell ={i,j};
            else if(arr[i][j] == 'E') ending_cell={i,j};
        }
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