#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define LD long double

const int N = 100010;

int inf = 1e9;
int mod = 1e9 + 7;

int MSB(ll n) {
    if (n < 0) return 63;
    return (int)__lg(n);
}

int RSB(ll n) {
    for(int i = 0; i < 64; i++){
        if(n & (1<<i)){return i;}
    }
}

void solve(){
    ll n;
    cin>>n;
    ll ans6;

    bitset<64> bs(n);
    cout<<bs<<endl; // 1
    
    if(n==0){cout<< -1 <<endl<< -1 <<endl<< 0 <<endl<< -1 <<endl<< (1<<1) <<endl; 
    return;
    }
    
        // 2
        cout<< MSB(n) << endl;// 2
        // 3
        cout<< RSB(n) << endl;// 3

        // 4  
        if( n < 0){ cout<< 0 << endl;}  
        else if(__builtin_popcount(n) == 1){ 
            if(n%2 == 1){
                cout<<0<<endl;
            }
            cout << 1 <<endl;}// 4
        else{ cout<< 0 << endl;}// 4



        // 5 
        cout<< (1ll<< (64 - __builtin_clzll(n-1))) << endl;
        
        // 6 
        if(n <=2){cout<<2<<endl;}
        else{
        if(__builtin_popcount(n) == 1){ cout<< (1<<(MSB(n))) << endl;}
        else{ cout<< (2<<(MSB(n))) << endl;}
        }

        
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