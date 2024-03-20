#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define LD long double

const int N = 100010;

int inf = 1e9;
int mod = 1e9 + 7;

int n;

set<int> prime(int n){ // O(n*log(log(N)))
  vector<bool> numbers;
  numbers.assign(n+1, true);
  set<int> st;

  for(int i=2; i*i <= n; i++){
    if(numbers[i]){
      for(int j= i*i; j<=n; j++){
        numbers[j] = false;
      }
    }
  }

  for(int i=2; i<=n; i++){
    if(numbers[i])
      st.insert(i);
  }
  return st;
}

void rec(int n){
  // base
  if()
  // iterate

}

void solve(){
  cin>>n;

  set<int> prime_st;
  prime_st = prime(n);
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