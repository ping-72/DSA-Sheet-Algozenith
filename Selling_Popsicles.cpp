#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define LD long double

const int N = 100010;

int inf = 1e9;
int mod = 1e9 + 7;


void solve(){
    int n; 
    cin >> n;
    set<int> Price_st;
    int min_price = inf,max_price = 0;

    int prices[n];

    for (int i = 0; i < n; ++i) {
        cin >> prices[i];
        min_price = min(min_price, prices[i]);
        max_price = max(max_price, prices[i]);
        Price_st.insert(prices[i]);
    }
     int i=0;
     while(abs(min_price - max_price) <= 10){
        min_price-- ;
     }

    cout<<min_price+1<<endl;

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
