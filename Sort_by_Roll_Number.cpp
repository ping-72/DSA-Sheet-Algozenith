#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define LD long double

const int N = 100010;

int inf = 1e9;
int mod = 1e9 + 7;


void solve(){
    int n;
    cin>>n;
    set<pair<int,string>> st;
    map<int,string> mp;
    for(int i=0;i<n;i++){
        int a;
        string s;
        cin>>s>>a;
        st.insert({a,s});

    }
    for(auto m:st){
        auto a = m.first;
        auto b = m.second;
        cout<<b<<" "<<a<<endl;
    }
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