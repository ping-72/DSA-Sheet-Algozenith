#include<bits/stdc++.h>
using namespace std;
#define endl '\n';

void solve(){
    double x,y;
    cin>>x>>y;
    if(x==0 && y==0){
        cout<<"Origin";
    }
    else if(x==0 && y!=0){
        cout<<"Y-axis";
    }
    else if(x!=0 && y==0){
        cout<<"X-axis";
    }
    else if(x>0){
        if(y>0){
            cout<<"Q1";
        }
        else {cout<<"Q4";}
    }
    else
    {
        if (x<0){
            if (y>0)
            {
                cout<<"Q2";
            }
            else{cout<<"Q3";}
            
        }
        
    }
    
}

signed main(){
ios_base::sync_with_stdio(0);
cin.tie(0);cout.tie(0);

//int _t;cin>>_t;while(_t--) 
solve();

}