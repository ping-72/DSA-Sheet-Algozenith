#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define LD long double

const int N = 100010;

int inf = 1e9;
int mod = 1e9 + 7;
void solve(){
    int n,m,y;
    multiset<int> mt;
    for (int i = 0; i < n; i++)
    {
        int x;cin>>x;
        mt.insert(x);
    }

    for (int j = 0; j < m; j++)
    {
        cin>>y;
        if(mt.empty()){cout<<"NO"<<endl;}
        //int k=mt.find(y);
        else if(mt.count(y))
        {cout<<"YES"<<endl;
        mt.erase(mt.find(y));}
        else{cout<<"NO"<<endl;}
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