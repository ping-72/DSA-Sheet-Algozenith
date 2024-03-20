#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define LD long double

const int N = 100010;

int inf = 1e9;
int mod = 1e9 + 7;
vector<int> arr;
    int n,k;
    vector<int> sol;


 void rec(int level){
        //base Case
        if(level == n){
            if(sol.size() ==k){
                for(auto r:sol){
                    cout<<r<<" ";
                }cout<<endl;
            }return;
        }
        

          // recursive Case
    //decide for arr[level]......

    //take
    if(sol.size() <k){ // check function - more optimised
            sol.push_back((arr[level]));
            rec(level+1);
            sol.pop_back();}


    //Don't take
    rec(level+1);
    }


void solve(){
    cin>>n>>k;
    arr.resize(n);

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    rec(0);
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