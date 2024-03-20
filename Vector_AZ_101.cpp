#include<bits/stdc++.h>
using namespace std;
#define endl '\n';

void solve(){
    int q;string s;int x;cin>>q;
    vector<int> v;
    for (int  i = 0; i < q; i++)
    {
        cin>>s;
        if (s =="add")
        {cin>>x;v.push_back(x);}
        else if(s =="remove"){
            v.pop_back();}
            else if(s =="print"){
                cin>>x;
                if (x< v.size())
                {cout<<v[x]<<endl;}
                else
                cout<<"0"<<endl;
                
                }
                else if(s=="clear"){
                    v.clear();
                }
        
    }

    



}

signed main(){
ios_base::sync_with_stdio(0);
cin.tie(0);cout.tie(0);

int _t;cin>>_t;while(_t--) 
solve();

}