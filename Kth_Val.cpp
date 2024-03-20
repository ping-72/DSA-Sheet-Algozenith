#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define LD long double

const int N = 100010;

int inf = 1e9;
int mod = 1e9 + 7;

vector<int> arr,S,pre;
map<int,int> mp;

void solve(){
    int n,m,q;
    cin>>n>>m>>q;
    arr.resize(n+1);
    pre.resize(n+1);
    //S.resize(m);

    for(int i=1;i<n+1;i++){
        cin>>arr[i];
    }

    for(int i=0;i<m;i++){// O( m* 1)
        int l,r;
        cin>>l>>r;
        pre[l]++;
        pre[r+1]--;
    }
    for(int i=1;i<=n;i++){
        pre[i]= pre[i-1] + pre[i];
    }

    sort(S.begin(),S.end()); // O( log n )
    // for(auto c:S){
    //     cout<<c<<" ";
    // }cout<<endl;

    while(q--){// O(q* 1)
        ll k;
        cin>>k;
        if(k > S.size()){
            cout<<-1<<" ";
        }
        else{
            cout<<S[k-1]<<" ";
        }
    }cout<<endl;
    S.clear();
    arr.clear();

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