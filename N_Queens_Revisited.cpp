#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define LD long double

const int N = 100010;

int inf = 1e9;
int mod = 1e9 + 7;
int n;
ll ans=0;
vector<int> columns(n);

int check(int row,int column){
    for(int i=0;i<row; i++){
        if(columns[i] != -1){
            if(columns[i] == column || abs(row-i) == abs(columns[i] -column) || (abs(columns[i] -column) + abs(row-i))==3){
                return 0;
            }
        }
    }return 1;
}

void rec(int level){
    if(level == n){
        // cout<<" Queens placed at -> "<<endl;
        for(int i=0;i<level;i++){
            // cout<<"( "<<i<<", "<<columns[i]<<")"<<endl;
        }
        ans++; 
        return; 
        }
    else{
    for(int i=0; i<n; i++){
        if(check(level, i) ==1){
            columns[level] = i;
            // cout<<"Checking placement at ->"<<level<<", "<<columns[level]<<endl;
            rec(level+1);
            columns[level] = -1;
        }}
    }


}

void solve(){
    cin>>n;// cout<<n;
    columns.clear();
    columns.resize(n);
    rec(0);
    // cout<<"Solving"<<endl;
    for(int i=0; i<n; i++){
        columns[i] = -1;
    }

    cout<<ans<<endl;

    //return;
    ans=0;
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