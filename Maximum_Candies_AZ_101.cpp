#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define LD long double

const int N = 100010;

int inf = 1e9;
int mod = 1e9 + 7;

vector<int> arr;
void solve(){
    int n,res,b;
    cin >> n>>b;
    arr.resize(n);
    //O(n)
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    sort(arr.begin(),arr.end());// O(log(n))
    for (int i = 1; i < n; i++) {
    
        arr[i] = arr[i-1]+ arr[i];
    }// o(N)
    auto it = upper_bound(arr.begin(),arr.end(), b);// O(log(n))
    if(*it == b) 
    res = it- arr.begin()+1;

    else
    res= it - arr.begin();
    cout << res << endl;
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