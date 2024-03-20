#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define LD long double

const int N = 100010;

int inf = 1e9;
int mod = 1e9 + 7;

int modu(int n){
    while(n<0)
        n = n + 4;
    n = n % 4;
    return n;
}

int dcol[]= {0, 1, 0, -1};
int drow[]= {-1, 0, 1, 0}; 


void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    int row = 0, col = 0;
    int direction = 0;
    bool is_round = false;
    pair<int,int> curr_pos;
    curr_pos = {row,col};

    for(int i=0; i<n; i++){
        if(s[i] == 'W'){
            row = row + drow[direction];
            col = col + dcol[direction];
            // cout<<"Reached "<<row<<", "<<col<<endl;
        }
        else if(s[i] == 'L'){
            direction = modu(direction - 1);
        }
        else if(s[i] == 'R'){
            direction = modu(direction + 1);
        }
    }

    if(row == 0 && col == 0){
        is_round = true;
        // cout<<"Round is true"<<endl;
        //cout<<"YES"<<endl;
    }

    else {
        for(int j=0; j<3; j++){
            for(int i=0; i<n; i++){
                if(s[i] == 'W'){
                    row = row + drow[direction];
                    col = col + dcol[direction];
                    // cout<<"Reached "<<row<<", "<<col<<endl;
                }
                else if(s[i] == 'L'){
                    direction = modu(direction+1);
                }
                else if(s[i] == 'R'){
                    direction = modu(direction - 1);
                }
            }

            if(row == 0 && col == 0){
                is_round = true;
                // cout<<"Round is true"<<endl;
            }

        } 
    }
    if(is_round){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }



    is_round = false;
    direction = 0;
    curr_pos = {0,0};


}

signed main() {
  // freopen("IN", "r", stdin);
  // freopen("OUT", "w", stdout);

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
int _t;cin>>_t;while(_t--){
    // cout<<"For test "<<_t<<endl;
    solve();
}
 
  return 0;
}