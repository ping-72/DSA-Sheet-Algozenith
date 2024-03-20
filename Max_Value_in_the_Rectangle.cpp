#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define LD long double

const int N = 100010;

int inf = 1e9;
int mod = 1e9 + 7;


void solve(){
    map<int, int> max_value_cnt;
    int n,m,q;
    cin>>n>>m>>q;
    ll arr[n+1][m+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            arr[i][j] = 0;
        }
    }
    while(q--){
        int x1,x2,y1,y2,c;
        cin>>x1>>y1>>x2>>y2>>c;
        for(int i=y1;i<=y2;i++){
            arr[x1][i] += c;
            if(x2 != n){
            arr[x2+1][i] -= c; 
            }
        }
    }
    ll max_no= -inf,temp_max= -inf, min_no = inf;int cnt=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            arr[i][j]= arr[i][j] + arr[i-1][j];
            // cout<<arr[i][j]<<" ";
           //  min_no = min(min_no, arr[i][j]);
            max_no = max(max_no, arr[i][j]);
            
            max_value_cnt[(arr[i][j])] ++;
        }
        cout<<endl;
    }
    cout<<endl;
    cout<<max_no<<" "<<max_value_cnt[max_no]<<endl;
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