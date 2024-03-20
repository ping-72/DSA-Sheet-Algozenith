#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define LD long double

const int N = 100010;

int inf = 1e9;
int mod = 1e9 + 7;


void solve(){
    multiset<ll> mt;
    int n;cin >> n;
    for(int i=0; i<n; i++){
        ll a;cin>>a;
        mt.insert(a);
        }
        ll cost=0;

        if(n==1){cout<<"0"<<endl;}
        else{
        while(mt.size() >1){
            ll current= *mt.begin();
            mt.erase(mt.begin());
            current += (*mt.begin());
            mt.erase(mt.begin());
            cost+=current;
            mt.insert(current);

        }

        cout<<cost<<endl;}
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