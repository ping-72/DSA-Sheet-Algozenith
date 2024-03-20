#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define LD long double

const int N = 100010;
ll max=INT_MAX;

int inf = 1e9;
int mod = 1e9 + 7;

int n,k;

bool check(int x){
    //max x tiles time ko lekar kya k ya k se kam bando se kaam karwa sakte hai
    ll last_left=0;
    ll needed=0;

    for (ll i = 0; i < n; i++)
    {
     if (last_left>=arr[i]){
        last_left-=arr[i];
     }
     else if (last_left<arr[i]){
        needed++;
        last_left= x- arr[i];
        }
    if(needed>k){return false;}
    
}
if(needed>k){return false;}
else{return true;}
}

void solve(){
    ll k;
    ll low=max,high=0,ans;
    cin>>n>>k;
    arr.resize(n);
    for (ll i = 0; i < n  ; i++)
    {
        cin>>arr[i];
        high+=arr[i];// O(n)
        low=max(low,arr[i]);// O(n)
    }

    //algo....
    
    low=max; high=sum;
    ; ans=0;
    //default values

    while(low<high){
        // O(log n)
        ll mid= (low+high)/2;
        if(check(mid)==0){
            low=mid+1;
        }
        else{
            ans=mid;
            high=mid-1;
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