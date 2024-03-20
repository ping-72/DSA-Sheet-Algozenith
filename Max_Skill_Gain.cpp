#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define LD long double

const int N = 100010;

int inf = 1e9;
int mod = 1e9 + 7;

int n;
int time[1001];
int skill[1001];
int x,k;

bool check(int level){
    ll time_taken = 0;
    ll item_taken = 0;
    for(int i=0; i<level; i++){
        if(taken[i]){
            time_taken = += t[i];
            item_taken ++;
        }
    }
    time_taken += t[level];
    item_taken++;
}

int rec(int level){
    // level -> current item in [0 ... n-1]
    // pruning 
    // basecase
    if(level == n){
        return 0;
    }
    // compute
    int ans = rec(level +1); // 1st choice : not taken
    if(check(level)){
        //place the change
        taken[level] = 1;
        //move
        ans= max(ans, shill[level] + rec(level+1));
        // revert
        taken[level] = 0;

    }
    // return
}
void solve(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>time[i]>>skill[i];
    }
    cin>>x>>k;
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