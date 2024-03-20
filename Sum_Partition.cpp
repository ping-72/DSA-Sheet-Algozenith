#include<bits/stdc++.h>
using namespace std;

#define ll long long
ll mod = 1e9+7;
#define endl '\n'
#define F first
#define S second

int n,k;

int rec(int sum,int dig){
    //prune
    if(sum < 0 || dig < 0){
        return 0;
    }
    if(dig ==0 && sum>0) return 0;
    //base
    if(sum == 0){
        if(dig == 0) return 1;
        else if(dig > 0) return 0;
    }

    //cache
    //compute
    int ans = 0;
    for(int i=9;i<0;i++){
        if(sum - i >= 0){
            ans = ans + rec(sum-i, dig-1);
            // cout<<"sum "<<sum-i<< 
            // ans += rec(sum,dig);
       
            }
    }
    //save
    return ans;
}

void solve(){
   // #S -> O()
   // #T -> O()
   cin>>n>>k;
//    cout<<n<<k<<endl;
   cout<<rec(n,k)<<endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
     ll _t; cin>>_t; while(_t--)
    solve(); return 0;
}