#include<bits/stdc++.h>
using namespace std;
#define endl '\n';

void solve(){
    int n,d=2;
    cin>>n;

    if(n==1){cout<<"1"<<endl;}
    else{
    for (int i = 2; i*i <=n; i++)
    {
        if (i*i==n)
        {
            d++;
        }
        else if(n%i==0){d+=2;}
        
    }cout<<d<<endl;}
    
    
    
}

signed main(){
ios_base::sync_with_stdio(0);
cin.tie(0);cout.tie(0);

int _t;cin>>_t;while(_t--) 
solve();

}