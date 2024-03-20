#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007
const ll N = 100001;
const ll BITS = 31;

ll addMod(ll a,ll b){
   a = a+b;
   if(a>=mod)
       a-=mod;
   return a;
}
ll nc2(ll x){
   return ((x*(x-1))/2)%mod;
}
signed main()
{
   ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
   ll powerOfTwo[N];
   powerOfTwo[0] = 1;
   for(ll i=1;i<N;i++){
       powerOfTwo[i] = addMod(powerOfTwo[i-1],powerOfTwo[i-1]);
   }

   ll testCase;
   cin>>testCase;
   while(testCase--){
       ll n;
       cin>>n;
       ll arr[n];
       for(ll i=0;i<n;i++)
           cin>>arr[i];

       ll sumPairXor = 0;
       ll sumSubsetXor = 0;
       ll sumPairAnd = 0;
       ll sumSubsetAnd = 0;

       for(ll i=0;i<BITS;i++){
           ll cnt = 0;
           for(ll j=0;j<n;j++){
               if(arr[j]&(1LL<<i))  
                   cnt++;
           }

           sumPairXor = addMod(sumPairXor , (1LL<<i)*cnt%mod*(n-cnt)%mod);
           if(cnt)
               sumSubsetXor = addMod(sumSubsetXor, (1LL<<i)*powerOfTwo[n-1]%mod);

           sumPairAnd = addMod(sumPairAnd, (1LL<<i)*nc2(cnt)%mod);
           sumSubsetAnd = addMod(sumSubsetAnd, (1LL<<i)*(powerOfTwo[cnt]-1+mod)%mod);

       }
       cout<<sumPairXor<<" "<<sumSubsetXor<<" "<<sumPairAnd<<" "<<sumSubsetAnd<<"\n";
   }

}