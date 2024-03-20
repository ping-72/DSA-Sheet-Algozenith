#include <bits/stdc++.h>
using namespace std;
typedef long long ll;



bool check(ll n,ll s){
    ll sum_digits = 0;
    ll temp = n;
    while(temp>0){
        sum_digits += temp%10;
        temp /= 10;
    }
    if(n - sum_digits >= s)
        return false;
    return true;
}

signed main()
{
   ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
   ll testcases;
   cin>>testcases;
   while(testcases--){
       ll n,s;
       cin>>n>>s;
       ll low = 1,high = n;
       ll ans = 0;
       while(low<=high)
       {
           ll mid = (low+high)/2;
           ll temp = mid;
           
           if(!check(mid,s))
               high = mid-1;
           else
               ans=mid,low = mid+1;
       }
       cout<<n-ans<<"\n";
   }
}