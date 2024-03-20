#include<bits/stdc++.h>
using namespace std;
#define endl '\n';

void solve(){
    int n;
    cin>>n;
    int A[n],B[n-1],C[n-2];
    long long Sum_A=0,Sum_B=0,Sum_C=0;
    for (int i = 0; i < n; i++)
    {cin>>A[i];Sum_A+=A[i];}
    for (int i = 0; i < (n-1); i++)
    {cin>>B[i];Sum_B+=B[i];}
    for (int i = 0; i < n-2; i++)
    {cin>>C[i];Sum_C+=C[i];}

    cout<<Sum_A-Sum_B<<" "<<Sum_B-Sum_C<<endl;

    //O(1)
    //memory- O(1)
    
}

signed main(){
ios_base::sync_with_stdio(0);
cin.tie(0);cout.tie(0);

int _t;cin>>_t;while(_t--) 
solve();

}