#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define LD long double

const int N = 100010;

int inf = 1e9;
int mod = 1e9 + 7;


bool is_4sum_possible(vector<int> arr, int n, int target){
  map< ll, ll> pos;

  // b is fixed for making each partition

  for(int b =n-3; b>=1 ; b--){

    for(int a=b-1; a>=0; a--){
      if( pos[target - arr[a] -arr[b]] == 1){
        return 1;
      }
    }
    int c=b;
    for(int d= c+1; d<n; d++){
      if((arr[c]+arr[d]) <= inf){
      pos[arr[c] + arr[d]] =1;
      }
    }
    }
    return 0;

}

void solve(){
  int n,x;
    cin>>n>>x;
    vector<int> arr;
    
    arr.clear();
    arr.resize(n);
    for(int i=0; i<n; i++){
      int q;
      cin>>q;
      arr[i] = q;
    }

    if( n < 4){
      cout<<"NO"<<endl;
    }
    else{

    auto answer = is_4sum_possible( arr, n, x);

    if(  is_4sum_possible( arr, n, x) ){
      cout<<"YES"<<endl;
    }
    else{
      cout<<"NO"<<endl;
    }}
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