#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define LD long double

const int N = 100010;

int inf = 1e9;
int mod = 1e9 + 7;


void solve(){
    int n;cin>>n;
    int arr[n];int ans;
    cin>>arr[0]>>arr[1];
    ans =__gcd(arr[0],arr[1]);

    for(int i=2; i<n; i++){
        // O(n)
        cin>>arr[i];
        if(ans >= 2){
            ans = __gcd(ans,arr[i]);
        }
    }
    if(ans >=2){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
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