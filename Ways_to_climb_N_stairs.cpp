#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define LD long double

const int N = 100010;

int inf = 1e9;
int mod = 1e9 + 7;

int n;
int ans = 0;
int rec(int level){
    // for(all choices)
    // {
    //     if(check (valid choice))
    //     {
    //         move(choice);
    //     }
    // }

//pruning code

//base Case
if(level n)
{
    return 1;
}
//loop over choices
for(int step=1; step<=3; step++)
{
    if(level+step <= n)
    {
        int ways = rec(level+step);
        ans+= ways; 
    }
}



}

void solve(){
    cin>>n;
    cour<<ans;
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