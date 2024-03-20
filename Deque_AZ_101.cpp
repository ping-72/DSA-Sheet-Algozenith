#include<bits/stdc++.h>
using namespace std;
#define endl '\n';

void solve(){
    int q;cin>>q;string s;int x;
    deque<int> dq;
    for (int i = 0; i < q; i++)
    {
        cin>>s;
        if(s=="insertback"){
            cin>>x;
            if(dq.empty()){dq.push_front(x);}
            dq.push_back(x);
        }
        
        else if(s=="insertfront"){cin>>x;
        dq.push_front(x);}
        
        else if (s=="eraseback")
        {
            if(!dq.empty())
            dq.pop_back();}
        
        else if (s=="erasefront"){
            if(!dq.empty())
            dq.pop_front();}

        else if(s=="printfront"){
            if(dq.empty()){cout<<"0"<<endl;}
            else{x=dq.front();cout<<x<<endl;}}

        else if (s=="printback"){
            if(dq.empty()){cout<<"0"<<endl;}
            else{x=dq.back();cout<<x<<endl;}}

        else if(s=="print"){
            cin>>x;
            if(dq.size()==0 || x>=(dq.size())){cout<<"0"<<endl;}
            else{cout<<dq[x]<<endl;}

            
        }


        


    }
    
}

signed main(){
ios_base::sync_with_stdio(0);
cin.tie(0);cout.tie(0);

int _t;cin>>_t;while(_t--) 
solve();

}