#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define LD long double

const int N = 100010;

int inf = 1e9;
int mod = 1e9 + 7;


void solve(){
    int n,ans=0;
    cin >> n;
    int a[n],b[n],c[n];
    for(int i=0;i<n;i++){
        cin>> a[i]>>b[i]>>c[i];
    }
    for(int i=0;i<n;i++){
        if(a[i]+b[i]+c[i] >=2){
            ans++;
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
//int _t;cin>>_t;while(_t--)
solve();
 
  return 0;
}