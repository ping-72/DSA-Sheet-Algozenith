#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define LD long double

const int N = 100010;

int inf = 1e9;
int mod = 1e9 + 7;
ll arr_A[n],arr_B[n],arr_C[n];

bool check(int mid,int i){
    if((arr_C[i] + arr_C[mid])>0){
        return 1;
    }
    else return 0;
}

void solve(){
    ll n;int count = 0;
    cin >> n;
    ll arr_A[n],arr_B[n],arr_C[n];
    for(int i = 0; i < n; i++){
        //O(n)
        cin >> arr_A[i];
    }
    for(int i = 0; i < n; i++){
        // O(n)
        cin >> arr_B[i];
        arr_C[i] = arr_A[i] - arr_B[i];

    // Sorting the array as addition is commutatuve
    sort(arr_C, arr_C+n);

    for (int i = 0; i < n; i++)
    {
        if(arr_C[i]<=0){
            if(lower_bound(arr_C,arr_C+n, -arr_C[i] + 1ll) - arr_C != n){

                count+ = n-lower_bound(arr_C.arr_C +n ,-arr_C[i]+1ll) -arr_C;
            }
        }
        else{
            count += n- (i+1);
        }
    }
    
    cout<<count<<endl;
    
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