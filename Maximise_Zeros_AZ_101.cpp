#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define LD long double

const int N = 100010;

int inf = 1e9;
int mod = 1e9 + 7;


map<double,int > mp_divided;

void solve(){
    int n;
    cin >> n;int max_cnt=0;int always_plus_in_any_case=0;
    ll a[n],b[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < n; i++){
        cin >> b[i];
        LD d;
        if(a[i] != 0){
            LD b_;
            b_=b[i];
            LD a_;
            a_=a[i];
        d= (-b_ )/ a_;
        mp_divided[d]++;
        max_cnt= max(max_cnt,mp_divided[d]);
    }
    if(a[i] == 0 && b[i] == 0){
        always_plus_in_any_case ++;
    }
    }
    cout<<max_cnt+always_plus_in_any_case<<endl;
    
    mp_divided.clear();
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