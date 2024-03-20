#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define LD long double

const int N = 100010;

int inf = 1e9;
int mod = 1e9 + 7;

vector<int> v;
int n,k;

bool check(int differrence)
{
    int k_cnt=0;
    for(int i=1; i<n; i++)
    {
        if((v[i] - v[i-1]) > differrence)
        {
            if(((v[i] - v[i-1]) % differrence)==0)
            {
                k_cnt= k_cnt -1 + (v[i] - v[i-1])/ differrence ;
            }
            else
            {
                k_cnt= k_cnt + (v[i]-v[i-1])/ differrence ;
            }
            if(k_cnt> k)
            {
                return 0;
            }
        }
    }
    if(k_cnt <= k)
    {
        return 1;
    }
    else{return 0;}
}


void solve()
{
    cin>>n>>k;
    v.clear();
    v.resize(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
        // high= max(high, v[i]);
    }
    int low=1,high=v[n-1]- v[0];

    int mid= (high + low)/2;
    int ans =0;

    while(high>= low)
    {

        mid= (high + low)/2;

        if(check(mid)==1){
            ans = mid;
            high= mid - 1;
        }
        else{
            low = mid + 1;
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
int _t;cin>>_t;while(_t--)
solve();
 
  return 0;
}