#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define LD long double

const int N = 100010;

int inf = 1e9;
int mod = 1e9 + 7;



void solve(){
    int q,n,i=0;
    if(q==1){
        while((i*i)<n){
            i++;
            cout<<" i= "<<i<<endl;
        }
        if((i*i) == n){cout<<"YES"<<endl;}
        else{cout<<"NO"<<endl;}
    }
    if(q==2){
        while((i*i*i)<n){
           i++;
        }
        if((i*i*i)==n){
                cout<<"YES"<<endl;
            }
        else {cout<<"NO"<<endl;}
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