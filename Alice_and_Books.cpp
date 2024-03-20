#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define LD long double

const int N = 100010;

int inf = 1e9;
int mod = 1e9 + 7;


void solve(){
    ll n,x;
    cin >> n;int b=0,cnt=0;int freq[100001]={};
    // O(n)
    for (int i = 0; i < n; i++)
    {
        cin>>x;
        freq[x]++;
        if(x>b){
            cnt++;
        }
        if(cnt>b){
            b++;
            cnt -=freq[b];
        }
        cout<<b <<" ";

    }
    cout<<endl;
    


}

signed main() {

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
int _t;cin>>_t;while(_t--){
//cout<<"Test Case-- "<<_t<<endl;
solve();
//cout<<endl;
}
 
  return 0;
}