#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define LD long double

const int N = 100010;

int inf = 1e9;
int mod = 1e9 + 7;

    multimap<string, int> mp;

void add(){
    string x;
    int y;
    cin>>x>>y;
    mp.insert({x, y});
}
void erase(){
    string x;
    cin>>x;
    if(mp.find(x) != mp.end()){
    mp.erase(mp.find(x));
    }
}
void eraseall(){
    string x;
    cin>>x;
        if(mp.find(x) != mp.end()){
            mp.erase(x);
        }
}
void print(){
    string x;
    cin>>x;
    if(mp.find(x) != mp.end()){
            auto it = mp.find(x);
            cout<<it->second<<endl;
        }
    else
    cout<<0<<endl;
}
void solve(){
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        string s;
        cin>>s;
        if(s =="add"){
            add();
        }
        if(s =="erase"){
            erase();
        }
        if(s =="eraseall")
            eraseall();
        if(s =="print")
            print();
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