#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define LD long double

const int N = 100010;

int inf = 1e9;
int mod = 1e9 + 7;

bool isDivisible(int x, int y){

}

void solve(){
    int n,m;
    cin>>n>>m;
    ll totalballs = m+n;
    int noofCollision = 0;
    //multiset<pair<int,int>> Xaxis,Yaxis;
    map<int,int> mp;
    
    for(int i=0;i<n;i++){
            int a,b;
            cin>>a>>b;
            int k= a*b;
            mp[k]++;
    }
    for(int i=0;i<m;i++){
            int a,b;
            cin>>a>>b;
            int k= a*b;
            if( mp.count(k) && mp[k]>0){
                noofCollision++;
                //cout<<"Count of "<<k<<" is " <<mp[k]<<endl;
                mp[k]--;
                if(mp.count(k) == 0){
                mp.erase(k);}
            }
    }
    
    cout<<noofCollision<<endl;
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