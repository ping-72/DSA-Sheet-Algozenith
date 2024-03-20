#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define LD long double

const int N = 100010;

int inf = 1e9;
int mod = 1e9 + 7;

vector<int> v, v1;
vector<pair<int, int>> From_to(n);


void solve(){
    int n;cin>>n;v.resize(n);
    ll final_sum=0;
    for(int i=0;i<n;i++){
        cin>>v[i];
        final_sum += v[i];
    }
   // new vector
   v1.resize(n+2);
   v1[0] = -inf; v1[n+1] = -inf;
   for(int i=1;i<n+1;i++){
    v1[i] = v[i-1];
   }

   // finding min and max pair of values
   for(int i=1;i<n+1;i++){
    int j =i;
    while(v1[j]>=v1[i]){j++;}
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