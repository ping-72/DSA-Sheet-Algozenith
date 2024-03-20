#include<bits/stdc++.h>
using namespace std;
#define endl '\n';

bool prime_check(int n){
    for (int i = 2; i*i <= n; i++)
    {
        if (n%i ==0)
        {
            return 0;
        }
        
    }return 1;
    
}
void solve(){
    int N,k;
    cin>>N;
    if (prime_check(N)==0)
    {
        cout<<"NO"<<endl;
    }else
    {
        cout<<"YES"<<endl;
    }
    
    
    
}

signed main(){
ios_base::sync_with_stdio(0);
cin.tie(0);cout.tie(0);

int _t;cin>>_t;while(_t--) 
solve();

}