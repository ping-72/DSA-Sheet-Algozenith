#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define LD long double

const int N = 100010;

int inf = 1e9;
int mod = 1e9 + 7;


void solve(){
    int n,q;cin>>n>>q;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        int k;
        cin>>k;
        v[i] =k;
    }
    sort(v.begin(),v.end());
    while(q--){
      int a,x;
      cin>>a>>x;

      if(a == 1){
        if( lower_bound(v.begin(),v.end(), x) != v.end()){
          int i = lower_bound(v.begin(),v.end(), x) - v.begin();
          cout<<v[i]<<" ";
        }
        else{
          cout<<-1<<" ";
        }
      }
      
      if(a == 2){
        if( upper_bound(v.begin(),v.end(), x) != v.end()){
          int i = upper_bound(v.begin(),v.end(), x) - v.begin();
          cout<<v[i]<<" ";
        }
        else{
          cout<<-1<<" ";
        }
      }
      
      if(a == 3){
        if( lower_bound(v.begin(),v.end(), x) != v.begin()){
          int i = lower_bound(v.begin(),v.end(), x) - v.begin();
          if (v[i] == x){
            while(i != (n-1) && v[i+1] == x){
              i++;
            }
            cout<<i+1<<" ";
          }
          else
            cout<<i<<" ";        
        }
        else{
          if(v[0] == x){
            int i = 0;
            while(i != (n-1) && v[i+1] == x){
              i++;
            }
            cout<<i+1<<" ";
          }
          else{
            cout<<0<<" ";
          }
        }
      }
      
      if(a == 4){
        if( lower_bound(v.begin(),v.end(), x) == v.begin()){
          //int i = lower_bound(v.begin(),v.end(), x) - v.begin();
          cout<<0<<" ";
        }
        else{
          int i = lower_bound(v.begin(),v.end(),x) - v.begin();
          cout<<i<<" ";
        }
      }
        
    }cout<<endl;
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