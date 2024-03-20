#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define LD long double

const int N = 100010;

int inf = 1e9;
int mod = 1e9 + 7;


void solve(){
    int n;cin >> n;
    vector<ll> prefix_Sum[n];
    vector<int> v[n];
    cin>>v[0];
    prefix_Sum[0]=v[0];
    for(int i=1; i<n; i++){
        cin>>v[i];
        prefix_Sum[i]+= v[i];
    }

    v.
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