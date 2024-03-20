#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define LD long double

const int N = 100010;

#define F first
#define S second 

int inf = 1e9;
int mod = 1e9 + 7;
int dist[1010][1010];

using state = pair<int, int>;

int n,m;
vector<string> arr;

int dx[] = {0,1,0,-1};
int dy[]= {1,0,-1,0};

bool is_valid(int x, int y) {
    if( x>=0 && x<n && y>=0 && y<m && arr[x][y] != '#'){
    return 1;
    }
    return 0;

}

void bfs(state starting_cell){

    // making all initial dist as inf
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            dist[i][j] = 100;
        }
    }

    dist[starting_cell.F][starting_cell.S] = 0;
    queue<state> q; // this queue will hwlp us to irterate through all the cells in BFS
    q.push(starting_cell);

    while( !q.empty()){
        state node= q.front();
        q.pop();
        int curent_dist = dist[node.F][node.S];
        for(int k=0; k<4; k++){
            state neighbour = { (node.F)+dx[k], (node.S)+dy[k]};
            if(is_valid(neighbour.F, neighbour.S)){

            if(dist[neighbour.F][neighbour.S] > (curent_dist+1)){
                // relaxing condition
                dist[neighbour.F][neighbour.S] = curent_dist+1;
                q.push(neighbour);

            }}
        }
    }

}





void solve(){
    cin>>n>>m;

    arr.resize(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    state st,en;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(arr[i][j] == 'S'){
                st ={i,j};
            }
            else if(arr[i][j] == 'E'){
                en ={i,j};
            }
        }
    }

    // coding the distance of the points
        bfs(st);
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
            cout<< dist[i][j]<<" ";                
            }
            cout<< endl;
        }
        cout<< "Distance of the ending point ->"<<dist[en.F][en.S]<<endl;


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