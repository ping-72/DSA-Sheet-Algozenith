#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define LD long double

const int N = 100010;

int inf = 1e9;
int mod = 1e9 + 7;



void solve(){
    int n;cin>>n;
    int h[n];
    ll max_rect=0;
    
    for(int i=0;i<n;i++){
        cin>>h[i];
        }
        for( int i=0;i<n;i++){
          int height_current=h[i],cnt_before=0,cnt_after=0;
          
          // before wale ka
          for(int j=0;j<i;j++){
            if(h[j]>=h[i]){cnt_before++;}
            else if(h[j] < h[i]){cnt_before=0;}
          }


          for(int j=i ; (j<n && (h[j]>= height_current));j++){
            if(h[j]>= height_current){cnt_after++;}
          }
          ll current_rect= 1ll* (cnt_before+cnt_after)* h[i];

          max_rect= max(max_rect,current_rect);
        }
        cout<<max_rect<<endl;
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