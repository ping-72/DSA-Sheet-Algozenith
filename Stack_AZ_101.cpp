#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define LD long double

const int N = 100010;

int inf = 1e9;
int mod = 1e9 + 7;




signed main() {
  // freopen("IN", "r", stdin);
  // freopen("OUT", "w", stdout);

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
int _t;cin>>_t;while(_t--){
    int q;string s;
    cin>>q;
    stack<int> st;
    while(q--){
        cin>>s;
        if(s=="add"){
            int x;
            cin>>x;
            st.push(x);
        }
        else if(s=="remove"){
            if(!st.empty()){
                st.pop();
            }
        }
        else if(s=="print"){
            if(!st.empty()){
                cout<<st.top()<<endl;
            }
            else{
                cout<<"0"<<endl;
            }
    
    }
}
}
 
  return 0;
}