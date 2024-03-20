#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define LD long double

const int N = 100010;

int inf = 1e9;
int mod = 1e9 + 7;

int n,k;
int low=0;
ll high=0,ans;
vector<int> arr;

bool check(ll ans){
    //O(n)

    ll min_nxt =arr[0] +ans;
    int cnt_student = 1;
    for(int i=1; i<n; i++){
        // cout<<arr[i]<<" ";
        // student placed at ith place
        if(arr[i] >= min_nxt){
            //student is placed at ith place
            cnt_student++;
            // cout<<"count students = "<<cnt_student<<endl;
            min_nxt = arr[i]+ ans;
        }}
        // cout<<endl;
        if(cnt_student >= k){
            return 1;
        }
        else{return 0;}
     
}

    void solve(){
    cin>>n>>k;

    arr.clear();
    arr.resize(n);
    for (int i = 0; i < n  ; i++)
    {
        cin>>arr[i];
    }

    sort(arr.begin(),arr.end()); // O( log n)

    high= arr[n-1] - arr[0];
    low = 1; 

    while(low<=high){
        // O(log n)
        ll mid= (low+high)/2;
        
        if(check(mid)==1){
            ans=mid;
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    cout<<ans<<endl;
    
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