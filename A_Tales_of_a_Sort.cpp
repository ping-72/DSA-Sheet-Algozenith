#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define LD long double

const int N = 100010;

int inf = 1e9;
int mod = 1e9 + 7;


void solve(){
    int n;cin >> n;
    int arr[n];
    int  sorted =1;
    int max_no= -1;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        if(i>0 && (arr[i] < arr[i-1]))
        {
            sorted =0;
            max_no = max(max_no,arr[i-1]);            
        }
    }
    if(sorted )
    {
        cout<<0<<endl;
    }
    else
    {cout<<max_no<<endl;}
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