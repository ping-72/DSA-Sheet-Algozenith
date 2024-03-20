#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define LD long double

const int N = 100010;

int inf = 1e9;
int mod = 1e9 + 7;


void solve(){
    int n,q,m;
    cin>>n>>q;
    vector<ll> v(n);
    // map<ll,int> mp(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    sort(v.begin(),v.end());
    for(int i=1;i<n;i++){
        v[i] += v[i-1];
    }
    
    while(q--){
        cin>>m;
        //lower bound(v.begin(),v.end(),m) gives the iterator to a no that is greater than equal to m
        auto it = upper_bound(v.begin(),v.end(),m);
        
        cout<< it - v.begin()<<endl;
    }

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