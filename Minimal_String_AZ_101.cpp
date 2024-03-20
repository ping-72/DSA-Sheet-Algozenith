#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define LD long double

const int N = 100010;

int inf = 1e9;
int mod = 1e9 + 7;


void solve(){
    string s,t,u;
    cin>>s;
    multiset<char> mt;
    for(int i=0;i<s.length();i++){// O( log(len(s)) )
        mt.insert(s[i]);
    }
    for(auto k:mt){cout<<k<<" ";}
    cout<<endl;

    while(!s.empty()){
        auto it = s.begin();
        char c1 = *it;
        s.erase(s.begin());
        cout<<"now s is "<<s<<endl;
        if(c1 == *(mt.begin())){// agar pahla letter hai toh U me push karna
            u.push_back(c1);
            mt.erase(mt.begin());
        }
        else{
            t.push_back(c1);
            mt.erase(mt.find(c1));
        }
    }

    while(!t.empty()){
        auto it = t.rbegin();
        char c1 = *it;
        t.pop_back();
        u.push_back(c1);
    }

    cout<<u<<endl;

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
