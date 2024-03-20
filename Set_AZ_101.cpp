#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define LD long double

const int N = 100010;

int inf = 1e9;
int mod = 1e9 + 7;

set<int> st;
void add(int x){
    st.insert(x);
}
void erase(int x){
    if(st.find(x) != st.end()){
        st.erase(st.find(x));
    }
}
void find(int x){
    if(st.find(x) != st.end()){
        cout<<"YES"<<endl;
    }
    else cout<<"NO"<<endl;
}

void solve(){
    int q;
    cin>>q;
    while(q--){
    string s;int x;
    cin >> s;
    if(s == "add"){
        cin>>x;
        st.insert(x);
    }
    else if(s == "erase"){
        cin>>x;
        erase(x);
    }
    else if(s == "find"){
        cin>>x;
        find(x);
    }
    else if(s=="print"){
        
        for(auto r:st){
            cout<<r<<" ";
        }
        cout<<endl;
    }
    else if(s=="empty"){
        st.clear();
    }}
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