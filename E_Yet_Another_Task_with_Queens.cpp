#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define LD long double

const int N = 100010;

int inf = 1e9;
int mod = 1e9 + 7;

int n;
int queen[20];// queen[i] -> where is my queen in nth row;

check(int rows, int cols){
    for(int i = 0; i <rows; i++){
        int previous_row = i;
        int previous_column = queen[i];

        if(previous_column == cols || (abs(previous_column - cols))==(abs(previous_row-rows))){
            return 0;
        }
    }
    return 1;
}

int rec(int level)
{// rec -> no of ways to populate the queen 
    // level -> row in which queen is being placed

    //pruninng

    // basecase
    if(level == n){
        return 1;
    }

    //compute
    int ans=0;
    for(int col=0;col<n;col++){
        if(check(level,col)){
            queen[level] = col;
           ans += rec(level+1);
            queen[level] = -1;
        }
    }

    // return
    return ans;

}
void solve(){
    cin>>n;
    memset(queen,-1,sizeof(queen));
    cout<<rec(0)<<endl;

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