#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define LD long double

const int N = 100010;

int inf = 1e9;
int mod = 1e9 + 7;

multiset<int> mt;
set<int> st;
vector<int> v;

void solve(){
    int n;cin>>n;
    int cnt=0;
    // mt.resize(n);
    for(int i=0;i<n;i++){
        int a;cin>>a;
        st.insert(a);
        mt.insert(a);
    }
    for(auto v:st){
        auto it= mt.count(v);
        if(it > v){
            cnt+= (it -v);
        }
        else if(it < v){
            cnt+= it;
        }

    }
    cout<<cnt<<endl;

    mt.clear();
    st.clear();
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