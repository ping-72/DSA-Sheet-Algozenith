#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define LD long double

const int N = 100010;

int inf = 1e9;
int mod = 1e9 + 7;

bool comp(pair<int, int> &a, pair<int, int> &b){
    //if a has to come before b
    return (a.first+a.second > b.first+b.second);
    // never use equal to in the compitior function  
}

void solve(){
    int n;
    cin>>n;
    vector<pair<int,int>> cards[n];

    for(int i=0; i<n; i++){
        cin>>cards[i].first>>cards[i].second;
    }
    sort(cards.begin(),cards.end(),comp);

    for(auto v:cards){
        cout<<v.first<<" "<<v.second<<endl;
    }
}

signed main() {
  // freopen("IN", "r", stdin);
  // freopen("OUT", "w", stdout);

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
// int _t;cin>>_t;while(_t--)
solve();
 
  return 0;
}