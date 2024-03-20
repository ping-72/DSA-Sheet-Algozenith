#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define LD long double

const int N = 100010;

int inf = 1e9;
int mod = 1e9 + 7;
int has_connections1 =0,has_connections2 =0;
vector<int> a,b;

void connected1(int (m), int (n)) {
    int x= m-1,y=n-1;
    if(x<0 || y<0){return;}
    for(int i=x; i>=0; i--){
        for(int j=y; j>=0; j--){
            if(a[i] == b[j]){
                has_connections1++;
                connected1(i,j);
                return;
            }
        }
    }
    return;

}
void connected2(int (m), int (n)) {
    int x= m-1,y=n-1;
    if(x<0 || y<0){return;}
    for(int i=y; i>=0; i--){
        for(int j=x; j>=0; j--){
            if(a[i] == b[j]){
                has_connections2++;
                connected2(i,j);
                return;
            }
        }
    }
    return;
}
void solve(){
    int x,y;cin>>x>>y;
    a.assign(x,0);
    b.assign(y,0);
    

    for(int i=0;i<x;i++){
        cin>>a[i];
    }
    for(int i=0;i<y;i++){
        cin>>b[i];
    }

    connected1(x,y);
    connected2(x,y);
    cout<<max(has_connections1,has_connections2)<<endl;

a.clear();
b.clear();
has_connections1=0;
has_connections2=0;
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