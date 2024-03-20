#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define LD long double

const int N = 100010;

int inf = 1e9;
int mod = 1e9 + 7;

map<string,int> mp;
void solve(){
    int q;
    string s_q,s;int y;
    cin>>q;
    while(q--){
        cin>>s_q;
        if(s_q=="add"){
            cin>>s>>y;
            if(mp.find(s)==mp.end()){
            mp.insert({s,y});}
            else{
              mp[s]=y;
            }
        }
        if(s_q=="erase"){
            cin>>s;
            if(mp.find(s)!=mp.end()){
            mp.erase(s);}
        }
        if(s_q=="print"){
          cin>>s;
          if(mp.find(s)!=mp.end()){
            cout<<mp[s]<<endl;
          }
          else{
            cout<<"0"<<endl;
          }
        }

    }
    mp.clear();
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