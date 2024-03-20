#include <bits/stdc++.h>
#include <iomanip>
using namespace std;

#define ll long long int
#define LD long double

const int N = 100010;

int inf = 1e9;
int mod = 1e9 + 7;


void solve(){
    int n ;
    cin>>n;
    int arr_A[n],arr_B[n];
    for(int i=0;i<n;i++){
        cin >> arr_A[i];
    }
    for(int i=0;i<n;i++){
        cin>>arr_B[i];
    }
    LD ans = 0;
    cout<< setprecision(8);
    // cout<<k<<endl;
    LD sum_A=0, sum_B=0;
    for(int i=0;i<n;i++){
        sum_A+=arr_A[i];
        sum_B+=arr_B[i];
        if(sum_B){
            long double sum = sum_A/ sum_B;
            if( sum > ans)
                ans = sum;
        }
    }
    cout<< ans<<endl;;
    return;
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