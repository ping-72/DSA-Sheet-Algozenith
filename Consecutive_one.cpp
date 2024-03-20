#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define LD long double

const int N = 100010;

int inf = 1e9;
int mod = 1e9 + 7;

int n,k;
vector<int> binary_arr, no_of_zeros;

bool check(int x){
    int cnt=0,i;
    for(i=0;i<x;i++){
        if(binary_arr[i] ==0)
            cnt+=1;
    }
    if(cnt <= k)
        return true;
    for(int i=x;i<n;i++){
        if(binary_arr[i-x] ==0)
            cnt--;
        if(binary_arr[i] == 0)
            cnt++;
        if(cnt<=k)
            return true;
    }
    return false;
}

void solve(){
    cin>>n>>k;
    int cnt_zeros =0;
    binary_arr.resize(n);
    for(int i=0;i<n;i++){
        cin>>binary_arr[i];
    }
    // Hamesa starting condition yahi hone wala hai 2 pointers me...
    int head = -1, tail = 0;
    int ans =0;
    // maintaining property
    // Iss Question me cnt of Zeros maintain karna hai

    while(tail<n){
        // Process this start index
        while(head+1 < n && (cnt_zeros + (binary_arr[head+1]==0?1:0)) <= k){
            head++;
            if(binary_arr[head] == 0)
            cnt_zeros++;
        }
        // [tail se head] tak ka answer nikala ans Usko process kar diya
        ans = max(ans,(head - tail + 1 ));
        // move tailby one step
        if(head<tail){
            tail++;
            head = tail-1;
        }
        else{
            if(binary_arr[tail] == 0) cnt_zeros--;
            tail++;
        }
    }
    cout<<ans<<endl;
    
    binary_arr.clear();no_of_zeros.clear();
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