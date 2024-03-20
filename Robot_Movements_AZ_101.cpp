#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define LD long double

const int N = 100010;

int inf = 1e9;
int mod = 1e9 + 7;



void solve(){
    int n,r,c,x,y;
    cin>>n>>r>>c>>x>>y;
    string s;
    cin>>s;

    bool vis[r][c];
    

    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            vis[i][j] = false;
        }  
    }
    x--;
    y--;
    
    vis[x][y] = true;
    int curr_row = x;
    int curr_col = y;

    for(int k=0;k<n;k++){
        char i = s[k];
        if(i == 'S'){
            while( vis[curr_row][curr_col]== true){
                // agar agla jaa sakte hai toh 
                if(curr_row+1 < r){
                    curr_row++;
                    cout<<"I reached at "<<curr_row+1<<" "<<curr_col+1<<endl;
                }
                // agar agla nahi jaa sakte hai toh
                else
                    break;
            }
            vis[curr_row][curr_col] =true;
        }

        else if(i == 'N'){
            while( vis[curr_row][curr_col]== true){
                // agar agla jaa sakte hai toh 
                if(curr_row-1 >= 0){
                    curr_row--;
                    cout<<"I reached at "<<curr_row+1<<" "<<curr_col+1<<endl;
                }
                // agar agla nahi jaa sakte hai toh
                else
                    break;
            }
            vis[curr_row][curr_col] =true;
        }

        else if(i == 'E'){
            while( vis[curr_row][curr_col]== true){
                // agar agla jaa sakte hai toh 
                if(curr_col+1 < c){
                    curr_col++;
                    cout<<"I reached at "<<curr_row+1<<" "<<curr_col+1<<endl;
                }
                // agar agla nahi jaa sakte hai toh
                else
                    break;
            }
            vis[curr_row][curr_col] =true;
        }

        else if(i == 'W'){
            while( vis[curr_row][curr_col]== true){
                // agar agla jaa sakte hai toh 
                if(curr_col-1 >= 0){
                    curr_col;
                    cout<<"I reached at "<<curr_row+1<<" "<<curr_col+1<<endl;
                }
                // agar agla nahi jaa sakte hai toh
                else
                    break;
            }
            vis[curr_row][curr_col] =true;
        }

        
    }
    cout<<curr_row+1<<" "<<curr_col+1<<endl;
}

signed main() {
  // freopen("IN", "r", stdin);
  // freopen("OUT", "w", stdout);

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
int _t;cin>>_t;while(_t--)
solve();
 
  return 0;
}