#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define LD long double

const int N = 100010;

int inf = 1e9;
int mod = 1e9 + 7;


void solve(){
    ll n;cin>>n;
    multiset<ll> mt;
    for(ll i=0;i<(1<<n);i++){
      ll x;
      cin>>x;
      mt.insert(x);
    }

    vector<ll> original_array;
    multiset<ll > generated;
    mt.erase(mt.find(0));
    generated.insert(0);

    while(! mt.empty() ){
      ll smallest_no = *mt.begin();
              vector<ll > new_generated_no;
              original_array.push_back(smallest_no);

      for(auto v:generated){
        new_generated_no.push_back(smallest_no+v);
            }  
            for(auto v:new_generated_no){
              generated.insert(v);
              mt.erase(mt.find(v));
            }    
    }
    for(auto v:original_array){
      cout<<v<<" ";
    }cout<<endl;
    
}

signed main() {
  // freopen("IN", "r", stdin);
  // freopen("OUT", "w", stdout);

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
ll _t;cin>>_t;while(_t--)
solve();
 
  return 0;
}