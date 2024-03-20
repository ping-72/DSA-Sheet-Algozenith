#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> arr;
int p;

int check(int mid){
    if( arr[0]>arr[mid]){
        return 1;
    }
    else{return 0;
    }// O(1)
}

void solve(){
    cin>>n;
    arr.resize(n);
    for (int i = 0; i < n  ; i++)
       {cin>>arr[i];}

    //algo....
    int low,high,ans;
    low=0; high=n-1; ans=0;

    while(low<=high){
        // O(log n)
        int mid= (low+high)/2;
        if(check(mid)==0){
            low=mid+1;
        }
        else{
            ans=mid;
            //cout<<"Mid =Current_Ans = "<<mid<<endl;
            high=mid-1;
        }
    }
    cout<<ans<<endl;
    
}

signed main() {

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
int _t;cin>>_t;while(_t--){
//cout<<"Test Case-- "<<_t<<endl;
solve();
//cout<<endl;
}
 
  return 0;
}