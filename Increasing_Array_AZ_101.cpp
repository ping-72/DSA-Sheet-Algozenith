#include<bits/stdc++.h>
using namespace std;
#define endl '\n';

void solve(){
    int n,maxi=0;
    unsigned long long sum=0;
    cin>>n;
    int arr;
    for (int i = 0; i < n; i++)
    {cin>>arr;
    maxi=max(maxi,arr);
    if (maxi>arr)
    {
        sum+=(maxi-arr);
    }}
    cout<<sum<<endl;
    //O(n)
    //memory- O(1)
}

signed main(){
ios_base::sync_with_stdio(0);
cin.tie(0);cout.tie(0);

int _t;cin>>_t;while(_t--) 
solve();

}