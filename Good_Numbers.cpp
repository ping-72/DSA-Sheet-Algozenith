// Enter your code below 
#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define LD long double

const int N = 100010;

int inf = 1e9;
int mod = 1e9 + 7;


void solve(){
   int n,k,q,r_max=0;
   cin>>n>>k>>q;
   ll arr[1000002];
   for (int i = 0; i <= 1000001; i++)arr[i]=0;
   for(int i= 1;i<=n;i++){
       // O(n)
       int l,r;
       cin>>l>>r;
       //r_max= max(r_max,r)
       arr[l]+=1;
       arr[r+1] -=1;
   }

   //Making prefix sum Array
   for (int i = 1; i <= 1000001; i++)
   {
       // O(n)
       arr[i] = arr[i-1]+arr[i];
   }
     for (int i = 1; i <= 1000001; i++)
   {
       // O(n)
       arr[i] = (arr[i]>=k);
   }

    for (int i = 1; i <= 1000001; i++)
   {
       // O(n)
       arr[i] = arr[i-1]+arr[i];
   }
   
   for(int i = 1; i <=q; i++)
   {
       // O( q*(R_L+1))
       int L,R;
       cin>>L>>R;
       cout<<arr[R]-arr[L-1]<<endl;

   }
   

}

signed main() {
 // freopen("IN", "r", stdin);
 // freopen("OUT", "w", stdout);

 ios_base::sync_with_stdio(0);
 cin.tie(0);
 cout.tie(0);

solve();

 return 0;
}