#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;

#define ll long long int
#define LD long double

const int N = 100010;

int inf = 1e9;
int mod = 1e9 + 7;

set<int> st;

void solve(){
    int q;
    cin>>q;
    while(q--){
        string s;
        cin>>s;
        if(s == "add"){
            int x;
            cin>>x;
            st.insert(x);
        }
        else if(s == "remove"){
            int x;
            cin>>x;
            if(st.find(x) != st.end()){
                st.erase(x);
            }
        }
        else if (s == "find"){
            int x;
            cin>>x;
            if( !st.empty() && x <= st.size() ){
                cout<<*(st.find_by_order(x))<<endl;
            }
            else{
                cout<<-1<<endl;
            }
        }
        else if (s == "findpos"){
            int x;
            cin>>x;
            if(st.find(x) != st.end()){
                cout<<*(st.order_by_key(x))<<endl;

            }
            else{
                cout<<-1<<endl;
            }
        }
        }







    st.clear();
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