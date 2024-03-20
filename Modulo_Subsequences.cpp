#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define LD long double

const int N = 100010;

int inf = 1e9;
int mod = 1e9 + 7;

int n,m;
vector<int> arr1,arr2,arr;
ll ans;

void rec(int i, ll sum,vector<int> arr){
  ans = max(ans,sum);
  // base - i==n || sum = m-1
  if(i==n || sum == m-1){
    //ans = sum;
    return;
  }

    

  // case 1 - agar arr[i] include ho raha hai
  rec(i+1, max(sum, (sum+1ll*arr[i])%m) );
  

  // case 2 - agar arr[i] include nahi ho raha hai
    rec(i+1, sum+0);

}

void solve(){
    cin>>n>>m;
    arr.resize(n);

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
    
    rec(0,0);

    cout<<ans;

}

signed main() {
  // freopen("IN", "r", stdin);
  // freopen("OUT", "w", stdout);

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
// int _t;cin>>_t;while(_t--)
solve();
 
  return 0;
}