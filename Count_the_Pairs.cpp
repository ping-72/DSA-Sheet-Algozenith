#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define LD long double

const int N = 100010;

int inf = 1e9;
int mod = 1e9 + 7;


void solve(){
    int n,x;
    cin>>n>>x;
    int sum=0;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr , arr+n);

    for(int i=0;i<n;i++){
        int a = x - arr[i];
        if(a==0){
            break;
        }
        // cout<<"now a is -> "<<a<<endl;
        auto it=lower_bound(arr+i+1, arr+n, a+1);
        // cout<<"choosing "<<arr[i]<<" we get ->"<<it-(arr+i)<<" where arr+i is - "<<*(arr+i)<<endl;

        sum = sum + (it - arr -i);
    }

    cout<<sum<<endl;


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