#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define LD long double

const int N = 100010;

int inf = 1e9;
int mod = 1e9 + 7;

stack<int> st;
int minEle = 0;

void push(int x) {
    if(st.empty()) {
        st.push(x);
        min Element = x;
        return;
    }
    if( x>= minEle){
        st.push(x);
    }
    else {
        st.push(2*x - minEle);
        minEle = x;
    }
}
void  pop(){
    int y = st.top();
    if(y < minEle){
        minEle = 2*minEle - y;
    }
    st.top();
}
void top_ret(){
    y = st.top();
    if(y < minEle)
        return minEle;
    return y;
}

void solve(){

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

