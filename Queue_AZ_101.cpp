#include<bits/stdc++.h>
using namespace std;
#define endl '\n';



void solve(){
    int q;string s;
    queue <int> v;
    cin>>q;
    for (int i = 0; i < q; i++)
    {
        cin>>s;
        if (s =="add")
        {int x;cin>>x;
        v.push(x);}

        else if(s== "remove"){
            if(int (v.size())!=0){
            v.pop();
            }}
        else if(s=="print"){
            if(int(v.size())==0){
                cout<<"0"<<endl;
                }
            else{cout<<v.front()<<endl;}
            
        }

        

    }
    

}

signed main(){
ios_base::sync_with_stdio(0);
cin.tie(0);cout.tie(0);

int _t;cin>>_t;while(_t--) 
solve();

}