#include<bits/stdc++.h>
using namespace std;
#define endl '\n';

void solve(){
    int N,x,Ans=0;
    cin>>N;
    for (int i = 0; i < N; i++)
    {cin>>x;
    Ans ^= x;
    //O(n)
    }
    cout<<Ans<<endl;
    
}

signed main(){
ios_base::sync_with_stdio(0);
cin.tie(0);cout.tie(0);

int _t;cin>>_t;while(_t--) 
solve();

}