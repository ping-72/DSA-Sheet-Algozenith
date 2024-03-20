#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define LD long double

const int N = 100010;

int inf = 1e9;
int mod = 1e9 + 7;


void solve(){
    int n,q;
    cin>>n>>q;
    ll pref_sum[n],no,ans;
    cin>>no;
    pref_sum[0] = no;
    for (int i = 1; i < n; i++) 
    {
        // O(n)
        cin>>no;
        pref_sum[i] = pref_sum[i-1] + no;
    }
    for(int i = 0; i < q; i++)
    {
        // O(q)
        int l,r;
        cin>>l>>r;
        if(l ==1){
            ans= pref_sum[r-1];
        }
        else{
        ans= (pref_sum[r-1]-pref_sum[l-2]);
        }
        //cout<<"The ans is "<<ans<<endl;
        ans= ans %mod;
        //cout<<"The mod-answer is "<<ans<<endl;
        while(ans<0){
            //O(n)
            ans=(ans + mod)% mod;
        }
        cout<<ans<<endl;
    }
    
    

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