#include<bits/stdc++.h>
using namespace std;
#define endl '\n';

void solve(){
    int n,m,budget;cin>>n>>m;
    vector<int> arr(n);
    for (int  i = 0; i < n; i++)
    {
        cin>>arr[i];}

        // in case you choose the sorting for array----sort(arr,arr+n);
        sort(arr.begin(),arr.end());
        //Prefix sum Array
        for (int i = 1; i < n; i++)
        {
            arr[i]=arr[i]+arr[i-1];}
        

        for (int i = 0; i < m; i++)
        {
           cin>> budget;
           auto x=upper_bound(arr.begin(),arr.end(),budget);
           cout<<(*x)<<" ";
           int ans=x-arr.begin();
           cout<<ans<<endl;
        }
        
         



}

signed main(){
ios_base::sync_with_stdio(0);
cin.tie(0);cout.tie(0);

//int _t;cin>>_t;while(_t--) 
solve();

}