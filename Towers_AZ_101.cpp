#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define LD long double

const int N = 100010;

int inf = 1e9;
int mod = 1e9 + 7;

multiset<int> min_set;


void solve(){
    int n;
    cin>>n;
    int cnt=0;
    int b;
    cin>>b;
    min_set.insert(b);
    cnt++;
    for(int i=1;i<n;i++){
      int a;
      cin>>a;
      if(min_set.upper_bound(a) != min_set.end()){
        // a se jyada value set me exist karta hai
              auto it = min_set.upper_bound(a);
              int k= *it;
              min_set.erase(min_set.find(k));
              min_set.insert(a);
      }
      else{
        // a se jyada value set me exist nahi karta hai
              cnt++;
              min_set.insert(a);
      }
    }
    cout<<cnt<<endl;
    min_set.clear();
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