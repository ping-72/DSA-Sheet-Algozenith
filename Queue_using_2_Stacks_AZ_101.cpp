#include<bits/stdc++.h>
using namespace std;
#define endl '\n';



/*
Solution 1-----

void solve(){
    queue<int> q;string s;int x;
    int n;cin>>n;
    for (int i = 0; i < n; i++)
    {
        cin>>s;
        if(s=="push"){cin>>x;q.push(x);}
        else if(s=="pop"){x=q.front();cout<<x<<endl;q.pop();}
        else if (s=="front"){x=q.front();cout<<x<<endl;}
    }
    
}*/


//Solution 2
void solve(){
    stack<int> st1;
    stack<int> st2;string s;int k;
    int q;cin>>q;int x;
    for (int i = 0; i < q; i++){
        cin>>s;
        if(s=="push"){cin>>x;st1.push(x);}
        if(s=="front"){k=st1.size();
            for (int j = 0; j < k; j++)
            {
                x=st1.top();st2.push(x);
                st1.pop();
            }cout<<x<<endl;
            for (int j = 0; j < k; j++)
            {
                x=st2.top();st1.push(x);
                st2.pop();
            }
            
        }
        if(s=="pop"){
             for (int j = 0; j < (st1.size()-1); j++)
            {
                x=st1.top();st2.push(x);
                st1.pop();
            }x=st1.top();cout<<x<<endl;st1.pop();
            for (int j = 0; j < st2.size(); j++)
            {
                x=st2.top();st1.push(x);
                st2.pop();
            }
                
        }
    }
    
}

signed main(){
ios_base::sync_with_stdio(0);
cin.tie(0);cout.tie(0);

int _t;cin>>_t;while(_t--) 
solve();

}