#include<bits/stdc++.h>
using namespace std;
#define endl '\n';

void solve(){
    int q;string s;
    multiset<int> mt;int x;
    cin>>q;
    for (int i = 0; i < q; i++)
    {
        cin>>s;
        if(s=="add"){
            cin>>x;
            mt.insert(x);
        }
        else if(s=="erase"){
            cin>>x;
            if(mt.find(x) != mt.end()){mt.erase(mt.find(x));}
        }
        else if (s=="eraseall"){
            cin>>x;
            if(mt.find(x) != mt.end()){mt.erase(x);}
        }
        else if (s=="find"){
            cin>>x;
            if(!mt.empty()){
            if(mt.find(x)== mt.end()){cout<<"NO"<<endl;}
            else{cout<<"YES"<<endl;}}
            else{cout<<"NO"<<endl;}
            }
        else if (s=="count"){
            cin>>x;
            cout<<int(mt.count(x))<<endl;
        }
        else if (s=="print"){
            for (int i : mt)
            {
                cout<<i<<" ";
            }cout<<endl;
            
        }
        else if(s=="empty"){mt.clear();}


    }
    
}

signed main(){
ios_base::sync_with_stdio(0);
cin.tie(0);cout.tie(0);

int _t;cin>>_t;while(_t--) 
solve();

}