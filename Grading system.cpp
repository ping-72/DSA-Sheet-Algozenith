#include<bits/stdc++.h>
using namespace std;
#define endl '\n';

void solve(){
    int m,f,c;
    cin>>m>>f>>c;
    if (m==-1||f==-1||m+f<=30)
    {cout<<"F"<<endl;}
    else if (m+f >=80)
    {cout<<"A"<<endl;}
    else if (m+f >=65)
    {cout<<"B"<<endl;}
    else if (m+f >=50)
    {cout<<"C"<<endl;}
    else if (m+f <=50 && c>50)
    {cout<<"C"<<endl;}
    else
    {cout<<"D"<<endl;}
    
    
    
    
}

signed main(){
ios_base::sync_with_stdio(0);
cin.tie(0);cout.tie(0);

int _t;cin>>_t;while(_t--) 
solve();

}