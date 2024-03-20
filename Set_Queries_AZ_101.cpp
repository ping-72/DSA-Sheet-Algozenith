#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define LD long double

const int N = 100010;

int inf = 1e9;
int mod = 1e9 + 7;
void solve(){
    int q;
    cin>>q;int t; ll x;
    set<int> st;

    while(q--){
      int i,x;
      cin>>i>>x;

      if(!(i-1)){
        st.insert(x);
      }
      else
      {
        if(x < *st.begin() || x > *st.end())
        {
          cout<<x<<" "<<endl;
        }
        else {
          auto it = st.lower_bound(x);
          if( *it != x )
          {
            cout<<x<<" "<<endl;
          }
          else 
          {
            while( it != st.end() || *it == x)
            {
              x++;
              it= st.lower_bound(x);
            }
            if( it == st.end()){
              cout<<x+1<<" "<<endl;
            }
            else{
              cout<<x<<" "<<endl;
            }
          }
        }
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