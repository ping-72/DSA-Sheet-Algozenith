#include<bits/stdc++.h>
using namespace std;
#define endl '\n';


//Soln no 1
/*
void solve(){
    int n;cin>>n;int x;
    set<int> st;
    
    for (int  i = 0; i < n ; i++)
    {
        cin>>x;
        st.insert(x);
    }
    //it=st.begin();it++;
    st.erase(st.begin());
    if(st.empty()){
        cout<<"-1"<<endl;
    }
    else
    cout<<*st.begin()<<endl;
}*/


//  Soln no 2
void solve(){
    int n;int s=1e9+7,ss=1e9+7;
    cin>>n;int x;
    for (int i = 0; i < n; i++)
    {
        cin>>x;
        if(x<s){
            ss=s;
            s=x;
        }else if(x>s && x<ss)ss=x;
    }
    if(ss==1e9+7){cout<<"-1"<<endl;}
    else
    {cout<<ss<<endl;}
}

signed main(){
ios_base::sync_with_stdio(0);
cin.tie(0);cout.tie(0);

int _t;cin>>_t;while(_t--) 
solve();

}