#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define LD long double

const int N = 100010;

int inf = 1e9;
int mod = 1e9 + 7;

int no_of_set_bit[32];

int n,x;


void solve(){
     cin>>n>>x;
     vector<int> arr;
     arr.assign(n,0);
    for(int i=0;i<n; i++){
        cin>>arr[i];
        // set_bit_cal(arr[i]);        
    }

    int ans=0;
    for(int i=31; i>=0 ; i--){
        vector<int> elementBitSet;
        for(auto v:arr){
            if(v & (1ll<<i))
            elementBitSet.push_back(v);
        }
        if(elementBitSet.size() >= x){
            ans += (1ll << i);
            arr= elementBitSet;
        }
    }
    cout<<ans<<endl;
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