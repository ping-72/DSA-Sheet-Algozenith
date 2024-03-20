#include<bits/stdc++.h>
using namespace std;
#define endl '\n';

void solve(){
    int n,k; long long r=1;
    cin>>n;
    for (int  i = 0; i < n; i++)
    {cin>>k;
    r=(1ll*r*k)%1000000007;
    }cout<<r<<endl;
    
}

signed main(){
ios_base::sync_with_stdio(0);
cin.tie(0);cout.tie(0);

int _t;cin>>_t;while(_t--) 
solve();

}