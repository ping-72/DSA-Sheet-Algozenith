#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define LD long double

const int N = 100010;

int inf = 1e9;
int mod = 1e9 + 7;


void solve(){ // O( nlog(n) )
  int n,k;
  cin>>n>>k;
  ll cnt_max = 0;
  multiset<int> mt;
  for(int i=0;i<n;i++){
    int a;cin>>a;
    mt.insert(a);
  }
  while(k--){
    auto it = mt.rbegin();
    int can = *it;
    mt.erase(mt.find(can)); // O( log n )
    cnt_max += can;
    mt.insert(can/2);
  }

  cout<<cnt_max<<endl;
  
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