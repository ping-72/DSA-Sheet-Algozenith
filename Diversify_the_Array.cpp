#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define LD long double

const int N = 100010;

int inf = 1e9;
int mod = 1e9 + 7;


void solve(){
    int n,k,x,cnt=0;
    map<int,int> mp;
    cin>>n>>k;
    int m;
    priority_queue<ll> pq;
    for (int i = 0; i < n; i++)
    {
        cin>>x;
        mp[x]++;
        if(mp[x] != 1){
            cnt++;
        }
    }
    ll ans= 1ll*(n*(n-1))/2;
    if(cnt >= k)
    {
        cout<<ans<<endl;
    }

    else
    {
        for(auto u:mp)
        {
            pq.push(u.second);
            ans -=(u.second*(u.second-1))/2 ;
            // These no dont contribute to diversification
        }

        while(k!= 0)
        {
            if(pq.empty()){break;}
            m=pq.top();
            if(m>1){
                ans+= m-1;// diversification increased by the highest element that is changed
                pq.pop(); // largest element is removed
                pq.push(m-1);
            }
            k--;
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
int _t;cin>>_t;while(_t--)
solve();
 
  return 0;
}