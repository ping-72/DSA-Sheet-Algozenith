#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define LD long double

const int N = 100010;

int inf = 1e9;
int mod = 1e9 + 7;

bool comp(pair<int,int> &a, pair<int,int> &b){
    //Condition true for a before b
    return a.first + a.second > b.first+b.second ;
    //Never write equals to when comparing a function
}
void solve(){
    int n;
    cin>>n;
    vector<pair<int,int>> cards(n);
    for (int i = 0; i < n; i++)
    {
        cin>>cards[i].first >>cards[i].second;
    }
    sort(cards.begin(),cards.end(),comp);
    for(auto r:cards){
        cout<<r.first <<" "<< r.second<< endl;
    }

}

signed main() {
  // freopen("IN", "r", stdin);
  // freopen("OUT", "w", stdout);

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
//int _t;cin>>_t;while(_t--)
solve();
 
  return 0;
}