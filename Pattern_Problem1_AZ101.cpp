#include<bits/stdc++.h>
using namespace std;
#define endl '\n';

void solve(){
    int m,n;
    cin>>m>>n;

    
    for (int j = 0; j < 3*n+1; j++)
        {cout<<"*";}
        cout<<endl;
    for (int k = 0; k < m; k++)
    {

    for (int i = 0; i < 2; i++)
    {
    cout<<"*";
    for(int i=0;i<n;i++){
        cout<<"..*";
    }cout<<endl;}
    for (int j = 0; j < 3*n+1; j++)
        {
            cout<<"*";}cout<<endl;
            }//cout<<endl;
}

signed main(){
ios_base::sync_with_stdio(0);
cin.tie(0);cout.tie(0);

int _t;cin>>_t;while(_t--) 
solve();

}