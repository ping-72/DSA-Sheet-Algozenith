#include<bits/stdc++.h>
using namespace std;
#define endl '\n';

void solve(){
    int J,I;
    cin>>I>>J;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < J; j++)
        {
            if(j%8==(i)){cout<<char('a'+j);}
            else if((j%8+(i))==8&& (i)<4){cout<<char('a'+j);}
            else{cout<<" ";}
        }cout<<endl;
        
    }
    
}

signed main(){
ios_base::sync_with_stdio(0);
cin.tie(0);cout.tie(0);

//int _t;cin>>_t;while(_t--) 
solve();

}