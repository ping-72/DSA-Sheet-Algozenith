#include<bits/stdc++.h>
using namespace std;
#define endl '\n';

void solve(){
    int n,sum=2,streak=2;cin>>n;
    int arr1,arr2,last_diff=0;
    cin>>arr1>>arr2;
    last_diff=arr2-arr1;arr1=arr2;
    for (int i = 0; i < (n-2); i++)
    {
        cin>>arr2;
        if(last_diff==(arr2-arr1)){streak++;}
        else{streak=2;}
        last_diff=arr2-arr1;
        arr1=arr2;
        sum=max(streak,sum);
    }cout<<sum<<endl;
    

}

signed main(){
ios_base::sync_with_stdio(0);
cin.tie(0);cout.tie(0);

int _t;cin>>_t;while(_t--) 
solve();

}